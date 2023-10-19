#include "monty.h"

/**
 * f_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @counter: line_number
 *
 * Return: no return
 */
void f_mod(stack_t **head, unsigned int counter)
{
	int len = 0, aux;
	stack_t *h = *head;

	/* Calculate the length of the stack */
	while (h)
	{
		h = h->next;
		len++;
	}

	/* Check if the stack is too short */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;

	/* Check for division by zero */
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Perform the modulus operation and update the stack */
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

