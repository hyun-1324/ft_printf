#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int printed1 = 0;
	int printed2 = 0;

	printed1 = ft_printf("%.03s", NULL);
	printed2 = printf("%.03s", NULL);
	printf("%d, %d\n",printed1, printed2);

	return (0);
}
