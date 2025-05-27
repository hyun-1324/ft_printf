/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pxX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:01:07 by donheo            #+#    #+#             */
/*   Updated: 2025/05/24 17:23:01 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*change_decimal_to_hexa(t_info *info, unsigned long decimal)
{
	const char	*base;
	char		buffer[9];
	char		*str;
	int			i;

	i = 8;
	if (info->type == 'p' || info->type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	buffer[i--] = '\0';
	if (info->type == 'p' && decimal == 0)
		return (ft_strdup("(nil)"));
	else if (decimal == 0)
		buffer[i--] = '0';
	while (decimal > 0)
	{
		buffer[i--] = base[decimal % 16];
		decimal /= 16;
	}
	str = ft_strdup(&buffer[i + 1]);
	return (str);
}

static int	print_px_str(char *s, int str_len, t_info *info, int decimal)
{
	int	i;

	i = 0;
	if (decimal == 0 && info->period > -1 && info->precision \
		== 0 && info->type == 'p')
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
		return (i);
	}
	else if (decimal == 0 && info->period > -1 && info->precision == 0 \
		&& info->width > 0)
	{
		write(1, " ", 1);
		i++;
		return (i);
	}
	while (s[i] && i < str_len && !(decimal == 0 && info->period > -1 && \
		info->precision == 0 && (info->type == 'x' || info->type == 'X')))
		write(1, &s[i++], 1);
	return (i);
}

static int	compute_px_output_len(t_info *info, \
	int str_len, unsigned long decimal)
{
	int	length;

	length = 0;
	if (info->type == 'p' && decimal != 0)
		length += 2;
	if (info->precision > str_len)
		length += info->precision;
	else
		length += str_len;
	return (length);
}

static int	process_px(t_info *info, unsigned long decimal, \
	char *str, int str_len)
{
	int	printed_bytes;

	printed_bytes = 0;
	if (info->minus > -1)
	{
		printed_bytes += print_hash(info, decimal);
		printed_bytes += print_leading_zeros_px(str_len, info);
		printed_bytes += print_px_str(str, str_len, info, decimal);
		printed_bytes += print_space(printed_bytes, info);
	}
	else
	{
		printed_bytes = compute_px_output_len(info, str_len, decimal);
		printed_bytes = print_prefix(printed_bytes, info, decimal);
		printed_bytes += print_leading_zeros_px(str_len, info);
		printed_bytes += print_px_str(str, str_len, info, decimal);
	}
	return (printed_bytes);
}

int	print_px(t_info *info, va_list args)
{
	int				printed_bytes;
	int				str_len;
	unsigned long	decimal;
	char			*str;

	printed_bytes = 0;
	if (info->type == 'p')
		decimal = (unsigned long)va_arg(args, void *);
	else
		decimal = (unsigned long)va_arg(args, unsigned int);
	str = change_decimal_to_hexa(info, decimal);
	str_len = ft_strlen(str);
	printed_bytes += process_px(info, decimal, str, str_len);
	free(str);
	return (printed_bytes);
}
