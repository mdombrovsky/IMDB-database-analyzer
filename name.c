/**
 * Name: Michael Dombrovsky
 * Student Number: 1040277
 * Email: mdombrov@uoguelph.ca
 **/ 
#include "name.h"
#include "binary.h"
#include "common.h"

struct name_basics_meta *get_name(char* string){

    FILE *fptr;

    struct name_basics *name_basics_array=NULL;
    struct name_basics_meta *name_basics_meta;

    char *buffer;
    char *file_name;
    char suffix [20] = "/name.basics.tsv";

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
    while(fgets(buffer, buffer_size ,fptr)!=NULL){
        get_column(buffer,&column,4);
        if((strstr(column,"actor")!=NULL)||(strstr(column,"actress")!=NULL)){
            preformer_count++;
        }
        free(column);
    }

    /*printf("Lines: %d\n\n",preformer_count);*/

    /*Allocates array*/
    name_basics_array=malloc(sizeof(struct name_basics)*preformer_count);

    rewind(fptr);
    preformer_count=0;

    /*Populates array*/
    while(fgets(buffer ,buffer_size ,fptr)!=NULL){
        get_column(buffer,&column,4);
        if((strstr(column,"actor")!=NULL)||(strstr(column,"actress")!=NULL)){
           
            get_column(buffer,&data,0);
            reverse(data);
            (name_basics_array+preformer_count)->nconst=data;

            get_column(buffer,&data,1);
            (name_basics_array+preformer_count)->primaryName=data;

            preformer_count++;
        }
        free(column);
    }


    fclose(fptr);
    fptr=NULL;


    name_basics_meta=malloc(sizeof(name_basics_meta));
    name_basics_meta->array=name_basics_array;
    name_basics_meta->count=preformer_count;
    name_basics_meta->nconst_index=0;
    name_basics_meta->name_index=0;

    return name_basics_meta;
}

void build_nb_nconst_index(struct name_basics_meta *name_basics_meta){
   int i;
    /*Loop over all elements in array*/
    for(i=0;i<(name_basics_meta->count);i++){
        add_node(&(name_basics_meta->nconst_index),((name_basics_meta->array)+i)->nconst,((name_basics_meta->array)+i));
    }
}

void build_nb_name_index(struct name_basics_meta *name_basics_meta){
    int i;
    /*Loop over all elements in array*/
    for(i=0;i<(name_basics_meta->count);i++){
        add_node(&(name_basics_meta->name_index),((name_basics_meta->array)+i)->primaryName,((name_basics_meta->array)+i));
    }
}

struct name_basics *find_nb_name(struct name_basics_meta *name_basics_meta,char* search_term){
    return (find_node((name_basics_meta->name_index),search_term)->data);
}

struct name_basics *find_nb_nconst(struct name_basics_meta *name_basics_meta,char* search_term){
    return (find_node((name_basics_meta->nconst_index),search_term)->data);
}



