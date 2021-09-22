#include "monty.h"
hero_t slayer;
/**
 *  main -  interpreter for Monty ByteCodes files
 *  @argc: Number of paramethers
 *  @argv: Pointer to all the paramethers
 *
 *  Return: Always 0
 */
int main(int argc, char **argv)
{
	ssize_t line_size;
	size_t line_buf_size = 0;

	slayer.stack_head = NULL;
	slayer.n_lines = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	slayer.fp_struct = fopen(argv[1], "r");
	if (!slayer.fp_struct)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((line_size = getline(&slayer.getl_info,
				    &line_buf_size, slayer.fp_struct)) != EOF)
	{
		slayer.n_lines++;
		delim_checker(slayer.getl_info);
		split_str(slayer.getl_info);
		opcode(slayer.getl_info);
	}
	free(slayer.getl_info);
	slayer_list(slayer.stack_head);
	fclose(slayer.fp_struct);
	return (EXIT_SUCCESS);
}