#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

DIR *d;
struct stat tmp;
char ans[256] = {0};
long size = 0;
int counter = 0;

long dirsize( char * );
char * listdirz( char * );
char * listfiles( char * );
char * convertbytes( long );
void tree( char * );
char * tabbing( int );
