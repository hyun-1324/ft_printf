#include "ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{

	int	printed1 = 0;
	int	printed2 = 0;

	const char *str = "hello";

	printf("===== %%s (str = \"hello\") TEST =====\n");

	printed1 = ft_printf("ft : [%s]\n", str);
	printed2 = printf(   "lib: [%s]\n", str);
	printf("-> Printed (basic): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%10s]\n", str);
	printed2 = printf(   "lib: [%10s]\n", str);
	printf("-> Printed (width=10): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%-10s]\n", str);
	printed2 = printf(   "lib: [%-10s]\n", str);
	printf("-> Printed (left-align width=10): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%.3s]\n", str);
	printed2 = printf(   "lib: [%.3s]\n", str);
	printf("-> Printed (precision=3): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%10.3s]\n", str);
	printed2 = printf(   "lib: [%10.3s]\n", str);
	printf("-> Printed (width=10, precision=3): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%-10.3s]\n", str);
	printed2 = printf(   "lib: [%-10.3s]\n", str);
	printf("-> Printed (left-align width=10, precision=3): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	const char *null_str = NULL;
	printed1 = ft_printf("ft : [%s]\n", null_str);
	printed2 = printf(   "lib: [%s]\n", null_str);
	printf("-> Printed (NULL string): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	return (0);
}
