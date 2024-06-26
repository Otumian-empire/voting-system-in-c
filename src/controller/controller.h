#include "../ui/ui.h"
#include "../models/model.h"

#ifndef _controller_h
#define _controller_h

int start_app_controller();
void create_voting_process_controller();
void add_voter_controller();
void add_candidate_controller();
void vote_controller();
void view_voters_result_controller();
void end_voting_process_controller();
void view_voting_results_controller();
void view_list_voting_processes_controller();
void view_registered_voter_controller();
void view_list_registered_voters_controller();

#endif