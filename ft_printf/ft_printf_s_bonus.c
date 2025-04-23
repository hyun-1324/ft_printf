/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:02:40 by donheo            #+#    #+#             */
/*   Updated: 2025/04/21 16:49:06 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	get_printable_strlen(char *s, t_info *info)
{
	int	strlen;

	strlen = 0;
	if (info->period == -1)
		strlen = ft_strlen(s);
	else
		while (info->precision > strlen && s[strlen])
			strlen++;
	return (strlen);
}

char	*process_null_s(char *s, t_info *info)
{
	if (s != NULL)
		return (s);
	if (info->period != -1 && info->precision < 6)
		return ("");
	else
		return ("(null)");
}

int	print_s(t_info *info, va_list args)
{
	int		printed_bytes;
	int		strlen;
	char	*s;

	printed_bytes = 0;
	s = va_arg(args, char *);
	s = process_null_s(s, info);
	strlen = get_printable_strlen(s, info);
	if (info->minus > -1)
	{
		printed_bytes += putstr_n(s, strlen);
		printed_bytes += put_space(printed_bytes, info);
	}
	else
	{
		printed_bytes += put_space(strlen, info);
		printed_bytes += putstr_n(s, strlen);
	}
	return (printed_bytes);
}
