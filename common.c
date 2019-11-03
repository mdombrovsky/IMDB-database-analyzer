#include "common.h"

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

    (*toReturn)[len]='\0';
  

}