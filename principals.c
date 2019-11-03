#include "principals.h"

struct title_principals *get_principals(char* string){

    FILE *fptr;

    struct title_principals *title_principals_array=NULL;

    char *buffer;
    char *file_name;
    char suffix [30] = "/title.principals.tsv";

    char *data=NULL;

    char *column=NULL;
    
    int preformer_count=0;
    int buffer_size=1000;

    file_name=malloc(strlen(string)+strlen(suffix)+1);

    strcpy(file_name,string);
    strcat(file_name,suffix);


    fptr=fopen(file_name,"r");

    /*Free file_name*/
    if(file_name){
        free(file_name);
        file_name=NULL;
    }
    

    /*If unable to open*/
    if(fptr==NULL){
        fprintf( stderr, "Error opening file %s%s\n", string,suffix);
        return NULL;
    }

    buffer=malloc(buffer_size+1);

    /*Get amount of preformers*/
    while(fgets(buffer ,buffer_size ,fptr)!=NULL){
        get_column(buffer,&column,3);
        if((strstr(column,"actor")!=NULL)||(strstr(column,"actress")!=NULL)){
            preformer_count++;
        }
        free(column);
    }

    /*Allocates array*/
    title_principals_array=malloc(sizeof(struct title_principals)*preformer_count);

    rewind(fptr);

    printf("Lines: %d\n\n",preformer_count);
    preformer_count=0;

    /*Populates array*/
    while(fgets(buffer , buffer_size ,fptr)!=NULL){
        get_column(buffer,&column,3);
        if((strstr(column,"actor")!=NULL)||(strstr(column,"actress")!=NULL)){
           
            get_column(buffer,&data,0);
            (title_principals_array+preformer_count)->tconst=data;

            get_column(buffer,&data,2);
            (title_principals_array+preformer_count)->nconst=data;

            get_column(buffer,&data,5);
            (title_principals_array+preformer_count)->characters=data;

            preformer_count++;
        }
        free(column);
    }


    fclose(fptr);
    fptr=NULL;


    return title_principals_array;
}

