#include "./controller.h"

/**
 * start app
 *
 * - calls start app ui
 * - returns an integer, the option chosen for an action
 */
int start_app_controller()
{
	start_app_ui();
	int start_option = get_int_input();
	if (!validate_input(start_option, UI_START_APP_OPTION_START, UI_START_APP_OPTION_END))
	{
		char message[100];
		sprintf(message, UI_START_APP_OPTION_ERR_MESSAGE);
		exit_with_error_message(message);
	}

	return start_option;
}

/**
 * create a voting process
 *
 * - calls create voting process ui
 * - name of the voting process is required. it is read from the stdin
 */
void create_voting_process_controller()
{
	create_voting_process_ui();
	char str[100];
	get_str_input(str, sizeof(str));
	printf("voting process name: %s\n", str);
}

/**
 * add voters
 *
 * - calls add voter ui
 * - voter's username, pin and the voting process id is required
 */
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
