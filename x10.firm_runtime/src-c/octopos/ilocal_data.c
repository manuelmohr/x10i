#include "ilocal_data.h"

void initialize_magic_number(void)
{
	ilocal_data_t *ilocal = get_ilocal_data();
	ilocal->magic = 0xDEADC0DE;
}

int check_magic_number(void)
{
	ilocal_data_t *ilocal = get_ilocal_data();
	return ilocal->magic == 0xDEADC0DE;
}
