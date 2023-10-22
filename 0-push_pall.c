#include "monty.h"

/**
 * f_push - Implements the push opcode.
 * @head: Double pointer to the head of the stack.
 * @number: The integer value to push onto the stack.
 */
void f_push(stack_t **head, unsigned int number)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = number;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL)
        (*head)->prev = new_node;

    *head = new_node;
}

/**
 * f_pall - Implements the pall opcode.
 * @head: Double pointer to the head of the stack.
 * @number: Line number (unused).
 */
void f_pall(stack_t **head, unsigned int number)
{
    stack_t *current;
    (void)number;
    current = *head;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}