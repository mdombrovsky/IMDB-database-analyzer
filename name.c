#include "name.h"
#include "common.h"

struct name_basics *get_name(char* string){

    FILE *fptr;

    struct name_basics *name_basics_array=NULL;

    char *buffer;
    char *file_name;
    char suffix [20] = "/name.basics.tsv";

    char *data=NULL;

    char *column=NULL;
    
    int preformer_count=0;

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
        fprintf( stderr, "Error opening file %s%s\n", string,"/name.basics.tsv");
        return NULL;
    }

    buffer=malloc(257);

    /*Get amount of preformers*/
    while(fgets(buffer ,256 ,fptr)!=NULL){
        get_column(buffer,&column,4);
        if((strstr(column,"actor")!=NULL)||(strstr(column,"actress")!=NULL)){
            preformer_count++;
        }
        free(column);
    }

    /*Allocates array*/
    name_basics_array=malloc(sizeof(struct name_basics)*preformer_count);

    rewind(fptr);
    preformer_count=0;

    /*Populates array*/
    while(fgets(buffer ,256 ,fptr)!=NULL){
        get_column(buffer,&column,4);
        if((strstr(column,"actor")!=NULL)||(strstr(column,"actress")!=NULL)){
           
            get_column(buffer,&data,0);
            (name_basics_array+preformer_count)->nconst=data;

            get_column(buffer,&data,1);
            (name_basics_array+preformer_count)->primaryName=data;

            preformer_count++;

        }
        free(column);
    }


    fclose(fptr);
    fptr=NULL;


    return name_basics_array;

}

