#include "monty.h"

/**
 * f_pint - prints the top
 * @head: stack head
 * @counter: line_number
 *
 * Return: no return
 */
void f_pint(stack_t **head, unsigned int counter)
{
	/* Check if the stack is empty */
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Print the value at the top of the stack */
	printf("%d\n", (*head)->n);
}

