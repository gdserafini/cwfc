#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "head.h"

/* FUNCTIONS */

void print_intro(){
    printf("\n****************************\n");
    printf("Copy, write, format and copy");
    printf("\n****************************\n");
}

void print_end(){
    printf("\nCWFC finished.");
    printf("\n%s %s\n\n", __DATE__, __TIME__);
}

/* FILE - WRITE */
void enter_file_name(char *file_name){
    printf("\nEnter the file name: ");
    fgets(file_name, STR_LEN, stdin);
}

/* TAB + MSG(ENTER THE TEXT) */
void init_text_parag(FILE *f){
    fputc(TAB, f);
    printf("\nEnter the text: ");
}

/* CHECK 4 POSITION OF ARRAY -> '.TXT' -> RETURN 1 */
int is_txt(char *file_name){
    for(int i = 0; i < strlen(file_name)-3; i++){
        if(file_name[i] == '.' && file_name[i+1] == 't' 
        && file_name[i+2] == 'x' && file_name[i+3] == 't'){
            return 1;
        }
    }

    return 0;
}

/* CHECK ANY ERROR AT FILE */
void check_ferror(FILE *f){
    if(f == NULL){
        printf("\nError - empty file.\n");
        exit(1);
    }
    else if(ferror(f)){
        printf("\nError - ");
        printf("\n");
        exit(1);
        
    }
}

/* NULL -> ARRAY */
void init_file_name(char *file_name){
    for(int i = 0; i < strlen(file_name); i++){
        file_name[i] = '\0';
    }
}