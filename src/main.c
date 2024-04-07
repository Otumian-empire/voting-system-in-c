#include "./controller/controller.h"

int main()
{
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
	case 1:
		create_voting_process_controller();
		break;
	case 2:
		add_voter_controller();
		break;
	case 3:
		add_candidate_controller();
		break;
	case 4:
		vote_controller();
		break;
	case 5:
		view_voters_result_controller();
		break;
	case 6:
		end_voting_process_controller();
		break;
	case 7:
		view_voting_results_controller();
		break;
	default:
		exit_with_error_message("Invalid option selected");
	}

	return 0;
}
