#define NUMBER '0'
#define FUNC '1'

void push(double);
double pop(void);
int getop(char []);
void clear_stack(void);
void duplicate_top_item(void);
void swap_elements(void);

int getch(void);
void ungetch(int);
int streq(char [], char []);
