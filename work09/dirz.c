#include "dirz.h"

int main(){
  //Directory Size:
  printf("\nTotal Directory Size: %s\n", convertbytes(dirsize(".")));
    
    
  //Directories:
  printf("Directories:\n");
  printf("%s\n", listdirz(".."));
    
  //Regular Files:
  printf("Regular Files: \n");
  printf("%s\n", listfiles(".."));

  //Tree:
  size = 0;
  char ans[256] = {0};
  printf("Tree: \n");
  tree("../..");
  printf("Total Directory Size: %s\n", convertbytes(size));

  if(!d){
    printf("%s\n", strerror(errno));
    return 0;
  }
}

long dirsize( char * dir ){
  struct dirent* entry;
  d = opendir(dir);
  while (entry = readdir(d))
    if (entry->d_type == DT_REG){
      stat(entry->d_name,&tmp);
      size += tmp.st_size;
    }
  closedir(d);
  return size;
}

char * listdirz( char * dir ){
  struct dirent* entry;
  memset(ans, 0, 255);
  d = opendir(dir);
  while (entry = readdir(d))
    if (entry->d_type == DT_DIR)
      sprintf(ans,"%s\t%s\n", ans, entry->d_name);
  closedir(d);
  return ans;
}

char * listfiles( char * dir ){
  struct dirent* entry;
  memset(ans, 0, 255);
  d = opendir(dir);
  while (entry = readdir(d))
    if (entry->d_type == DT_REG)
      sprintf(ans,"%s\t%s\n", ans, entry->d_name);
  closedir(d);
  return ans;
}

char * convertbytes( long bytes ){
  while( bytes ){
    if( bytes >= 1000000000){
      sprintf(ans,"%ld MB ",bytes/1000000000);
      bytes %= 1000000000;
    }
    else if( bytes >= 1000000){
      sprintf(ans,"%ld MB ",bytes/1000000);
      bytes %= 1000000;
    }
    else if( bytes >= 1000){
      sprintf(ans,"%s%ld KB ", ans, bytes/1000);
      bytes %= 1000;
    }
    else{
      sprintf(ans,"%s%ld B", ans, bytes);
      bytes = 0;
    }
    //printf("%s\n", ans);
  }
  return ans;
}

void tree( char * dir ){
  DIR * d;
  struct dirent* entry;
  d = opendir(dir);
  char temp[256];
  
  while (entry = readdir(d)) {
    if(!strcmp(entry->d_name,"..") || !strcmp(entry->d_name,"."))
      continue;
    if(entry->d_type == DT_REG){
      tabbing(counter);
      printf("%s\n", entry->d_name);
      stat(entry->d_name,&tmp);
      size += tmp.st_size;
    }
    else if (entry->d_type == DT_DIR){
      tabbing(counter);
      printf("%s/\n", entry->d_name);
      counter++;
      sprintf(temp, "%s/%s", dir, entry->d_name);
      tree(temp);
    }
  }
  closedir(d);
  counter--;
}

char * tabbing( int i ){
  while(i--)
    printf("\t");
}
