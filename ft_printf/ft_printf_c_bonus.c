/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c _bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 08:24:38 by donheo            #+#    #+#             */
/*   Updated: 2025/04/17 22:58:26 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "./libft/libft.h"

int	print_c_b(t_info *info, va_list args)
{
	int				printed_bytes;
	unsigned char	c;

	printed_bytes = 0;
	c = (unsigned char)va_arg(args, int);
	if (info->minus > -1)
	{
		write(1, &c, 1);
		printed_bytes++;
		printed_bytes += print_padding_space_b(info);
	}
	else
	{
		printed_bytes += print_padding_space_b(info);
		write(1, &c, 1);
		printed_bytes++;
	}
	return (printed_bytes);
}
