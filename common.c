#include "common.h"
/**
 * Name: Michael Dombrovsky
 * Student Number: 1040277
 * Email: mdombrov@uoguelph.ca
 **/ 
void get_column(char *line, char **toReturn, int columnNumber){
    char *start;
    int i;
    int len;
    int tCount;

    tCount=0;
    
    len=strlen(line);   

    /*Get start*/
    for(i=0;(i<len)&&(tCount<columnNumber);i++){
        if((*line)=='\t'){
            tCount++;
        }
        line++;
    }
    start=line;

    len=strlen(line);

    /*Get end*/
    for(i=0;(i<len)&&((*line)!='\t');i++){
        line++;
    }

    len=line-start;

    (*toReturn)=malloc(len+1);

    strncpy((*toReturn),start,len);
    if(len!=0){
        if((*toReturn)[len-1]=='\n'){
            (*toReturn)[len-1]='\0';   
        }
    }
    (*toReturn)[len]='\0';
}

void reverse(char*string){
    int i;
    char temp;
    int len=strlen(string)-1;
    for(i=0;i<len/2;i++){
        temp=string[i];
        string[i]=string[len-i];
        string[len-i]=temp;
    }
}