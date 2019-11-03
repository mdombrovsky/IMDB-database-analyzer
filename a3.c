#include "name.h"
#include "title.h"
#include "principals.h"

int main (int argc, char**argv){


    struct title_principals* title_principals;
    int i;

    if(argc!=2)
    { 
        fprintf( stderr, "Usage:  %s directory\n", argv[0] );
        return-1;
    }

    title_principals=get_principals(argv[1]);

  for (i=0;i<10;i++)

  {

    printf( "%s %s %s\n", title_principals[i].tconst,

                          title_principals[i].nconst,

                          title_principals[i].characters );

  }

  printf( "\n" );

  for (i=14627307;i<14627317;i++)

  {

    printf( "%s %s %s\n", title_principals[i].tconst,

                          title_principals[i].nconst,

                          title_principals[i].characters );

  }

 

    return 0;
}