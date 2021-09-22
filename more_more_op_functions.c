#include "monty.h"

/**
 * op_div - add two elements on the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: number of the current line
 *
 * Return: the number of nodes
 */
void op_div(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%u: can't div, stack too short\n", slayer.n_lines);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next->n == 0)
	{
		slayer_list(slayer.stack_head);
		free(slayer.getl_info);
		fclose(slayer.fp_struct);
		fprintf(stderr, "L%u: division by zero\n", slayer.n_lines);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->n = (*stack)->n / (*stack)->prev->n;
		(*stack)->prev = NULL;
		free(temp);
	}
}

/**
 * op_mul - add mul elements on the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: number of the current line
 *
 * Return: the number of nodes
 */
void op_mul(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%u: can't mul, stack too short\n", slayer.n_lines);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->n = (*stack)->n * (*stack)->prev->n;
		(*stack)->prev = NULL;
		free(temp);
	}
}

/**
 * op_mod - mod two elements on the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: number of the current line
 *
 * Return: the number of nodes
 */
void op_mod(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%u: can't mod, stack too short\n", slayer.n_lines);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next->n == 0)
	{
		slayer_list(slayer.stack_head);
		free(slayer.getl_info);
		fclose(slayer.fp_struct);
		fprintf(stderr, "L%u: division by zero\n", slayer.n_lines);
		exit(EXIT_FAILURE);
	}
	if (*stack != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->n = (*stack)->n % (*stack)->prev->n;
		(*stack)->prev = NULL;
		free(temp);
	}
}