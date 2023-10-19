#include "monty.h"

/**
 * f_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 *
 * Return: no return
 */
void f_mul(stack_t **head, unsigned int counter)
{
	int len = 0, aux;
	stack_t *h = *head;

	/* Calculate the length of the stack */
	for (; h; h = h->next)
	{
		len++;
	}

	/* Check if the stack is too short */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;

	/* Perform the multiplication and update the stack */
	aux = h->n * h->next->n;
	h->next->n = aux;
	*head = h->next;

	free(h);
}

