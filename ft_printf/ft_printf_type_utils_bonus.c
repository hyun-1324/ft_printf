/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:45:36 by donheo            #+#    #+#             */
/*   Updated: 2025/04/21 13:21:56 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	put_space_or_zero(int printed_bytes, t_info *info)
{
	int	count;

	count = 0;
	if (info->width > 0 && info->zero > -1)
	{
		while (printed_bytes + count < info->width)
		{
			write(1, "0", 1);
			count++;
		}
	}
	else if (info->width > 0)
	{
		while (printed_bytes + count < info->width)
		{
			write(1, " ", 1);
			count++;
		}
	}
	return (count);
}

int	putstr_n(char *s, int strlen)
{
	int	i;

	i = 0;
	while (s[i] && i < strlen)
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	put_zero(int strlen, t_info *info)
{
	int	i;
	int	printed_bytes;

	i = 0;
	printed_bytes = 0;
	if (info->precision > strlen)
		i = info->precision - strlen;
	while (i--)
	{
		write(1, "0", 1);
		printed_bytes++;
	}
	return (printed_bytes);
}

int	print_padding_space(t_info *info)
{
	int	padding;

	padding = 0;
	while (info->width > (padding + 1))
	{
		write(1, " ", 1);
		padding++;
	}
	return (padding);
}

int	put_space(int printed_bytes, t_info *info)
{
	int	count;

	count = 0;
	if (info->width > 0)
	{
		while (printed_bytes + count < info->width)
		{
			write(1, " ", 1);
			count++;
		}
	}
	return (count);
}
