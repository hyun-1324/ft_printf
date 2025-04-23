/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pxX_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:36:16 by donheo            #+#    #+#             */
/*   Updated: 2025/04/23 16:48:51 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	put_hash(t_info *info, unsigned long p)
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

int	put_zero_and_space(int printed_bytes, t_info *info, unsigned long decimal, \
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
		*count += put_hash(info, decimal);
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

int	put_prefix_width(int printed_bytes, t_info *info, unsigned long decimal)
{
	int	count;

	count = 0;
	put_zero_and_space(printed_bytes, info, decimal, &count);
	if (!(info->hash > -1 && info->zero > -1 && info->width > 0))
		count += put_hash(info, decimal);
	if (info->hash > -1)
		count -= 2;
	return (count);
}

int	put_prefix(int printed_bytes, t_info *info, unsigned long decimal)
{
	int	count;

	count = 0;
	if (info->width > 0)
		count += put_prefix_width(printed_bytes, info, decimal);
	else if ((info->width == 0 && info->type == 'p') || ((info->type == 'x' \
		|| info->type == 'X') && info->hash > -1))
		count += put_hash(info, decimal);
	return (count);
}

int	put_zero_for_px_str(int strlen, t_info *info)
{
	int	i;
	int	printed_bytes;

	i = 0;
	printed_bytes = 0;
	if (info->precision > strlen)
		i = info->precision - strlen;
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
