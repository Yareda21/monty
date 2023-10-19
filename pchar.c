#include "monty.h"

/**
 * f_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 *
 * Return: no return
 */
void f_pchar(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;

	/* Check if the stack is empty */
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Check if the value is a printable ASCII character */
	if (h->n < 0 || h->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Print the ASCII character */
	printf("%c\n", h->n);
}

