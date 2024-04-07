#include "./include.h"

/* get an integer from the cmdline to represent an option */
int get_int_input()
{
	int int_input = 0;
	scanf("%d", &int_input);

	return int_input;
}

/* check that  start <= input <= end */
int validate_input(int input, int start, int end)
{
	return input >= start && input <= end;
}
