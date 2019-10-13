#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

//defining counters for files and directories
static int num_dirs, num_regular;

// checks if path works 
bool is_dir(const char* path) {
	
	struct stat buf;
	
	if(stat(path, &buf) == 0){
		int checkDir = S_ISDIR(buf.st_mode);
		if(checkDir!=0){
			return true;
		} else {
			return false;
		}
	} else {
		printf("Stat didn't return 0. Problem with path");
		return false;
	}
}

/* 
 * I needed this because the multiple recursion means there's no way to
 * order them so that the definitions all precede the cause.
 */
void process_path(const char*);

// counts directories and has a recursive call to 'process_path'
void process_directory(const char* path) {
	DIR* dirStream;
	struct dirent* content;
	char* dname;	
	
	dirStream = opendir(path);

	if(dirStream!=NULL){
		chdir(path);

		while((content=readdir(dirStream))){
			dname = content->d_name;
			if(strcmp(dname,".")!=0 && strcmp(dname,"..")!=0){
				process_path(dname); // recursive call 
			}
		}

		num_dirs++;
		chdir("..");	
	}

	closedir(dirStream);
}

void process_file(const char* path) {
   //Update the number of regular files.
	num_regular++;
}

// recurses 
void process_path(const char* path) {
  if (is_dir(path)) {
    process_directory(path);
  } else {
    process_file(path);
  }
}

// main 
int main (int argc, char *argv[]) {
  // Ensure an argument was provided.
  if (argc != 2) {
    printf ("Usage: %s <path>\n", argv[0]);
    printf ("       where <path> is the file or root of the tree you want to summarize.\n");
    return 1;
  }

  num_dirs = 0;
  num_regular = 0;

  process_path(argv[1]);

  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_regular);

  return 0;
}
