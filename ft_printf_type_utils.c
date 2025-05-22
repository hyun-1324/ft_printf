/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:45:36 by donheo            #+#    #+#             */
/*   Updated: 2025/05/22 15:56:20 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_zero(int strlen, t_info *info)
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

int	print_space(int printed_bytes, t_info *info)
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
