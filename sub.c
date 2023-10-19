#include "monty.h"
/**
  *f_sub- sustration
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
#include "monty.h"

void f_sub(stack_t **head, unsigned int counter)
{
    int sus, nodes = 0;
    stack_t *aux = *head;

    /*/ Calculate the length of the stack */
    for (; aux; aux = aux->next, nodes++);

    /*/ Check if the stack is too short */
    if (nodes < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    aux = *head;

    /*/ Perform the subtraction and update the stack */
    sus = aux->next->n - aux->n;
    aux->next->n = sus;
    *head = aux->next;
    
    free(aux);
}

