#include <octopos.h>

extern int main(int argc, char **argv);

void main_ilet(claim_t claim)
{
	(void) claim;

	/* We want to use uart redirection through grmon -u */
	leon_set_uart_debug_mode(1);

	main(0, NULL);
}
