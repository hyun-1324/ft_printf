/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 12:17:42 by donheo            #+#    #+#             */
/*   Updated: 2025/04/21 13:21:57 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	put_space_or_zero_for_u(int printed_bytes, t_info *info)
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

int	putstr_n_for_u(char *s, int strlen, unsigned int u, t_info *info)
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

char	*fill_unsigned_str(unsigned int n, char *str, int len, int tmp)
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

char	*ft_utoa(unsigned int n, t_info *info)
{
	unsigned int	tmp;
	int				len;
	char			*str;

	tmp = n / 10;
	len = 1;
	while (tmp)
	{
		len++;
		tmp = tmp / 10;
	}
	if (info->precision > len)
	{
		str = (char *)malloc(info->precision + 1);
		tmp = info->precision - len;
	}
	else if (info->period != -1 && n == 0 && info->width == -1)
		return (NULL);
	else
		str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str = fill_unsigned_str(n, str, len, tmp);
	return (str);
}

int	print_u(t_info *info, va_list args)
{
	int				printed_bytes;
	int				strlen;
	unsigned int	i;
	char			*u;

	printed_bytes = 0;
	i = va_arg(args, unsigned int);
	u = ft_utoa(i, info);
	if (!u)
		return (0);
	strlen = ft_strlen(u);
	if (info->minus > -1)
	{
		printed_bytes += putstr_n_for_u(u, strlen, i, info);
		printed_bytes += put_space(strlen, info);
	}
	else
	{
		printed_bytes += put_space_or_zero_for_u(strlen, info);
		printed_bytes += putstr_n_for_u(u, strlen, i, info);
	}
	free(u);
	return (printed_bytes);
}
