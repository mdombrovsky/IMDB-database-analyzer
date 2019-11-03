#include "title.h"

struct title_basics *get_title(char* string){

    FILE *fptr;

    struct title_basics *title_basics_array=NULL;

    char *buffer;
    char *file_name;
    char suffix [20] = "/title.basics.tsv";

    char *data=NULL;

    char *column=NULL;
    
    int movie_count=0;

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


    return title_basics_array;
}

