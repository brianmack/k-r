/* do the reverse a linked list problem */
#include <stdlib.h>
#include <stdio.h>

#define LISTLEN 5

struct node {
    struct node *next;
    struct node *prev;
    int value;
};


struct node *reverse_linked_list(struct node *);
void print_linked_list(struct node *);
struct node *add_node(struct node *);
struct node *nalloc(void);


/* initialize a linked list, print it, reverse it, and print again */
int main()
{
    int listlen = LISTLEN;
    
    /* some arbitrary value to set list nodes to */
    int inc = 10; 
    int *incp = &inc;
    
    /* default values for head */
    struct node linked_list = {NULL, NULL, inc}; 
    struct node *lp = &linked_list;

    /* fill in with range of values */
    while (listlen--) {
        lp->value = (*incp)++;
        if (listlen)
            lp = add_node(lp);
    }

    printf("original list:\n");
    print_linked_list(&linked_list);

    lp = reverse_linked_list(&linked_list);
    
    printf("reversed list:\n");
    print_linked_list(lp);
    
    return 0;
}

/* make a new linked list node */
struct node *nalloc(void)
{
    return (struct node *)malloc(sizeof(struct node));
}

/* allocate memory and return new node with defualt
   NULL value for next pointer */
struct node *add_node(struct node *l)
{
    struct node *new;
    new = nalloc();
    l->next = new;
    new->prev = l;
    new->next = NULL;
    return new;
}

/* recursively follow nodes and print values */
void print_linked_list(struct node *l)
{
    if (l != NULL) {
        printf("%d\n", l->value);
        print_linked_list(l->next);
    }
}


struct node *reverse_linked_list(struct node *l)
{
    struct node *tmp;
    while ((tmp = l->next) != NULL) {
        l->next = l->prev;
        l = l->prev = tmp;
    }
    l->next = l->prev;
    
    return l;
}
