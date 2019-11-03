#include "name.h"
#include "title.h"
#include "principals.h"
#include <stdio.h>

int main (int argc, char**argv){


    struct name_basics_meta* name_basics;
    struct name_basics* name;

    if(argc!=2)
    { 
        fprintf( stderr, "Usage:  %s directory\n", argv[0] );
        return-1;
    }

    name_basics=get_name(argv[1]);

    build_bn_name_index(name_basics);
    name = find_primary_name( name_basics, 

                            "Anthony Daniels" );

 

  printf( "%p\n", (void *)name );

  printf( "%s\n", name->nconst );

  printf( "%s\n", name->primaryName );

    return 0;
}