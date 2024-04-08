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
	print_prompt_ui();

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
	print_prompt_ui();

	char str[100];
	get_str_input(str, sizeof(str));
	printf("voting process name: %s\n", str);
}

/**
 * add voters
 *
 * - calls add voter ui
 * - voter's username, pin and the voting process id is required
 * - Eg: [username] [pin] [voting_process_id]
 */
void add_voter_controller()
{
	char username[11] = {'\0'}, pin[6] = {'\0'};
	int voting_process_id = 0;

	add_voter_ui();

	print_prompt_ui();
	get_str_input(username, sizeof(username));

	print_prompt_ui();
	get_str_input(pin, sizeof(pin));

	print_prompt_ui();
	voting_process_id = get_int_input();

	printf("add_voter_controller: %s %s %d\n", username, pin, voting_process_id);
}

/**
 * add candidates
 *
 * - calls add candidate ui
 * - candidate's username, name and voting process id are required
 * - Eg: [username] [full_name] [voting_process_id]
 */
void add_candidate_controller()
{
	add_candidate_ui();
	char username[11] = {'\0'}, full_name[26] = {'\0'};
	int voting_process_id = 0;

	print_prompt_ui();
	get_str_input(username, sizeof(username));

	print_prompt_ui();
	get_str_input(full_name, sizeof(full_name));

	print_prompt_ui();
	voting_process_id = get_int_input();

	printf("add_candidate_controller: %s %s VPID(%d)\n", username, full_name, voting_process_id);
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
