#include "./controller.h"

/**
 * start_app_controller
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
		char message[TITLE_SIZE];
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

	char voting_process_name[TITLE_SIZE];
	get_str_input(voting_process_name, sizeof(voting_process_name));

	if (SUCCESS == create_voting_process_model(voting_process_name))
	{
		printf("voting process name: %s\n", voting_process_name);
	}
	else
	{
		// TODO: this can be refactored into a function and process
		// or event name can be passed to it. Eg: Voting process
		// void print_error_message(char* event_name);
		// I tried something like that but it didn't work so reverted it
		// I think this function should be in the model since it will
		// have access to sqlite from there
		char error_message[TITLE_SIZE];
		get_connection_error_message(error_message);

		fprintf(
			stderr,
			"Error occurred while creating 'Voting process': %s\n",
			error_message);
	}
}

/**
 * add_voter_controller
 *
 * - calls add voter ui
 * - voter's username, pin and the voting process id is required
 * - Eg: [username] [pin] [voting_process_id]
 */
void add_voter_controller()
{
	char username[USER_NAME_SIZE] = {'\0'}, pin[PIN_SIZE] = {'\0'};
	int voting_process_id = 0;

	add_voter_ui();

	print_prompt_ui();
	get_str_input(username, sizeof(username));

	print_prompt_ui();
	get_str_input(pin, sizeof(pin));

	print_prompt_ui();
	voting_process_id = get_int_input();

	if (SUCCESS == create_registered_voter_model(voting_process_id, username, pin))
	{
		printf("add_voter_controller: %s %s %d\n", username, pin, voting_process_id);
	}
	else
	{
		// TODO: refactor to use the function
		char error_message[TITLE_SIZE];
		get_connection_error_message(error_message);

		fprintf(
			stderr,
			"Error occurred while creating 'Registered voter': %s\n",
			error_message);
	};
}

/**
 * add_candidate_controller
 *
 * - calls add candidate ui
 * - candidate's username, name and voting process id are required
 * - Eg: [username] [full_name] [voting_process_id]
 */
void add_candidate_controller()
{
	add_candidate_ui();
	char username[USER_NAME_SIZE] = {'\0'}, full_name[NAME_SIZE] = {'\0'};
	int voting_process_id = 0;

	print_prompt_ui();
	get_str_input(username, sizeof(username));

	print_prompt_ui();
	get_str_input(full_name, sizeof(full_name));

	print_prompt_ui();
	voting_process_id = get_int_input();

	printf("add_candidate_controller: %s %s VPID(%d)\n", username, full_name, voting_process_id);
}

/**
 * vote_controller
 *
 * - calls vote ui
 * - voting process id is require for a registered voter to vote
 * - voter needs to be authenticated by entering their username and pin
 * - choose a candidate to vote for
 * - voter then has to confirm they are done with the voting process
 */
void vote_controller()
{
	vote_ui();
	char username[USER_NAME_SIZE] = {'\0'}, pin[PIN_SIZE] = {'\0'};
	int voting_process_id = 0, candidate_id = 0, confirmation = 0;

	print_prompt_ui();
	voting_process_id = get_int_input();

	print_prompt_ui();
	get_str_input(username, sizeof(username));

	print_prompt_ui();
	get_str_input(pin, sizeof(pin));

	print_prompt_ui();
	candidate_id = get_int_input();

	print_prompt_ui();
	confirmation = get_int_input();

	char support_text[15] = {'\0'};
	if (SUCCESS == confirmation)
	{
		strcpy(support_text, "voted");
	}
	else
	{
		strcpy(support_text, "did not vote");
	}

	printf("vote_controller: %s(%s) %s for candidate(%d) in the VPID(%d)\n",
		   username, pin, support_text, candidate_id, voting_process_id);
}

// 5. view voter's result (this is done by a voter)
void view_voters_result_controller()
{
	view_voters_result_ui();
	char username[USER_NAME_SIZE] = {'\0'}, pin[PIN_SIZE] = {'\0'};
	int voting_process_id = 0;

	print_prompt_ui();
	voting_process_id = get_int_input();

	print_prompt_ui();
	get_str_input(username, sizeof(username));

	print_prompt_ui();
	get_str_input(pin, sizeof(pin));

	printf("view_voters_result_controller: %s(%s) viewed result for VPID(%d)\n",
		   username, pin, voting_process_id);
}

// 6. end voting process
void end_voting_process_controller()
{
	// TODO: list the available voting processes available
	end_voting_process_ui();
	int voting_process_id = 0;

	print_prompt_ui();
	voting_process_id = get_int_input();

	printf("end_voting_process_controller: Admin is ending VPID(%d)\n",
		   voting_process_id);
}

// 7. view voting results
void view_voting_results_controller()
{
	// TODO: list the available voting processes available
	view_voting_results_ui();
	int voting_process_id = 0;

	print_prompt_ui();
	voting_process_id = get_int_input();

	printf("view_voting_results_controller: Admin is viewing results for VPID(%d)\n",
		   voting_process_id);
}

/**
 * view_list_voting_processes_controller
 *
 * - calls view_list_voting_processes_ui and list_voting_process_models
 */
void view_list_voting_processes_controller()
{
	view_list_voting_processes_ui();
	list_voting_process_models();
}

/**
 * view_registered_voter_controller
 *
 * - calls view_registered_voter_ui and read_registered_voter_model
 */
void view_registered_voter_controller()
{
	// view_list_voting_processes_ui();
	// list_voting_process_models();
}

/**
 * view_list_registered_voters_controller
 *
 * - calls view_list_registered_voters_header_ui and list_registered_voters_model
 */
void view_list_registered_voters_controller()
{

	// TODO: find a way to put this prompt in the UI
	printf("Enter voting process ID\n");

	print_prompt_ui();
	int voting_process_id = get_int_input();

	// TODO: check that the voting process exits

	view_list_registered_voters_header_ui();
	list_registered_voters_model(voting_process_id);
}