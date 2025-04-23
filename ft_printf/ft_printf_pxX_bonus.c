/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pxX_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:01:07 by donheo            #+#    #+#             */
/*   Updated: 2025/04/23 16:48:48 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*change_deciaml_to_hexa(t_info *info, unsigned long p)
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
	if (info->type == 'p' && p == 0)
		return (ft_strdup("(nil)"));
	else if (p == 0)
		buffer[i--] = '0';
	while (p > 0)
	{
		buffer[i--] = base[p % 16];
		p /= 16;
	}
	str = ft_strdup(&buffer[i + 1]);
	return (str);
}

int	putstr_n_for_px(char *s, int strlen, t_info *info, int decimal)
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
	while (s[i] && i < strlen && !(decimal == 0 && info->period > -1 && \
		info->precision == 0 && (info->type == 'x' || info->type == 'X')))
		write(1, &s[i++], 1);
	return (i);
}

int	calculate_str_length(t_info *info, int strlen, unsigned long decimal)
{
	int	length;

	length = 0;
	if (info->type == 'p' && decimal != 0)
		length += 2;
	if (info->precision > strlen)
		length += info->precision;
	else
		length += strlen;
	return (length);
}

int	process_px(t_info *info, unsigned long decimal, char *str, int strlen)
{
	int	printed_bytes;

	printed_bytes = 0;
	if (info->minus > -1)
	{
		printed_bytes += put_hash(info, decimal);
		printed_bytes += put_zero_for_px_str(strlen, info);
		printed_bytes += putstr_n_for_px(str, strlen, info, decimal);
		printed_bytes += put_space(printed_bytes, info);
	}
	else
	{
		printed_bytes = calculate_str_length(info, strlen, decimal);
		printed_bytes = put_prefix(printed_bytes, info, decimal);
		printed_bytes += put_zero_for_px_str(strlen, info);
		printed_bytes += putstr_n_for_px(str, strlen, info, decimal);
	}
	return (printed_bytes);
}

int	print_px(t_info *info, va_list args)
{
	int				printed_bytes;
	int				strlen;
	unsigned long	decimal;
	char			*str;

	printed_bytes = 0;
	if (info->type == 'p')
		decimal = (unsigned long)va_arg(args, void *);
	else
		decimal = (unsigned long)va_arg(args, unsigned int);
	str = change_deciaml_to_hexa(info, decimal);
	strlen = ft_strlen(str);
	printed_bytes += process_px(info, decimal, str, strlen);
	free(str);
	return (printed_bytes);
}
