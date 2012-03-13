#include <octopos.h>

extern int main(int argc, char **argv);

void main_ilet(claim_t claim)
{
	(void) claim;
	main(0, NULL);
}
