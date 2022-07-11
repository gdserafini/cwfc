/* COPY, WRITE, FORMAT, COPY */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

int main(void){
    char *file_name, c, string[STR_LEN];
    int cc = 4, cd = 0;
    FILE *fc;
    FILE *f;
    
    /* MAIN ALGORITM */
    print_intro();

    do{
    /* ALLOC/REALLOC, INIT/ENTER FILE NAME */
        file_name = malloc(sizeof(char) * STR_LEN);
        init_file_name(file_name);
        enter_file_name(file_name);
        file_name = realloc(file_name, strlen(file_name));
    /**/

        if(is_txt(file_name)){ //WITH .TXT
        /* INIT TXT */
            f = fopen(file_name, "w");
            verif_ferror(f);
            init_text_parag(f);
        /**/

        /* WRITE AND FORMAT */
            do{
                /* C = CHAR, CC = COUNT CHAR, CD = COUNT DOT */
                c = fgetc(stdin); //WRITE
                if(c != ENTER){ cc++; fputc(c, f);
                }
                if(cc == 99){ fputc(ENTER, f); cc = 0; //FORMAT LINES
                }
                if(c == DOT){ cd++; //FORMAT PARAG.(DOT)
                } 
                if(cd == 5){ fputc(ENTER, f); fputc(ENTER, f); fputc(TAB, f); cd = 0; cc = 4;
                }
            }while(c != ENTER);

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