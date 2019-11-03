#include "name.h"
#include "title.h"
#include "principals.h"
#include <stdio.h>

int main (int argc, char**argv){


    struct name_basics_meta* name_basics;
    struct name_basics* name;

    struct title_basics_meta* title_basics;
    struct title_basics* title;

    struct title_principals* principals;
    struct title_principals_meta* title_principals;

    if(argc!=2)
    { 
        fprintf( stderr, "Usage:  %s directory\n", argv[0] );
        return-1;
    }

    /*name_basics=get_name(argv[1]);
    build_bn_name_index(name_basics);
    build_bn_nconst_index(name_basics);

    title_basics=get_title
   */

 

  printf( "%p\n", (void *)name );

  printf( "%s\n", name->nconst );

  printf( "%s\n", name->primaryName );

    return 0;
}