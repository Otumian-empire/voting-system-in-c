#include "./ui.h"

void print_prompt_ui()
{
	printf(UI_INPUT_PROMPT);
}

/**
 * start_app_ui
 *
 * displays options to
 * - 1. create a voting process
 * - 2. add voters
 * - 3. add candidates
 * - 4. vote
 * - 5. view voter's result (this is done by a voter)
 * - 6. end voting process
 * - 7. view voting results
 * - else: exit app
 */
void start_app_ui()
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

/**
 * create_voting_process_ui
 *
 * displays the create voting process prompt
 */
void create_voting_process_ui()
{
	// printf("View for creating voting process\n");
	printf("Enter name of voting process\n");
}

/**
 * add_voter_ui
 *
 * - displays prompt for adding a voter onto a voting process
 * - Eg: [username] [pin] [voting_process_id]
 */
void add_voter_ui()
{
	printf("Enter voter's username, pin and voting process ID in order\n");
	printf("Eg: 1000001211 1234 1\n");
}

/**
 * add_candidate_ui
 *
 * - displays prompt for adding a candidate onto a voting process
 */
void add_candidate_ui()
{
	printf("Enter voter's username, full name and voting process ID in order\n");
	printf("Eg: 1000001211 john doe 1\n");
}

/**
 * vote_ui
 *
 * - displays the prompt for a registered voter to vote
 * - Eg: [voting_process] [username] [pin] [candidate] [confirmation]
 */
void vote_ui()
{
	printf("Choose a voting process, login, choose candidate and confirm vote\n");
	printf("Eg: [voting_process] [username] [pin] [candidate] [confirmation]\n");
}
