#include "./controller/controller.h"
// #include "./models/model.h"

int main()
{

	// start the database connection
	create_connection();

	int start_option = start_app_controller();

	// 1. create a voting process
	// 2. add voters
	// 3. add candidates
	// 4. vote
	// 5. view voter's result (this is done by a voter)
	// 6. end voting process
	// 7. view voting results
	switch (start_option)
	{
	case VOTING_PROCESS:
		create_voting_process_controller();
		break;
	case ADD_VOTER:
		add_voter_controller();
		break;
	case ADD_CANDIDATE:
		add_candidate_controller();
		break;
	case VOTE:
		vote_controller();
		break;
	case VIEW_VOTERS_RESULT:
		view_voters_result_controller();
		break;
	case END_VOTING_PROCESS:
		end_voting_process_controller();
		break;
	case VIEW_VOTING_RESULTS:
		view_voting_results_controller();
		break;
	default:
		exit_with_error_message("Invalid option selected");
	}

	return 0;
}
