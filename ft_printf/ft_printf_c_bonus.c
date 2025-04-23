/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 08:24:38 by donheo            #+#    #+#             */
/*   Updated: 2025/04/21 13:21:34 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_c(t_info *info, va_list args)
{
	int				printed_bytes;
	unsigned char	c;

	printed_bytes = 0;
	c = (unsigned char)va_arg(args, int);
	if (info->minus > -1)
	{
		write(1, &c, 1);
		printed_bytes++;
		printed_bytes += print_padding_space(info);
	}
	else
	{
		printed_bytes += print_padding_space(info);
		write(1, &c, 1);
		printed_bytes++;
	}
	return (printed_bytes);
}
