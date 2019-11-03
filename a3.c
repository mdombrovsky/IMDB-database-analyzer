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

    printf( "\n" );

    name_basics=get_name(argv[1]);
    build_nb_name_index(name_basics);
    build_nb_nconst_index(name_basics);

    title_basics=get_title(argv[1]);
    build_tb_title_index(title_basics);
    build_tb_tconst_index(title_basics);

    title_principals=get_principals(argv[1]);
    build_tp_nconst_index(title_principals);
    build_tp_tconst_index(title_principals);

    printf( "Ready\n" );

    title = find_tb_title( title_basics, "Blade Runner" );

    principals = find_tp_tconst( title_principals, title->tconst );

    name = find_nb_nconst( name_basics, principals->nconst );

 

  printf( "%s\n", name->primaryName );



  name = find_nb_name( name_basics, "Bruce Lee" );

  principals = find_tp_nconst( title_principals, name->nconst );

  title = find_tb_tconst( title_basics, principals->tconst );

  printf( "%s\n", title->primaryTitle );

    return 0;
}