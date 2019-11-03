#include "name.h"

int main (int argc, char**argv){


    struct name_basics* nameBasics;

    if(argc!=2)
    { 
        fprintf( stderr, "Usage:  %s directory\n", argv[0] );
        return-1;
    }
    printf("here1\n");
    fflush(stdout);
    nameBasics=get_name(argv[1]);

    if(nameBasics){}
    return 0;
}