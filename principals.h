/**
 * Name: Michael Dombrovsky
 * Student Number: 1040277
 * Email: mdombrov@uoguelph.ca
 **/ 
#include "binary.h"
struct title_principals {
    char *nconst;
    char *tconst;
    char *characters;
};

struct title_principals_meta {
    struct title_principals *array;
    int count;
    struct node *tconst_index;
    struct node *nconst_index;
};




struct title_principals_meta *get_principals(char* string);

struct node *find_tp_tconst(struct title_principals_meta *title_principals_meta,char* search_term);
void build_tp_tconst_index(struct title_principals_meta *title_principals_meta);

struct node *find_tp_nconst(struct title_principals_meta *title_principals_meta,char* search_term);
void build_tp_nconst_index(struct title_principals_meta *title_principals_meta);
