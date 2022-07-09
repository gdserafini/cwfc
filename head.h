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

void verif_ferror(FILE *f);

void write_file(char *ch, int *countc, FILE *f);

void format_line(int *countc, FILE *f);
void format_parag(char *ch, int *countd, int *countc, FILE *f);
