/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:20:40 by donheo            #+#    #+#             */
/*   Updated: 2025/04/21 13:22:01 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	init_info(t_info *info)
{
	info->hash = -1;
	info->minus = -1;
	info->period = -1;
	info->plus = -1;
	info->space = -1;
	info->type = -1;
	info->zero = -1;
	info->width = 0;
	info->precision = 0;
}

int	process_zero(t_info *info, int index)
{
	if (info->period > -1)
		info->precision = info->precision * 10;
	else if (info->width)
		info->width = info->width * 10;
	else
		info->zero = index;
	return (1);
}

int	update_info(t_info *info, const char *format, int index)
{
	if (ft_strchr("0", format[index]))
		return (process_zero(info, index));
	else if (ft_strchr("-.# +", format[index]))
	{
		if (format[index] == '-')
			info->minus = index;
		else if (format[index] == '.')
			info->period = index;
		else if (format[index] == '#')
			info->hash = index;
		else if (format[index] == ' ')
			info->space = index;
		else if (format[index] == '+')
			info->plus = index;
		return (1);
	}
	else if (ft_strchr("123456789", format[index]))
	{
		if (info->period > -1)
			info->precision = (info->precision * 10) + (format[index] - '0');
		else
			info->width = (info->width * 10) + (format[index] - '0');
		return (1);
	}
	return (0);
}
