#include "ft_printf_bonus.h"
#include <stdio.h>

void	test_c()
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
}

void	test_s()
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
	printed1 = ft_printf("ft : [%10.4s]\n", null_str);
	printed2 = printf(   "lib: [%10.4s]\n", null_str);
	printf("-> Printed (NULL string): ft_printf = %d, printf = %d\n\n", printed1, printed2);
}
void	test_percent()
{
	printf("===== %% TEST =====\n");
	int	printed1 = 0;
	int	printed2 = 0;

	printed1 = ft_printf("%%k\n");
	printed2 = printf("%%k\n");
	printf("Printed_bytes for ft_printf(\"%%k\\n\"): %d\n", printed1);
	printf("Printed_bytes for printf(\"%%k\\n\"): %d\n\n", printed2);
}

void	test_u()
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

	val = 0;
	printed1 = ft_printf("ft : [%.0u]\n", val);
	printed2 = printf(   "lib: [%.0u]\n", val);
	printf("-> Printed (val=0, precision=0): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%5.0u]\n", val);
	printed2 = printf(   "lib: [%5.0u]\n", val);
	printf("-> Printed (val=0, width=5, precision=0): ft_printf = %d, printf = %d\n\n", printed1, printed2);
}

void	test_di()
{
	int printed1 = 0;
	int printed2 = 0;
	int val = 42;
	int neg_val = -42;

	printf("===== %%d TEST (val = 42, -42) =====\n");

	printed1 = ft_printf("ft : [%d]\n", val);
	printed2 = printf(   "lib: [%d]\n", val);
	printf("-> Printed (basic): ft = %d, lib = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%10d]\n", val);
	printed2 = printf(   "lib: [%10d]\n", val);
	printf("-> Printed (width=10): ft = %d, lib = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%-10d]\n", val);
	printed2 = printf(   "lib: [%-10d]\n", val);
	printf("-> Printed (left-align): ft = %d, lib = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%010d]\n", val);
	printed2 = printf(   "lib: [%010d]\n", val);
	printf("-> Printed (zero pad): ft = %d, lib = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%.5d]\n", val);
	printed2 = printf(   "lib: [%.5d]\n", val);
	printf("-> Printed (precision=5): ft = %d, lib = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%10.5d]\n", val);
	printed2 = printf(   "lib: [%10.5d]\n", val);
	printf("-> Printed (width=10, precision=5): ft = %d, lib = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%+d]\n", val);
	printed2 = printf(   "lib: [%+d]\n", val);
	printf("-> Printed (plus flag): ft = %d, lib = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [% d]\n", val);
	printed2 = printf(   "lib: [% d]\n", val);
	printf("-> Printed (space flag): ft = %d, lib = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%-10.5d]\n", neg_val);
	printed2 = printf(   "lib: [%-10.5d]\n", neg_val);
	printf("-> Printed (neg, width+prec): ft = %d, lib = %d\n\n", printed1, printed2);
}

void	test_p()
{
	int a = 123;
	void *ptr = &a;
	void *null_ptr = NULL;
	int printed1, printed2;

	printf("===== %%p TEST =====\n");

	printed1 = ft_printf("ft : [%p]\n", ptr);
	printed2 = printf(   "lib: [%p]\n", ptr);
	printf("-> Printed (basic): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%20p]\n", ptr);
	printed2 = printf(   "lib: [%20p]\n", ptr);
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

	printed1 = ft_printf("ft : [%20p]\n", null_ptr);
	printed2 = printf(   "lib: [%20p]\n", null_ptr);
	printf("-> Printed (NULL + width=20): ft_printf = %d, printf = %d\n\n", printed1, printed2);
}

void	test_xX()
{

	int printed1 = 0;
	int printed2 = 0;
	unsigned int val = 255;

	printf("===== %%x (val = 255) TEST =====\n");

	printed1 = ft_printf("ft : [%x]\n", val);
	printed2 = printf(   "lib: [%x]\n", val);
	printf("-> Printed (basic): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%8x]\n", val);
	printed2 = printf(   "lib: [%8x]\n", val);
	printf("-> Printed (width=8): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%-8x]\n", val);
	printed2 = printf(   "lib: [%-8x]\n", val);
	printf("-> Printed (left-align width=8): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%08x]\n", val);
	printed2 = printf(   "lib: [%08x]\n", val);
	printf("-> Printed (zero-padding width=8): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%.5x]\n", val);
	printed2 = printf(   "lib: [%.5x]\n", val);
	printf("-> Printed (precision=5): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%8.5x]\n", val);
	printed2 = printf(   "lib: [%8.5x]\n", val);
	printf("-> Printed (width=8, precision=5): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%-8.5x]\n", val);
	printed2 = printf(   "lib: [%-8.5x]\n", val);
	printf("-> Printed (left-align width=8, precision=5): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%#x]\n", val);
	printed2 = printf(   "lib: [%#x]\n", val);
	printf("-> Printed (prefix): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%#08x]\n", val);
	printed2 = printf(   "lib: [%#08x]\n", val);
	printf("-> Printed (prefix, zero-pad, width=8): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%#.5x]\n", val);
	printed2 = printf(   "lib: [%#.5x]\n", val);
	printf("-> Printed (prefix + precision=5): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%#8.8x]\n", val);
	printed2 = printf(   "lib: [%#8.8x]\n", val);
	printf("-> Printed (prefix + precision + width): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("ft : [%#8.7x]\n", val);
	printed2 = printf(   "lib: [%#8.7x]\n", val);
	printf("-> Printed (prefix + precision + width): ft_printf = %d, printf = %d\n\n", printed1, printed2);


	printed1 = ft_printf("ft : [%#8.6x]\n", val);
	printed2 = printf(   "lib: [%#8.6x]\n", val);
	printf("-> Printed (prefix + precision + width): ft_printf = %d, printf = %d\n\n", printed1, printed2);


	printed1 = ft_printf("ft : [%#8.5x]\n", val);
	printed2 = printf(   "lib: [%#8.5x]\n", val);
	printf("-> Printed (prefix + precision + width): ft_printf = %d, printf = %d\n\n", printed1, printed2);


	printed1 = ft_printf("ft : [%#8.4x]\n", val);
	printed2 = printf(   "lib: [%#8.4x]\n", val);
	printf("-> Printed (prefix + precision + width): ft_printf = %d, printf = %d\n\n", printed1, printed2);


	printed1 = ft_printf("ft : [%#8.3x]\n", val);
	printed2 = printf(   "lib: [%#8.3x]\n", val);
	printf("-> Printed (prefix + precision + width): ft_printf = %d, printf = %d\n\n", printed1, printed2);


	printed1 = ft_printf("ft : [%#8.2x]\n", val);
	printed2 = printf(   "lib: [%#8.2x]\n", val);
	printf("-> Printed (prefix + precision + width): ft_printf = %d, printf = %d\n\n", printed1, printed2);


	printed1 = ft_printf("ft : [%#8.1x]\n", val);
	printed2 = printf(   "lib: [%#8.1x]\n", val);
	printf("-> Printed (prefix + precision + width): ft_printf = %d, printf = %d\n\n", printed1, printed2);


	val = 0;

	printed1 = ft_printf("%#04x\n", val);
	printed2 = printf(   "%#04x\n", val);
	printf("-> Printed (val=0, prefix, zero-pad): ft_printf = %d, printf = %d\n\n", printed1, printed2);


	printed1 = ft_printf("%#02x\n", val);
	printed2 = printf(   "%#02x\n", val);
	printf("-> Printed (val=0, prefix, zero-pad): ft_printf = %d, printf = %d\n\n", printed1, printed2);


	printed1 = ft_printf("%#0x\n", val);
	printed2 = printf(   "%#0x\n", val);
	printf("-> Printed (val=0, prefix, zero-pad): ft_printf = %d, printf = %d\n\n", printed1, printed2);


	printed1 = ft_printf("%#04.5x\n", val);
	printed2 = printf(   "%#04.5x\n", val);
	printf("-> Printed (val=0, prefix, zero-pad): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("%#04.4x\n", val);
	printed2 = printf(   "%#04.4x\n", val);
	printf("-> Printed (val=0, prefix, zero-pad): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("%#04.3x\n", val);
	printed2 = printf(   "%#04.3x\n", val);
	printf("-> Printed (val=0, prefix, zero-pad): ft_printf = %d, printf = %d\n\n", printed1, printed2);

	printed1 = ft_printf("%#04.2x\n", val);
	printed2 = printf(   "%#04.2x\n", val);
	printf("-> Printed (val=0, prefix, zero-pad): ft_printf = %d, printf = %d\n\n", printed1, printed2);


	printed1 = ft_printf("%#04.1x\n", val);
	printed2 = printf(   "%#04.1x\n", val);
	printf("-> Printed (val=0, prefix, zero-pad): ft_printf = %d, printf = %d\n\n", printed1, printed2);


	printed1 = ft_printf("%#04.x\n", val);
	printed2 = printf(   "%#04.x\n", val);
	printf("-> Printed (val=0, prefix, zero-pad): ft_printf = %d, printf = %d\n\n", printed1, printed2);
}


int	main(void)
{
	test_c();
	test_s();
	test_percent();
	test_u();
	test_di();
	test_p();
	test_xX();
	return (0);
}
