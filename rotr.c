#include "monty.h"

/**
  *f_rotr- rotates the stack to the bottom
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *copy = *head;

	/* Check if the stack is empty or has only one element */
	if (*head == NULL || (*head)->next == NULL)
		return;

	/* Find the last element of the stack */
	while (copy->next)
		copy = copy->next;

	/* Rotate the stack to the right */
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	*head = copy;
}

