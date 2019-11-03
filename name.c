
#include "name.h"

struct name_basics *get_name(char* string){

    FILE *fptr;

    char *buffer=malloc(257);
    char *fileName;
    char suffix [20] = "/name.basics.tsv";


    fileName=malloc(strlen(string)+strlen(suffix)+1);

    strcpy(fileName,string);
    strcat(fileName,suffix);

    printf("here3\n");
    fflush(stdout);
    fptr=fopen(fileName,"r");

  
    while(fgets(buffer ,256 ,fptr)!=NULL){

        printf("%s\n",buffer);
    }


    fclose(fptr);

    if(fileName){
        free(fileName);
        fileName=NULL;
    }

    return NULL;

}