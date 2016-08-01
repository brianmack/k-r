#include <stdio.h>

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void clear_stack(void)
{
    sp = 0;
}

/* print top element from stack (ex. 4-4) */
void print_stack(void)
{
    if (sp > 0)
        printf("%.2ff\n", val[sp-1]);
    else
        printf("error: stack empty\n");
}

/* duplicate the stack (ex. 4-4) */
void duplicate_top_item(void)
{
    double item = pop();

    push(item);
    push(item);
}

/* swap top two elements of stack (ex. 4-4) */
void swap_elements(void)
{
    double tmp1, tmp2;
    tmp1 = pop();
    tmp2 = pop();
    push(tmp1);
    push(tmp2);
}

