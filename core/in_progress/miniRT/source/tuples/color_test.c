#include "../../include/colors.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	t_color c = {0.1, 0.2, 0.3};

	printf("%f %f %f\n", c.red, c.green, c.blue);
	c = 2 * c;
	printf("%f %f %f\n", c.red, c.green, c.blue);
	return 0;
}
