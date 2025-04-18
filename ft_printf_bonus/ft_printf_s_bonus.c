/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:02:40 by donheo            #+#    #+#             */
/*   Updated: 2025/04/17 23:02:46 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "./libft/libft.h"

int	get_printable_strlen_b(char *s, t_info *info)
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

int	put_space_b(int printed_bytes, t_info *info)
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

int	print_s_b(t_info *info, va_list args)
{
	int		printed_bytes;
	int		strlen;
	char	*s;

	printed_bytes = 0;
	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	strlen = get_printable_strlen_b(s, info);
	if (info->minus > -1)
	{
		printed_bytes += putstr_n_b(s, strlen);
		printed_bytes += put_space_b(printed_bytes, info);
	}
	else
	{
		printed_bytes += put_space_b(strlen, info);
		printed_bytes += putstr_n_b(s, strlen);
	}
	return (printed_bytes);
}
