/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:08:58 by donheo            #+#    #+#             */
/*   Updated: 2025/04/17 22:58:15 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "./libft/libft.h"

int	print_arg_b(t_info *info, va_list args)
{
	int	printed_bytes;

	printed_bytes = 0;
	if (info->type == '%')
		printed_bytes = print_percent_b(info);
	else if (info->type == 'c')
		printed_bytes = print_c_b(info, args);
	else if (info->type == 's')
		printed_bytes = print_s_b(info, args);
	else if (info->type == 'u')
		printed_bytes = print_u_b(info, args);
	else if (info->type == 'd' || info->type == 'i')
		printed_bytes = print_di_b(info, args);
	else if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		printed_bytes = print_px_b(info, args);
	return (printed_bytes);
}

int	init_parsing_b(const char *format, int *index, va_list args)
{
	t_info	info;
	int		printed_bytes;

	printed_bytes = 0;
	init_info_b(&info);
	while (ft_strchr("-0.# +123456789", format[*index]))
	{
		update_info_b(&info, format, *index);
		(*index)++;
	}
	if (ft_strchr("cspdiuxX%", format[*index]))
	{
		info.type = format[*index];
		printed_bytes += print_arg_b(&info, args);
	}
	return (printed_bytes);
}

int	parse_format_b(const char *format, va_list args)
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
			printed_size += init_parsing_b(format, index_ptr, args);
		}
		else
			printed_size += write(1, &(format[index]), 1);
		index++;
	}
	return (printed_size);
}

int	ft_printf_b(const char *format, ...)
{
	va_list	args;
	int		printed_size;

	va_start(args, format);
	printed_size = parse_format_b(format, args);
	va_end(args);
	return (printed_size);
}
