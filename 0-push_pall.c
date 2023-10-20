#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

stack_t *stack = NULL;

void push(int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = stack;

    if (stack != NULL)
        stack->prev = new_node;

    stack = new_node;
}

void pall()
{
    stack_t *current = stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    pall();

    return 0;
}
