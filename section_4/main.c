#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define FUNC '1' /* signal that a function string was found */

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case FUNC:
                if (streq(s, "sin"))
                    push(sin(pop()));
                else if (streq(s, "pow")) {
                    op2 = pop();
                    push(pow(pop(), op2));
                }
                else if (streq(s, "exp")) {
                    push(exp(pop()));
                } else {
                    printf("error: not a command: %s\n", s);
                }
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '^':
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '!':
                clear_stack();
                break;
            case '#':
                duplicate_top_item();
                break;
            case '~':
                swap_elements();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

