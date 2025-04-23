#include "ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int a = 123;
	void *ptr = &a;
	void *null_ptr = NULL;
	int printed1, printed2;

	printf("===== %%p TEST =====\n");

	printed1 = ft_printf("ft : [%p]\n", ptr);
	printed2 = printf(   "lib: [%p]\n", ptr);
	printf("-> Printed (basic): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("%20pk\n", ptr);
	printed2 = printf(   "%20pk\n", ptr);
	printf("-> Printed (width=20): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%-20p]\n", ptr);
	printed2 = printf(   "lib: [%-20p]\n", ptr);
	printf("-> Printed (left-align width=20): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%p]\n", null_ptr);
	printed2 = printf(   "lib: [%p]\n", null_ptr);
	printf("-> Printed (NULL pointer): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%3p]\n", null_ptr);
	printed2 = printf(   "lib: [%3p]\n", null_ptr);
	printf("-> Printed (NULL pointer): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("%20pk\n", null_ptr);
	printed2 = printf(   "%20pk\n", null_ptr);
	printf("-> Printed (NULL + width=20): ft_printf = %d, printf = %d\n\n", printed1, printed2);
	return (0);
}
