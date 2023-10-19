#include "monty.h"

/**
 * f_queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_queue(stack_t **head, unsigned int counter)
{
	/* Ignore unused variables */
	(void)head;
	(void)counter;

	/* Set the queue mode */
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *aux = *head;

	/* Check if the memory allocation was successful */
	if (new_node == NULL)
	{
		printf("Error\n");
		return;
	}

	/* Initialize the new node */
	new_node->n = n;
	new_node->next = NULL;

	/* Add the new node to the end of the queue */
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new_node;
		new_node->prev = aux;
	}
	else
	{
		*head = new_node;
		new_node->prev = NULL;
	}
}

