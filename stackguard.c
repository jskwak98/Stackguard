#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int secret;

int no_guard(char *str)
{
    char buffer[6];
    strcpy(buffer, str);
    return 1;
}

int stackguard(char *str)
{
    int guard = secret;

    char buffer[6];
    strcpy(buffer, str);

    if (guard != secret){
        printf("Stack Overwritten, Secret : %d, Guard : %d\n", secret, guard);
        exit(0);
    }
    
    return 1;
}

int main(int argc, char *argv[])
{   
    srand(time(NULL));
    secret = rand();

    if(argc != 2)
    {
        printf("Please pass one string argument when running.\n");
        exit(0);
    }

    no_guard(argv[1]);
    printf("No_guard returned properly\n");
    stackguard(argv[1]);
    printf("Stackguard returned properly\n");

    return 1;
}