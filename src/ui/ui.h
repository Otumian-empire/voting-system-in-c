#include <stdio.h>

// the min and max expected value for the start app options
#define UI_START_APP_OPTION_START 1
#define UI_START_APP_OPTION_END 7

#define UI_START_APP_OPTION_ERR_MESSAGE "invalid start option entered. expected: [%d, %d]", UI_START_APP_OPTION_START, UI_START_APP_OPTION_END

#define UI_INPUT_PROMPT "$ "

#ifndef _ui_h
#define _ui_h

void start_app_ui();
void create_voting_process_ui();
void add_voter_ui();
void add_candidate_ui();
void print_prompt_ui();

#endif
