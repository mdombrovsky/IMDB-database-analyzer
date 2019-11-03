/**
 * Name: Michael Dombrovsky
 * Student Number: 1040277
 * Email: mdombrov@uoguelph.ca
 **/

#include "binary.h"

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

void* find_node(struct node *node,char *key){
    if(node){
        if(strcmp(node->key,key)==0){
            return node->data;
        } else if(strcmp(node->key,key)<0){
            return find_node(node->right_child,key);
        } else{
           return find_node(node->left_child,key);
        }
    }else{
        return NULL;
    }
}