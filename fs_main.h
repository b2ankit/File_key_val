#ifndef FS_MYLIB_H
#define FS_MYLIB_H

#include<stdio.h>


FILE * mul_fs_fopen(char * fsPath,char * fsMode);
int mul_fs_fseek(FILE *filePointer,int offset,int whence);
int mul_fs_fwrite(FILE *filePointer, char *fsDataToWrite);
int mul_fs_fread(FILE *filePointer,char * dataToread,int sizeofdata);
int mul_fs_read_key(FILE *filePointer,char *dataToread,int sizeofdata,char *sKey,char *line_holder);
void mul_fs_fclose(FILE *filePointer);

#endif