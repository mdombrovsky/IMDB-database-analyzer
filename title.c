/**
 * Name: Michael Dombrovsky
 * Student Number: 1040277
 * Email: mdombrov@uoguelph.ca
 **/ 
#include "title.h"
#include "binary.h"
#include "common.h"

struct title_basics_meta *get_title(char* string){

    FILE *fptr;

    struct title_basics *title_basics_array=NULL;
    struct title_basics_meta *title_basics_meta=NULL;

    char *buffer;
    char *file_name;
    char suffix [20] = "/title.basics.tsv";

    char *data=NULL;

    char *column=NULL;
    
    int movie_count=0;

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

    /*Get amount of movies*/
    while(fgets(buffer ,buffer_size ,fptr)!=NULL){
        get_column(buffer,&column,1);
        if(strstr(column,"movie")!=NULL){
            free(column);

            get_column(buffer,&column,4);
            if(strstr(column,"1")==NULL){
                movie_count++;
            }
        }
        free(column);
    }

    /*printf("Lines: %d\n",movie_count);*/

    /*Allocates array*/
    title_basics_array=malloc(sizeof(struct title_basics)*movie_count);

    rewind(fptr);
    movie_count=0;

    /*Populates array*/
    while(fgets(buffer ,buffer_size ,fptr)!=NULL){
        get_column(buffer,&column,1);
        if(strstr(column,"movie")!=NULL){
            free(column);

            get_column(buffer,&column,4);
            if(strstr(column,"1")==NULL){

                get_column(buffer,&data,0);
                reverse(data);
                (title_basics_array+movie_count)->tconst=data;

                get_column(buffer,&data,2);
                (title_basics_array+movie_count)->primaryTitle=data;

                movie_count++;
            }
        }
        free(column);
    }


    fclose(fptr);
    fptr=NULL;

    title_basics_meta=malloc(sizeof(title_basics_meta));
    title_basics_meta->array=title_basics_array;
    title_basics_meta->count=movie_count;
    title_basics_meta->tconst_index=0;
    title_basics_meta->title_index=0;

    return title_basics_meta;
}

void build_tb_title_index(struct title_basics_meta *title_basics_meta){
    int i;
    /*Loop over all elements in array*/
    for(i=0;i<(title_basics_meta->count);i++){
        add_node(&(title_basics_meta->title_index),((title_basics_meta->array)+i)->primaryTitle,((title_basics_meta->array)+i));
    }
}


void build_tb_tconst_index(struct title_basics_meta *title_basics_meta){
    int i;
    /*Loop over all elements in array*/
    for(i=0;i<(title_basics_meta->count);i++){
        add_node(&(title_basics_meta->tconst_index),((title_basics_meta->array)+i)->tconst,((title_basics_meta->array)+i));
    }
}


struct title_basics *find_tb_title(struct title_basics_meta *title_basics_meta,char* search_term){
    return (find_node((title_basics_meta->title_index),search_term)->data);
}


struct title_basics *find_tb_tconst(struct title_basics_meta *title_basics_meta,char* search_term){
    return (find_node((title_basics_meta->tconst_index),search_term)->data);
}


