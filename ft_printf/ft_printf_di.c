/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:37:27 by donheo            #+#    #+#             */
/*   Updated: 2025/04/09 09:44:38 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	put_sign_prefix(t_info *info, int di)
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

int	put_flag_prefix_with_width(int printed_bytes, t_info *info, int di)
{
	char	pad;
	int		count;

	count = 0;
	if (info->zero > -1 && info->period == -1)
	{
		if (di >= 0)
			count += put_sign_prefix(info, di);
		else if (di < 0)
			put_sign_prefix(info, di);
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
		count += put_sign_prefix(info, di);
	else if (di < 0)
		count++;
	return (count);
}

int	put_flag_prefix(int printed_bytes, t_info *info, int di)
{
	int		count;

	count = 0;
	if (info->width > 0)
		count += put_flag_prefix_with_width(printed_bytes, info, di);
	else if (info->plus > -1 || info->space > -1 || di < 0)
		count += put_sign_prefix(info, di);
	return (count);
}

int	process_di(t_info *info, int di, int strlen, char *str)
{
	int		printed_bytes;

	printed_bytes = 0;
	if (info->minus > -1)
	{
		printed_bytes += put_sign_prefix(info, di);
		printed_bytes += put_zero(strlen, info);
		printed_bytes += putstr_n_for_di(str, strlen, info, di);
		printed_bytes += put_space(printed_bytes, info);
	}
	else
	{
		printed_bytes = calculate_length_of_chars_for_di(info, strlen, di);
		printed_bytes = put_flag_prefix(printed_bytes, info, di);
		printed_bytes += put_zero(strlen, info);
		printed_bytes += putstr_n_for_di(str, strlen, info, di);
	}
	return (printed_bytes);
}

int	print_di(t_info *info, va_list args)
{
	int		printed_bytes;
	long	di;
	int		strlen;
	char	*str;

	printed_bytes = 0;
	di = (long)va_arg(args, int);
	if (di < 0)
		str = ft_itoa_for_long(-di);
	else if (di == 0 && info->period > -1 && info->precision == 0 \
		&& info->width == -1)
		return (printed_bytes);
	else
		str = ft_itoa(di);
	strlen = ft_strlen(str);
	printed_bytes = process_di(info, di, strlen, str);
	free(str);
	return (printed_bytes);
}
