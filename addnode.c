#include "monty.h"

/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 *
 * Return: no return
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *aux = *head;

	/* Check if the memory allocation was successful */
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	/* Initialize the new node */
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	/* Insert the new node at the beginning of the stack */
	if (aux)
		aux->prev = new_node;
	*head = new_node;
}

