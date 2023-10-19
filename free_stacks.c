#include "monty.h"
/**
* free_stack - frees list
* @head: head of the stack
*/

void free_stack(stack_t *head)
{
	stack_t *aux;

	/*/ Free each node in the stack */
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}

