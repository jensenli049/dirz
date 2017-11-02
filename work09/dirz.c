#include "dirz.h"

int main(){
  DIR *d = opendir("~/Desktop");
  struct dirent* entry;
  printf("Listing all files...\n");
  while (d){
    entry = readdir(d);
    printf("%s\n", entry->d_name);
  }
  printf("%s\n", strerror(errno));
  closedir(d);
  
}
