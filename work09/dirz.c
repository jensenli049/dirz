#include "dirz.h"

int main(){
  DIR *d = opendir("../..");
  struct dirent* entry;
    
    
    //Directory Size:
    int size = 0;
    if(!d){
        printf("%s\n", strerror(errno));
        return 0;
    }
    
    while (entry = readdir(d)){
        if (entry->d_type == DT_REG){
            size += entry->d_reclen;
        }
    }
    closedir(d);
    printf("Total Directory Size: %d\n", size);
    
    
    //Directories:
    d = opendir("../..");
    printf("Directories: \n");
    while (entry = readdir(d)){
        if (entry->d_type == DT_DIR){
            printf("\t%s\n", entry->d_name);
        }
    }
    closedir(d);
    
    
    //Regular Files:
    d = opendir("../..");
    printf("Regular Files: \n");
    while (entry = readdir(d)){
        if (entry->d_type == DT_REG){
            printf("\t%s\n", entry->d_name);
        }
    }
    closedir(d);
      

}
