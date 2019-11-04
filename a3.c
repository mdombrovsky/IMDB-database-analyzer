#include "name.h"
#include "title.h"
#include "principals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(char **string,char*target);

int main (int argc, char**argv){

    int buffer_size=1024;
    char *buffer=NULL;

    char *nconst;
    char *tconst;

    char *movie_characters;
    char *movie_title;
    char *actor_name;

    struct name_basics_meta* name_basics;
    struct name_basics* name;

    struct title_basics_meta* title_basics;
    struct title_basics* title;

    struct node *node;

    struct title_principals* principals;
    struct title_principals_meta* title_principals;

    if(argc!=2)
    { 
        fprintf( stderr, "Usage:  %s directory\n", argv[0] );
        return-1;
    }

    buffer=malloc(buffer_size+1);

    name_basics=get_name(argv[1]);

    build_nb_name_index(name_basics);
    build_nb_nconst_index(name_basics);

    title_basics=get_title(argv[1]);
    
    build_tb_title_index(title_basics);
    build_tb_tconst_index(title_basics);

    title_principals=get_principals(argv[1]);
    
    build_tp_nconst_index(title_principals);
    build_tp_tconst_index(title_principals);


    while(1){
        printf("> ");
        fgets(buffer,buffer_size,stdin);
    
        if(search(&buffer,"name")){
            actor_name=buffer;
            if(actor_name!=NULL){
                name = find_nb_name(name_basics, actor_name);
                if(name!=NULL){
                    nconst=name->nconst;                   
                    if(nconst!=NULL){
                        node=find_tp_nconst(title_principals, nconst );
                        while(node!=NULL){
                            principals=node->data;
                            if(principals!=NULL){
                                movie_characters=principals->characters;
                                if(movie_characters!=NULL){
                                    tconst=principals->tconst;
                                    if(tconst!=NULL){
                                        title = find_tb_tconst(title_basics, tconst);
                                        if(title!=NULL){
                                            movie_title=title->primaryTitle;
                                            if(movie_title!=NULL){
                                                printf("%s : %s\n",movie_title,movie_characters);
                                            }
                                        }
                                    }
                                }     
                            }
                            node=find_node(node->left_child,nconst);
                        }
                    }
                }
            }
        } else if(search(&buffer,"title")){
            movie_title=buffer;
            if(movie_title!=NULL){
                title = find_tb_title(title_basics, movie_title);
                if(title!=NULL){
                    tconst=title->tconst;
                    if(tconst!=NULL){
                        node=find_tp_tconst(title_principals, tconst );
                        while(node!=NULL){
                            principals=node->data;
                            if(principals!=NULL){
                                movie_characters=principals->characters;
                                if(movie_characters!=NULL){
                                    nconst=principals->nconst;
                                    if(nconst!=NULL){
                                        name = find_nb_nconst(name_basics, nconst);
                                        if(name!=NULL){
                                            actor_name=name->primaryName;
                                            if(actor_name!=NULL){
                                                printf("%s : %s\n",actor_name,movie_characters);
                                            }
                                        }
                                    }
                                }     
                            }
                            node=find_node(node->left_child,tconst);
                        }
                    }
                }
            }    
        } 
    }

    if(buffer){
        free(buffer);
        buffer=NULL;
    }
    return 0;
}

int search(char **string,char*target){

    char *to_search;
    int i;
    int len_search;
    int len_target;
    int len;

    to_search=(*string);

    while((*to_search)==' '){
        to_search++;
    }

    len_search=strlen(to_search);
    len_target=strlen(target);
    len=(len_search>len_target)?(len_target):(len_search);

    for(i=0;i<len;i++){
        if(!(target[i]==(*to_search))){
            return 0;
        }
        to_search++;
    }
    
    while((*to_search)==' '){
        to_search++;
    }

    (*string)=to_search;

    len=strlen(to_search);

    for(i=0;i<len;i++){
        if((*to_search)=='\n'){
            (*to_search)='\0';
        }
        to_search++;
    }
    

    
    return 1;
}

