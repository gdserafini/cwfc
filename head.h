#define STR_LEN 100 //LINE SIZE TOO
#define ENTER '\n'
#define TAB '\t'
#define DOT '.'
#define MAXD 5 //DOTS PER PARAGRAPH

void print_intro(void);
void print_end(void);

void enter_file_name(char *file_name);
int is_txt(char *file_name);
void init_file_name(char *file_name);
void init_text_parag(FILE *f);

void check_ferror(FILE *f);