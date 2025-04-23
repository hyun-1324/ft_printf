/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:30:46 by donheo            #+#    #+#             */
/*   Updated: 2025/04/21 13:21:45 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_percent(t_info *info)
{
	int	printed_bytes;

	printed_bytes = 0;
	if (info->minus > -1)
	{
		write(1, "%", 1);
		printed_bytes++;
	}
	else
	{
		write(1, "%", 1);
		printed_bytes++;
	}
	return (printed_bytes);
}
