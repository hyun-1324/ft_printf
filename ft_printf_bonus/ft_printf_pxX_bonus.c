/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pxX_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:01:07 by donheo            #+#    #+#             */
/*   Updated: 2025/04/17 23:27:23 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "./libft/libft.h"

int	putstr_n_for_px_b(char *s, int strlen, t_info *info, int decimal)
{
	int	i;

	i = 0;
	if (decimal == 0 && info->period > -1 && info->precision == 0 && \
		info->type == 'p')
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

int	calculate_str_length_b(t_info *info, int strlen, unsigned long decimal)
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

int	proce_px_b(t_info *info, unsigned long decimal, char *str, int strlen)
{
	int	printed_bytes;

	printed_bytes = 0;
	if (info->minus > -1)
	{
		printed_bytes += put_hash_b(info, decimal);
		printed_bytes += put_zero_for_px_str_b(strlen, info);
		printed_bytes += putstr_n_for_px_b(str, strlen, info, decimal);
		printed_bytes += put_space_b(printed_bytes, info);
	}
	else
	{
		printed_bytes = calculate_str_length_b(info, strlen, decimal);
		printed_bytes = put_prefix_b(printed_bytes, info, decimal);
		printed_bytes += put_zero_for_px_str_b(strlen, info);
		printed_bytes += putstr_n_for_px_b(str, strlen, info, decimal);
	}
	return (printed_bytes);
}

int	print_px_b(t_info *info, va_list args)
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
	str = change_deciaml_to_hexa_b(info, decimal);
	strlen = ft_strlen(str);
	printed_bytes += proce_px_b(info, decimal, str, strlen);
	free(str);
	return (printed_bytes);
}
