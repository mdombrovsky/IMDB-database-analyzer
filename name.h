#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct name_basics {
    char *nconst;
    char *primaryName;
};

struct name_basics *get_name(char* string);