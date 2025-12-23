#include <stdio.h>
#include <string.h>

char memory[30000] = {0};
unsigned int stackpointer = 0;

int main(int argc, char *argv[])
{

    FILE *fp;
    fp = fopen(argv[1],"r");

    char instruction[65535];
    char c;
    int i = 0; 
    int depth = 0;
    while ((c = fgetc(fp)) != EOF && i != 65535){
        if (c == '+' || c == '-' || c == '<' || c == '>' || c == '.' || c == ',' || c == '[' || c == ']'){
            instruction[i] = c;
            i++;
        }
        
    }
    instruction[i++] = '\0'; 
    int in_ptr;
    for(in_ptr = 0; in_ptr < strlen(instruction); in_ptr++){
        switch (instruction[in_ptr]){
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
            case ',':
                char inp; 
                inp = getchar();
                if (inp == EOF){
                    inp = 0;
                }
                memory[stackpointer] = inp;
                break;
            case '[':
                if(memory[stackpointer] == 0){
                    
                    int depth = 1;
                    while(depth > 0){
                        in_ptr++;
                        c = instruction[in_ptr];
                        if (c == '\0'){
                            printf("INVALID\n");
                            return 1;
                        }else if(c == '['){
                            depth++;
                        }else if(c == ']'){
                            depth--;
                        }
                       in_ptr++;
                    }
                }
                break;
            case ']':
                if(memory[stackpointer] != 0){
                    
                    int depth = 1;
                    while(depth > 0){
                        in_ptr--;
                        c = instruction[in_ptr];
                        if (c == '['){
                            depth--;
                        }else if (c == ']'){
                            depth++;
                        }
                        
                    }
                }
                break;
            }

        }

}
