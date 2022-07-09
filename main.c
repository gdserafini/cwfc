/* COPY, WRITE, FORMAT, COPY */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "head.h"

int main(void){
    char file_name[STR_LEN], ch, string[STR_LEN];
    int countc = 4, countd = 0;
    FILE *fc;
    FILE *f;
    
    /* MAIN ALGORITM */
    print_intro();

    do{
        init_file_name(file_name);
        enter_file_name(file_name);

        if(is_txt(file_name)){ //WITH .TXT
        /* INIT TXT */
            f = fopen(file_name, "w");
            verif_ferror(f);
            init_text_parag(f);
        /**/

        /* WRITE AND FORMAT */
            do{
                write_file(&ch, &countc, f);
                format_line(&countc, f);
                format_parag(&ch, &countd, &countc, f);
            }while(!end_write(ch));

            fclose(f);
        /**/
        
        /* COPY */
            fc = fopen("scopy.txt", "w");
            f = fopen(file_name, "r");
            verif_ferror(fc);
            verif_ferror(f);

            do{
                fgets(string, STR_LEN, f);
                fputs(string, fc);
                verif_ferror(fc);
                verif_ferror(f);
            }while(!feof(f));

            fclose(fc);
            fclose(f);
        /**/
        }
        else{
            printf("\nEnter a .txt file name.\n");
        }
    }while(!is_txt(file_name)); //REPEAT IF != .TXT

    print_end();

    return 0;
}

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

/* END -> PRESS ENTER */
int end_write(char ch){
    if(ch == ENTER){
        return 1;
    }
    else{
        return 0;
    }
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
void verif_ferror(FILE *f){
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

/* WRITE IN FILE_NAME */
void write_file(char *ch, int *countc, FILE *f){
    *ch = fgetc(stdin);

    if(*ch != ENTER){
        (*countc)++;
        fputc(*ch, f);
    }
}

/* LINE SIZE = 100 CH */
void format_line(int *countc, FILE *f){
    if(*countc == STR_LEN-1){
        fputc(ENTER, f);
        *countc = 0;
    }
}

/* 5 DOTS -> FORMAT (NEW PARAGRAPH) */
void format_parag(char *ch, int *countd, int *countc, FILE *f){
    if(*ch == DOT){
        (*countd)++;

        if(*countd == MAXD){
            fputc(ENTER, f);
            fputc(ENTER, f);
            fputc(TAB, f);
            *countd = 0;
            *countc = 4;
        }
    }
}

/* NULL -> ARRAY */
void init_file_name(char *file_name){
    for(int i = 0; i < strlen(file_name); i++){
        file_name[i] = '\0';
    }
}