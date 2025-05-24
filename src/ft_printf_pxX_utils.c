/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pxX_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:36:16 by donheo            #+#    #+#             */
/*   Updated: 2025/05/24 17:22:57 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_hash(t_info *info, unsigned long p)
{
	int	printed_bytes;

	printed_bytes = 0;
	if (p != 0 && (info->hash > -1 || info->type == 'p'))
	{
		if (info->type == 'x' || info->type == 'p')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		printed_bytes = 2;
	}
	return (printed_bytes);
}

int	print_px_padding(int printed_bytes, t_info *info, unsigned long decimal, \
	int *count)
{
	while (printed_bytes + *count < info->width && info->period != -1 \
		&& decimal == 0)
	{
		write(1, " ", 1);
		(*count)++;
	}
	if (info->zero > -1 && info->period == -1)
	{
		*count += print_hash(info, decimal);
		while (printed_bytes + *count < info->width)
		{
			write(1, "0", 1);
			(*count)++;
		}
	}
	if (info->hash > -1)
		*count += 2;
	while (printed_bytes + *count < info->width)
	{
		write(1, " ", 1);
		(*count)++;
	}
	return (*count);
}

int	print_prefix_with_width(int printed_bytes, \
	t_info *info, unsigned long decimal)
{
	int	count;

	count = 0;
	print_px_padding(printed_bytes, info, decimal, &count);
	if (!(info->hash > -1 && info->zero > -1 && info->width > 0))
		count += print_hash(info, decimal);
	if (info->hash > -1)
		count -= 2;
	return (count);
}

int	print_prefix(int printed_bytes, t_info *info, unsigned long decimal)
{
	int	count;

	count = 0;
	if (info->width > 0)
		count += print_prefix_with_width(printed_bytes, info, decimal);
	else if ((info->width == 0 && info->type == 'p') || ((info->type == 'x' \
		|| info->type == 'X') && info->hash > -1))
		count += print_hash(info, decimal);
	return (count);
}

int	print_leading_zeros_px(int str_len, t_info *info)
{
	int	i;
	int	printed_bytes;

	i = 0;
	printed_bytes = 0;
	if (info->precision > str_len)
		i = info->precision - str_len;
	if (info->type != 'p')
	{
		while (i--)
		{
			write(1, "0", 1);
			printed_bytes++;
		}
	}
	return (printed_bytes);
}
