#include "ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("===== %% TEST =====\n");
	int	printed1 = 0;
	int	printed2 = 0;

	printed1 = ft_printf(NULL);
	printed2 = printf(NULL);

	printf("%d\n", printed1);
	printf("%d\n", printed2);
}
