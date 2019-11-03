/**
 * Name: Michael Dombrovsky
 * Student Number: 1040277
 * Email: mdombrov@uoguelph.ca
 **/ 
#include<string.h>
#include<stdlib.h>

struct node{
    char* key;
    void *data;
    struct node *left_child;
    struct node *right_child;
};
void add_node(struct node **node,char*key,void*data);
void* find_node(struct node *node,char *key);