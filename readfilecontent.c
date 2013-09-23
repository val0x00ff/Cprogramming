/*
Description: Read file content. Similair to `cat` command
Copyrigh ⓒ  me
*/


#include <stdio.h>

#define NL printf("\n");

int main( int argc, char *argv[])
{
    if( argc != 2)
        printf("Usage: %s [filename]\n\n", argv[0]);
    else{
        FILE *file;
        file = fopen(argv[1], "r");
        if(file == NULL){
            printf("Could not open file %s or file %s doesn't exist", argv[1], argv[1]);
            NL NL
            return 1;
            }
        else{
            int input;
            if(fgetc(file) == 0){
                printf("File %s is empty\n\n", argv[1]);
                return (-1);
            }
            fseek(file, 0, SEEK_SET);
            while((input = fgetc(file)) != EOF)
               printf("%c", input); 
        }
        fclose(file);
    }
}
