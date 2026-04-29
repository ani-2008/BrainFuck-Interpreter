#include <stdio.h>
#include <string.h>

#define MEMORY_SIZE 30000 
char memory[MEMORY_SIZE] = {0};
unsigned int stackpointer = 0;

int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("USAGE: bfi <brainfuck filename>\n");
        return -1;
    }
    FILE *fp;
    fp = fopen(argv[1],"r");
    if(fp == NULL){
        printf("ERROR OPENING BRAINFUCK FILE\n");
        return -1;
    }
    char instruction[65535];
    char c;
    int i = 0; 

    while ((c = fgetc(fp)) != EOF && i < 65534){
        if (c == '+' || c == '-' || c == '<' || c == '>' || c == '.' || c == ',' || c == '[' || c == ']'){
            instruction[i] = c;
            i++;
        }
        
    }
    instruction[i++] = '\0'; 
    int in_ptr;

    size_t instruction_len = strlen(instruction);
    
    char inp;
    int depth = 0;
    for(in_ptr = 0; in_ptr < instruction_len; in_ptr++){
        switch (instruction[in_ptr]){
            case '+':
                memory[stackpointer]++;
                break;
            case '-':
                memory[stackpointer]--;
                break;
            case '>':
                stackpointer = (stackpointer + 1) % MEMORY_SIZE;

                break;
            case '<':
                stackpointer = (stackpointer - 1 + MEMORY_SIZE) % MEMORY_SIZE;
                break;
            case '.':
                printf("%c",memory[stackpointer]);
                break;
            case ',': 
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
    fclose(fp);

}
