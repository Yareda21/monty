#include "monty.h"
/**
 * f_pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/

void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;

	/*/ Ignore unused variable */
	(void)counter;

	/*/ Check if the stack is empty */
	if (h == NULL)
		return;

	/*/ Print all elements of the stack */
	for (; h; h = h->next)
		printf("%d\n", h->n);
}

