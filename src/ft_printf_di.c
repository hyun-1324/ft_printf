/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:37:27 by donheo            #+#    #+#             */
/*   Updated: 2025/05/24 17:22:53 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_sign_prefix(t_info *info, int di)
{
	int	printed_bytes;

	printed_bytes = 0;
	if (info->plus > -1)
	{
		if (di >= 0)
			write(1, "+", 1);
		else
			write(1, "-", 1);
		printed_bytes++;
	}
	else if (info->space > -1)
	{
		if (di >= 0)
			write(1, " ", 1);
		else
			write(1, "-", 1);
		printed_bytes++;
	}
	else if (di < 0)
	{
		write(1, "-", 1);
		printed_bytes++;
	}
	return (printed_bytes);
}

static int	print_prefix_with_padding(int printed_bytes, t_info *info, int di)
{
	char	pad;
	int		count;

	count = 0;
	if (info->zero > -1 && info->period == -1)
	{
		if (di >= 0)
			count += print_sign_prefix(info, di);
		else if (di < 0)
			print_sign_prefix(info, di);
		pad = '0';
	}
	else
		pad = ' ';
	while (printed_bytes + count < info->width)
	{
		write(1, &pad, 1);
		count++;
	}
	if (pad == ' ')
		count += print_sign_prefix(info, di);
	else if (di < 0)
		count++;
	return (count);
}

static int	print_sign_and_padding(int printed_bytes, t_info *info, int di)
{
	int		count;

	count = 0;
	if (info->width > 0)
		count += print_prefix_with_padding(printed_bytes, info, di);
	else if (info->plus > -1 || info->space > -1 || di < 0)
		count += print_sign_prefix(info, di);
	return (count);
}

static int	process_di(t_info *info, int di, int digit_len, char *str)
{
	int		printed_bytes;

	printed_bytes = 0;
	if (info->minus > -1)
	{
		printed_bytes += print_sign_prefix(info, di);
		printed_bytes += print_zero(digit_len, info);
		printed_bytes += print_di_str(str, digit_len, info, di);
		printed_bytes += print_space(printed_bytes, info);
	}
	else
	{
		printed_bytes = compute_print_len_di(info, digit_len, di);
		printed_bytes = print_sign_and_padding(printed_bytes, info, di);
		printed_bytes += print_zero(digit_len, info);
		printed_bytes += print_di_str(str, digit_len, info, di);
	}
	return (printed_bytes);
}

int	print_di(t_info *info, va_list args)
{
	int		printed_bytes;
	int		value;
	long	long_di;
	int		digit_len;
	char	*str;

	printed_bytes = 0;
	value = va_arg(args, int);
	long_di = (long)value;
	if (value < 0)
		str = ft_itoa_for_long(-long_di);
	else if (value == 0 && info->period > -1 && info->precision == 0 \
		&& info->width == -1)
		return (printed_bytes);
	else
		str = ft_itoa(value);
	digit_len = ft_strlen(str);
	printed_bytes = process_di(info, value, digit_len, str);
	free(str);
	return (printed_bytes);
}
