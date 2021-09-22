#include "monty.h"

/**
 * op_add - add two elements on the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: number of the current line
 *
 * Return: the number of nodes
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	size_t n = 0;
	stack_t *temp = *stack;

	line_number = line_number;
	n = dlistint_len(slayer.stack_head);
	if (n < 2)
	{
		slayer_list(slayer.stack_head);
		free(slayer.getl_info);
		fclose(slayer.fp_struct);
		fprintf(stderr, "L%u: can't add, stack too short\n", slayer.n_lines);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->n = (*stack)->n + (*stack)->prev->n;
		(*stack)->prev = NULL;
		free(temp);
	}
}

/**
 * dlistint_len - returns the number of elements in a d linked list
 * @h: head of the linked list
 *
 * Return: the number of nodes
 */
size_t dlistint_len(stack_t *h)
{
	size_t n_nodes = 0;

	if (h == NULL)
	{
		return (0);
	}
	while (h != NULL)
	{
		h = h->next;
		n_nodes++;
	}
	return (n_nodes);
}

/**
 * op_nop - do nothing
 * @stack: pointer to the head of the stack
 * @line_number: number of the current line
 *
 * Return: the number of nodes
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	stack = stack;
	line_number = line_number;
}

/**
 * op_pop - delete the element on the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: number of the current line
 *
 * Return: the number of nodes
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	line_number = line_number;
	if (temp == NULL)
	{
		slayer_list(slayer.stack_head);
		free(slayer.getl_info);
		fclose(slayer.fp_struct);
		fprintf(stderr, "L%u: can't pop an empty stack\n", slayer.n_lines);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	if (*stack)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}

/**
 * op_sub - sub two elements on the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: number of the current line
 *
 * Return: the number of nodes
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	size_t n = 0;
	stack_t *temp = *stack;

	line_number = line_number;
	n = dlistint_len(slayer.stack_head);
	if (n < 2)
	{
		slayer_list(slayer.stack_head);
		free(slayer.getl_info);
		fclose(slayer.fp_struct);
		fprintf(stderr, "L%u: can't sub, stack too short\n", slayer.n_lines);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->n = (*stack)->n - (*stack)->prev->n;
		(*stack)->prev = NULL;
		free(temp);
	}
}