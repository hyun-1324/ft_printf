/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:02:40 by donheo            #+#    #+#             */
/*   Updated: 2025/05/22 15:00:28 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_print_len(char *s, t_info *info)
{
	int	print_len;

	print_len = 0;
	if (info->period == -1)
		print_len = ft_strlen(s);
	else
		while (info->precision > print_len && s[print_len])
			print_len++;
	return (print_len);
}

static char	*handle_null_string(char *s, t_info *info)
{
	if (s != NULL)
		return (s);
	if (info->period != -1 && info->precision < 6)
		return ("");
	else
		return ("(null)");
}

static int	write_n_chars(char *s, int print_len)
{
	int	i;

	i = 0;
	while (s[i] && i < print_len)
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	print_s(t_info *info, va_list args)
{
	int		printed_bytes;
	int		print_len;
	char	*s;

	printed_bytes = 0;
	s = va_arg(args, char *);
	s = handle_null_string(s, info);
	print_len = get_print_len(s, info);
	if (info->minus > -1)
	{
		printed_bytes += write_n_chars(s, print_len);
		printed_bytes += put_space(printed_bytes, info);
	}
	else
	{
		printed_bytes += put_space(print_len, info);
		printed_bytes += write_n_chars(s, print_len);
	}
	return (printed_bytes);
}
