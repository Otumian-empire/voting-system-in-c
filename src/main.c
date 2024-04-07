#include <stdlib.h>
#include "./ui/ui.h"
#include "./include/include.h"

int main()
{
	start_app();
	int start_option = get_int_input();
	if (!validate_input(start_option, UI_START_APP_OPTION_START, UI_START_APP_OPTION_END))
	{
		printf(UI_START_APP_OPTION_ERR_MESSAGE);
		exit(0);
	}

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
		printf("1. create a voting process\n");
		break;
	case 2:
		printf("2. add voters\n");
		break;
	case 3:
		printf("3. add candidates\n");
		break;
	case 4:
		printf("4. vote\n");
		break;
	case 5:
		printf("5. view voter's result\n");
		break;
	case 6:
		printf("6. end voting process\n");
		break;
	case 7:
		printf("7. view voting results\n");
		break;
	default:
		printf(UI_START_APP_OPTION_ERR_MESSAGE);
		exit(0);
	}

	return 0;
}
