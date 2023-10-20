#include "monty.h"

/**
 * f_pint - Implements the pint opcode.
 * @head: Double pointer to the head of the stack.
 * @number: Line number (unused).
 */
void f_pint(stack_t **head, unsigned int number)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*head)->n);
}
