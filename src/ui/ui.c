#include "./ui.h"

/*
display options to
1. create a voting process
2. add voters
3. add candidates
4. vote
5. view voter's result (this is done by a voter)
6. end voting process
7. view voting results
else: exit app
 */
void start_app()
{
	// printf("View for main app\n");
	printf("Choose options to:\n");
	printf("1. create a voting process\n");
	printf("2. add voters\n");
	printf("3. add candidates\n");
	printf("4. vote\n");
	printf("5. view voter's result (this is done by a voter)\n");
	printf("6. end voting process\n");
	printf("7. view voting results\n");
	printf("else: exit app\n");
}

void create_voting_process()
{
	// printf("View for creating voting process\n");
	printf("Enter name of voting process: ");
}