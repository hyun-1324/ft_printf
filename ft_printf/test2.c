#include "ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int printed1 = 0;
	int printed2 = 0;
	unsigned int val = 123;

	printf("===== %%u (val = 123) TEST =====\n");

	printed1 = ft_printf("ft : [%u]\n", val);
	printed2 = printf(   "lib: [%u]\n", val);
	printf("-> Printed (basic): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%08u]\n", val);
	printed2 = printf(   "lib: [%08u]\n", val);
	printf("-> Printed (width=8, zero-padding): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%-8u]\n", val);
	printed2 = printf(   "lib: [%-8u]\n", val);
	printf("-> Printed (left-align width=8): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%.5u]\n", val);
	printed2 = printf(   "lib: [%.5u]\n", val);
	printf("-> Printed (precision=5): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%-8.5u]\n", val);
	printed2 = printf(   "lib: [%-8.5u]\n", val);
	printf("-> Printed (left-align width=8, precision=5): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%8.5u]\n", val);
	printed2 = printf(   "lib: [%8.5u]\n", val);
	printf("-> Printed (width=8, precision=5): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	val = 0;
	printed1 = ft_printf("ft : [%.0u]\n", val);
	printed2 = printf(   "lib: [%.0u]\n", val);
	printf("-> Printed (val=0, precision=0): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%5.0u]\n", val);
	printed2 = printf(   "lib: [%5.0u]\n", val);
	printf("-> Printed (val=0, width=5, precision=0): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%5.1u]\n", val);
	printed2 = printf(   "lib: [%5.1u]\n", val);
	printf("-> Printed (val=0, width=5, precision=0): ft_printf = %d, printf = %d\n\n", printed1, printed2);
}
