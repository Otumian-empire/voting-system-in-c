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
	printf("%d. create a voting process\n", VOTING_PROCESS);
	printf("%d. add voters\n", ADD_VOTER);
	printf("%d. add candidates\n", ADD_CANDIDATE);
	printf("%d. vote\n", VOTE);
	printf("%d. view voter's result (this is done by a voter)\n", VIEW_VOTERS_RESULT);
	printf("%d. end voting process\n", END_VOTING_PROCESS);
	printf("%d. view voting results\n", VIEW_VOTING_RESULTS);
	printf("%d. view voting processes\n", VIEW_LIST_VOTING_PROCESSES);
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

/**
 * view_voters_result_ui
 *
 * - displays a voter's result (this is done by a voter)
 * - it could also be used to know whether voter has voted
 * - Eg: [voting_process] [username] [pin]
 */
void view_voters_result_ui()
{
	printf("Choose a voting process and login\n");
	printf("Eg: [voting_process] [username] [pin]\n");
}

/**
 * end_voting_process_ui
 *
 * - display a view for the admin to end a voting process
 * - Eg: [voting_process]
 */
void end_voting_process_ui()
{
	printf("Choose voting process to end\n");
}

/**
 * view_voting_results_ui
 *
 * - displays the results for a voting process (vote collation)
 * - Eg: [voting_process]
 */
void view_voting_results_ui()
{
	printf("Choose voting process to display result\n");
}

/**
 * view_list_voting_processes_ui
 *
 * displays the headers for the voting process list
 */
void view_list_voting_processes_ui()
{
	char pads[] = "----------";
	printf("Voting processes\n");
	printf("%-4s %-30s %-4s\n", "ID", "NAME", "STATUS");
	printf("%s-%s-%s-%s\n", pads, pads, pads, pads);
}