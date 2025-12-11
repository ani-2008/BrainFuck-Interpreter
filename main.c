#include <stdio.h>
#include <string.h>

char unsigned memory[30000] = {0};
unsigned int stackpointer = 0;

int main(int argc, char *argv[])
{

    char bfc[1024];
    FILE *fp;
    fp = fopen(argv[1],"r");
    fgets(bfc,sizeof(bfc),fp);
    printf(bfc);
}

