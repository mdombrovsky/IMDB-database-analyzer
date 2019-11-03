/**
 * Name: Michael Dombrovsky
 * Student Number: 1040277
 * Email: mdombrov@uoguelph.ca
 **/ 


struct name_basics_meta{
    struct name_basics *array;
    int count;
    struct node *nconst_index;
    struct node *name_index;
};

struct name_basics {
    char *nconst;
    char *primaryName;
};

struct name_basics_meta *get_name(char* string);
void build_bn_name_index(struct name_basics_meta *name_basics_meta);
struct name_basics *find_primary_name(struct name_basics_meta *name_basics_meta,char* search_term);