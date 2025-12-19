#include <stdio.h>
#include <string.h>

char unsigned memory[30000] = {0};
unsigned int stackpointer = 0;

int main(int argc, char *argv[])
{

    char bfc[1024];
    FILE *fp;
    fp = fopen(argv[1],"r");

    while(fgets(bfc,sizeof(bfc),fp) != NULL){
        for(int i = 0; i < strlen(bfc); i++){
            switch (bfc[i]){
                case '+':
                    memory[stackpointer]++;
                    break;
                case '-':
                    memory[stackpointer]--;
                    break;
                case '>':
                    stackpointer++;
                    break;
                case '<':
                    stackpointer--;
                    break;
                case '.':
                    printf("%c",memory[stackpointer]);
                    break;
                case '$':
                    char c; 
                    c = getchar();
                    if (c == EOF){
                        c = 0;
                    }
                    memory[stackpointer] = c;
                    break;
                    
            }

        }
    }
}

