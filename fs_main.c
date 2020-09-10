#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fs_main.h"




FILE * mul_fs_fopen(char * fsPath,char * fsMode){
    FILE *filePointer = NULL;
    filePointer=fopen(fsPath,fsMode);

    if(!filePointer){
        printf("No file found\n");
        printf("FilePointer is failed to open | Creating new file\n");
        filePointer=fopen(fsPath,"w+");
        if(!filePointer){
            printf("File created :Failed\n");
            return NULL;
        }
    }

    return(filePointer);
}

int mul_fs_fseek(FILE *filePointer,int offset,int whence){
    if(filePointer){
        fseek(filePointer,offset,whence);
        return 1;
    }
    return -1;
}


int mul_fs_fwrite(FILE *filePointer, char *fsDataToWrite){
    if(filePointer)
    {
        // fputs(fsDataToWrite,filePointer);
        fprintf(filePointer,fsDataToWrite);
        return 1;
    } 
        
    return -1;
}

int mul_fs_fread(FILE *filePointer,char * dataToread,int sizeofdata){
    if(filePointer)
     {
        while(fgets(dataToread,sizeofdata,filePointer)!=NULL);
        return 1;        
    } 
    return -1;
        
}

int mul_fs_read_key(FILE *filePointer,char *dataToread,int sizeofdata,char *sKey,char *line_holder){
    int flags = 0;
    if(filePointer)
    {
        while(fgets(dataToread,sizeofdata,filePointer)!=NULL){
            if(strstr(dataToread,sKey)!=NULL){
                strncpy(line_holder,dataToread,strlen(dataToread));
                flags++;
            }
        }
        if(flags)
            return 1;
    }
    printf("No match found\n");
    return -1;



}

void mul_fs_fclose(FILE *filePointer){
     if(filePointer)
        fclose(filePointer);
}

