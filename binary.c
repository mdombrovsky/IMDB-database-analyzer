/**
 * Name: Michael Dombrovsky
 * Student Number: 1040277
 * Email: mdombrov@uoguelph.ca
 **/

#include "binary.h"
#include <stdio.h>

void add_node(struct node **node,char*key,void*data){
    if(*node){
        if(strcmp(((*node)->key),key)<0){
            /*Put it on the right*/
            add_node(&((*node)->right_child),key,data);
        } else{
            /*Put it on the left*/
            add_node(&((*node)->left_child),key,data);
        }
    }else{

        (*node)=malloc(sizeof(struct node));
        (*node)->key=key;
        (*node)->data=data;
        (*node)->right_child=NULL;
        (*node)->left_child=NULL;
    }
}

struct node* find_node(struct node *node,char *key){
    if(node){
        /*printf("Comparing: |%s| and |%s|\n",node->key,key);*/
        if(strcmp(node->key,key)==0){
            return node;
        } else if(strcmp(node->key,key)<0){
            /*printf("right\n");*/
            return find_node(node->right_child,key);
        } else{
            /*printf("left\n");*/
           return find_node(node->left_child,key);
        }
    }else{
        return NULL;
    }
}

void free_tree(struct node*node){
    if(node){
        free_tree(node->right_child);
        free_tree(node->left_child);
        free(node);
        node=NULL;
    }
}