/**
 * Name: Michael Dombrovsky
 * Student Number: 1040277
 * Email: mdombrov@uoguelph.ca
 **/ 
#include "principals.h"
#include "common.h"
#include <string.h>

struct title_principals_meta *get_principals(char* string){

    FILE *fptr;

    struct title_principals *title_principals_array=NULL;
    struct title_principals_meta *title_principals_meta=NULL;

    char *buffer;
    char *file_name;
    char suffix [30] = "/title.principals.tsv";

    char *data=NULL;

    char *column=NULL;
    
    int preformer_count=0;
    int buffer_size=1024;

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

    /*printf("Lines: %d\n\n",preformer_count);*/
    preformer_count=0;

    /*Populates array*/
    while(fgets(buffer , buffer_size ,fptr)!=NULL){
        get_column(buffer,&column,3);
        if((strstr(column,"actor")!=NULL)||(strstr(column,"actress")!=NULL)){
           
            get_column(buffer,&data,0);
            reverse(data);
            (title_principals_array+preformer_count)->tconst=data;

            get_column(buffer,&data,2);
            reverse(data);
            (title_principals_array+preformer_count)->nconst=data;

            get_column(buffer,&data,5);
            /*if(*(data+strlen(data)-1)=='\n'){
                (*(data+strlen(data)-1))='\0';
            }*/
            (title_principals_array+preformer_count)->characters=data;

            preformer_count++;
        }
        free(column);
    }


    fclose(fptr);
    fptr=NULL;


    title_principals_meta=malloc(sizeof(title_principals_meta));
    title_principals_meta->array=title_principals_array;
    title_principals_meta->count=preformer_count;
    title_principals_meta->tconst_index=0;
    title_principals_meta->nconst_index=0;

    return title_principals_meta;
}


void build_tp_tconst_index(struct title_principals_meta *title_principals_meta){
    int i;
    /*Loop over all elements in array*/
    for(i=0;i<(title_principals_meta->count);i++){
        add_node(&(title_principals_meta->tconst_index),((title_principals_meta->array)+i)->tconst,((title_principals_meta->array)+i));
    }
}


struct node *find_tp_tconst(struct title_principals_meta *title_principals_meta,char* search_term){
    return (find_node((title_principals_meta->tconst_index),search_term));
}

void build_tp_nconst_index(struct title_principals_meta *title_principals_meta){
    int i;
    /*Loop over all elements in array*/
    for(i=0;i<(title_principals_meta->count);i++){
        add_node(&(title_principals_meta->nconst_index),((title_principals_meta->array)+i)->nconst,((title_principals_meta->array)+i));
    }
}


struct node *find_tp_nconst(struct title_principals_meta *title_principals_meta,char* search_term){
    return (find_node((title_principals_meta->nconst_index),search_term));
}



