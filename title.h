/**
 * Name: Michael Dombrovsky
 * Student Number: 1040277
 * Email: mdombrov@uoguelph.ca
 **/ 

struct title_basics_meta {
    struct title_basics *array;
    int count;
    struct node *tconst_index;
    struct node *title_index;
};


struct title_basics{
    char *tconst;
    char *primaryTitle;
};

struct title_basics_meta *get_title(char* string);

void build_bt_title_index(struct title_basics_meta *title_basics_meta);
struct title_basics *find_primary_title(struct title_basics_meta *title_basics_meta,char* search_term);