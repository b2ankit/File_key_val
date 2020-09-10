#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fs_main.h"

#define FILEPATH "./test.txt"

void file_clean(){
    FILE *file_pointer = NULL;
    file_pointer = mul_fs_fopen(FILEPATH,"w");
    if(file_pointer){
        mul_fs_fclose(file_pointer);
    }
}


void file_write(char *key, char *value){

    FILE *file_pointer = NULL;
    file_pointer = mul_fs_fopen(FILEPATH,"a+");
    if(file_pointer){
        mul_fs_fwrite(file_pointer,key);
        mul_fs_fwrite(file_pointer,"=");
        mul_fs_fwrite(file_pointer,value);
        mul_fs_fwrite(file_pointer,"\n");
        mul_fs_fclose(file_pointer);
    }

}


int file_read(char *key,char *valuetoWrite){
    int retVal = 0;
    int keyLen = strlen(key)+1;
    int vaLen;
    int sizetoRead = 264;
    char *readData = NULL;
    char *modified_key = NULL;
    char *line_holder = NULL;
    int modified_keyLen = strlen(key)+1;

    FILE *file_pointer = NULL;
    file_pointer = mul_fs_fopen(FILEPATH,"r+");


    readData = (char *)calloc(sizetoRead,sizeof(char));
    if(!readData){
        printf("Memory allocation failed\n");
        return -1;
    }

    modified_key = (char *)calloc(modified_keyLen,sizeof(char));
    if(!modified_key){
        printf("Memory allocation for modified_key : Failed\n");
        return -1;
    }
    sprintf(modified_key,"%s%s",key,"=");

    printf("Modified key value : %s\n",modified_key);


    line_holder = (char *)calloc(128,sizeof(char));
    if(!line_holder){
        printf("memory allocation for line_holder : Failed\n");
        return -1;
    }

    if(file_pointer){
        retVal = mul_fs_read_key(file_pointer,readData,sizetoRead,modified_key,line_holder);
        if(retVal!=1)
            return -1;
        vaLen = strlen(line_holder)-(keyLen+1);
        memcpy(valuetoWrite,line_holder+keyLen,vaLen);
        printf("valuekey : %s\n",valuetoWrite);
        return 1;

    }

}


int main(){

    char *key = "Ankit";
    char *value = NULL;
    /*CLeaning the file before writing*/
    file_clean();

    /*Writing in file*/
    file_write("Hello","world");
    file_write("Ankit","Jioka naam");
    file_write("office","jioooo");
    file_write("address","chapra");
    file_write("Ankit1","Kumar");

    /*Reading in file*/
    

    value = (char *)calloc(32,sizeof(char));
    if(!value){
        printf("memory allocation for value : Failed\n");
        return -2;
    }
    if(file_read(key,value)==1){
        printf("key : %s || value : %s\n",key,value);
    }
    return 0;
}