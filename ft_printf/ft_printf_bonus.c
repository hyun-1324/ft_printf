/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:08:58 by donheo            #+#    #+#             */
/*   Updated: 2025/04/21 15:49:38 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_arg(t_info *info, va_list args)
{
	int	printed_bytes;

	printed_bytes = 0;
	if (info->type == '%')
		printed_bytes = print_percent(info);
	else if (info->type == 'c')
		printed_bytes = print_c(info, args);
	else if (info->type == 's')
		printed_bytes = print_s(info, args);
	else if (info->type == 'u')
		printed_bytes = print_u(info, args);
	else if (info->type == 'd' || info->type == 'i')
		printed_bytes = print_di(info, args);
	else if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		printed_bytes = print_px(info, args);
	return (printed_bytes);
}

int	init_parsing(const char *format, int *index, va_list args)
{
	t_info	info;
	int		printed_bytes;

	printed_bytes = 0;
	init_info(&info);
	while (ft_strchr("-0.# +123456789", format[*index]))
	{
		update_info(&info, format, *index);
		(*index)++;
	}
	if (ft_strchr("cspdiuxX%", format[*index]))
	{
		info.type = format[*index];
		printed_bytes += print_arg(&info, args);
	}
	return (printed_bytes);
}

int	parse_format(const char *format, va_list args)
{
	int	printed_size;
	int	index;
	int	*index_ptr;

	printed_size = 0;
	index = 0;
	index_ptr = &index;
	while (format[index])
	{
		if (format[index] == '%')
		{
			index++;
			printed_size += init_parsing(format, index_ptr, args);
		}
		else
			printed_size += write(1, &(format[index]), 1);
		index++;
	}
	return (printed_size);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_size;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	printed_size = parse_format(format, args);
	va_end(args);
	return (printed_size);
}
