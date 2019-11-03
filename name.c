
#include "name.h"
#include "common.h"

struct name_basics *get_name(char* string){

    FILE *fptr;

    struct name_basics *nameStruct=NULL;

    char *buffer=malloc(257);
    char *fileName;
    char suffix [20] = "/name.basics.tsv";

    char *column=NULL;
    
    int actorCount=0;

    fileName=malloc(strlen(string)+strlen(suffix)+1);

    strcpy(fileName,string);
    strcat(fileName,suffix);


    fptr=fopen(fileName,"r");


    while(fgets(buffer ,256 ,fptr)!=NULL){
        get_column(buffer,&column,4);
        /*printf("%s\n",column);*/
        if((strstr(buffer,"actor")!=NULL)||(strstr(buffer,"actress")!=NULL)){
            actorCount++;
        }
        free(column);
    }



    printf("Lines: %d\n",actorCount);
    fclose(fptr);

    if(fileName){
        free(fileName);
        fileName=NULL;
    }

    return nameStruct;

}

