#include "ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int printed1 = 0;
	int printed2 = 0;

	char ch = 'A';

	printf("===== %%c (char = 'A') TEST =====\n");

	printed1 = ft_printf("ft : [%c]\n", ch);
	printed2 = printf(   "lib: [%c]\n", ch);
	printf("-> Printed (basic): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%5c]\n", ch);
	printed2 = printf(   "lib: [%5c]\n", ch);
	printf("-> Printed (width=5): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%-5c]\n", ch);
	printed2 = printf(   "lib: [%-5c]\n", ch);
	printf("-> Printed (left-align width=5): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%-5c]\n", ch);
	printed2 = printf(   "lib: [%-5c]\n", ch);
	printf("-> Printed (left-align width=5): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%-5c]\n", ch);
	printed2 = printf(   "lib: [%-5c]\n", ch);
	printf("-> Printed (left-align width=5): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%-5c]\n", ch);
	printed2 = printf(   "lib: [%-5c]\n", ch);
	printf("-> Printed (left-align width=5): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%-5c]\n", ch);
	printed2 = printf(   "lib: [%-5c]\n", ch);
	printf("-> Printed (left-align width=5): ft_printf = %d, printf = %d\n\n", printed1, printed2);
	return (0);
}
