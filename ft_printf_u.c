/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:17:42 by donheo            #+#    #+#             */
/*   Updated: 2025/05/22 15:29:29 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_u_padding(int printed_bytes, t_info *info)
{
	int	count;

	count = 0;
	if (info->zero > -1 && info->width > 0 && info->period == -1)
	{
		while (printed_bytes + count < info->width)
		{
			write(1, "0", 1);
			count++;
		}
	}
	else if ((info->precision > 0 && info->zero > -1) || info->width > 0)
	{
		while (printed_bytes + count < info->width)
		{
			write(1, " ", 1);
			count++;
		}
	}
	return (count);
}

static int	write_u_formatted(char *s, int strlen, unsigned int u, t_info *info)
{
	int	i;

	i = 0;
	if ((u == 0 && info->width > 0 && info->period != -1 && \
		info->precision == 0 && info->zero > -1) || (u == 0 && \
		info->period == -1 && info->width == 0))
	{
		write(1, "0", 1);
		return (++i);
	}
	else if (u == 0 && info->width > 0 && info->period != -1 \
		&& info->precision == 0)
	{
		write(1, " ", 1);
		return (++i);
	}
	else if (u == 0 && info->period != -1 && info->precision == 0 \
		&& info->width == 0)
		return (i);
	while (s[i] && i < strlen)
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

static char	*fill_u_str_with_zeros(unsigned int n, char *str, int len, int tmp)
{
	str[len + tmp] = '\0';
	while (len--)
	{
		str[len + tmp] = '0' + (n % 10);
		n /= 10;
	}
	while (tmp--)
		str[tmp] = '0';
	return (str);
}

static char	*ft_utoa(unsigned int n, t_info *info)
{
	unsigned int	leading_zero;
	int				digit_len;
	char			*str;

	leading_zero = n / 10;
	digit_len = 1;
	while (leading_zero)
	{
		digit_len++;
		leading_zero = leading_zero / 10;
	}
	if (info->precision > digit_len)
	{
		str = (char *)malloc(info->precision + 1);
		leading_zero = info->precision - digit_len;
	}
	else if (info->period != -1 && n == 0 && info->width == -1)
		return (NULL);
	else
		str = (char *)malloc(digit_len + 1);
	if (!str)
		return (NULL);
	str = fill_u_str_with_zeros(n, str, digit_len, leading_zero);
	return (str);
}

int	print_u(t_info *info, va_list args)
{
	int				printed_bytes;
	int				print_len;
	unsigned int	value;
	char			*u;

	printed_bytes = 0;
	value = va_arg(args, unsigned int);
	u = ft_utoa(value, info);
	if (!u)
		return (0);
	print_len = ft_strlen(u);
	if (info->minus > -1)
	{
		printed_bytes += write_u_formatted(u, print_len, value, info);
		printed_bytes += put_space(print_len, info);
	}
	else
	{
		printed_bytes += print_u_padding(print_len, info);
		printed_bytes += write_u_formatted(u, print_len, value, info);
	}
	free(u);
	return (printed_bytes);
}
