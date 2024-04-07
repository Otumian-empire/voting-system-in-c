#include "./include.h"

/* get an integer from the cmdline to represent an option */
int get_int_input()
{
	int input = 0;
	scanf("%d", &input);

	// this is to remove the \n character from the stdin after scanf
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
	{
	};

	return input;
}

/* check that  start <= input <= end */
int validate_input(int input, int start, int end)
{
	return input >= start && input <= end;
}

/* get string input */
void get_str_input(char *input, size_t size)
{
	fgets(input, size, stdin);
	if (input[strlen(input) - 1] == '\n')
	{
		input[strlen(input) - 1] = '\0';
	}
}

/* print some error message and exit */
void exit_with_error_message(char *error_message)
{
	printf("%s\n", error_message);
	exit(0);
}