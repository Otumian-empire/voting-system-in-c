#include "./controller.h"

// o. start app
int start_app_controller()
{

	start_app();
	int start_option = get_int_input();
	if (!validate_input(start_option, UI_START_APP_OPTION_START, UI_START_APP_OPTION_END))
	{
		char message[100];
		sprintf(message, UI_START_APP_OPTION_ERR_MESSAGE);
		exit_with_error_message(message);
	}

	return start_option;
}

// 1. create a voting process
void create_voting_process_controller()
{
	create_voting_process();
	char str[100];
	get_str_input(str, sizeof(str));
	printf("voting process name: %s\n", str);
}

// 2. add voters
void add_voter_controller()
{
	printf("add_voter_controller\n");
}

// 3. add candidates
void add_candidate_controller()
{
	printf("add_candidate_controller\n");
}

// 4. vote
void vote_controller()
{
	printf("vote_controller\n");
}

// 5. view voter's result (this is done by a voter)
void view_voters_result_controller()
{
	printf("view_voters_result_controller\n");
}

// 6. end voting process
void end_voting_process_controller()
{
	printf("end_voting_process_controller\n");
}

// 7. view voting results
void view_voting_results_controller()
{
	printf("view_voting_results_controller\n");
}
