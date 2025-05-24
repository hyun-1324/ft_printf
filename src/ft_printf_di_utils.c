/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:26:19 by donheo            #+#    #+#             */
/*   Updated: 2025/05/24 17:22:48 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_di_str(char *s, int strlen, t_info *info, int di)
{
	int	i;

	i = 0;
	if (di == 0 && info->period > -1 && info->precision == 0 && info->width > 0)
	{
		write(1, " ", 1);
		i++;
		return (i);
	}
	else if (di == 0 && info->period > -1 && info->precision == 0 \
				&& info->width == 0)
	{
		return (i);
	}
	while (s[i] && i < strlen)
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	compute_print_len_di(t_info *info, int strlen, int di)
{
	int	printed_bytes;

	printed_bytes = 0;
	if (di < 0)
		printed_bytes++;
	if (info->plus > -1 || info->space > -1)
		printed_bytes++;
	if (info->precision > strlen)
		printed_bytes += info->precision;
	else
		printed_bytes += strlen;
	return (printed_bytes);
}

int	count_digits(long n)
{
	int		len;
	long	num;

	num = n;
	if (num == 0)
		return (1);
	len = 0;
	if (num < 0)
	{
		len++;
		num *= (-1);
	}
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

void	long_to_str(int n, char *str, int len)
{
	long	num;

	str[len] = '\0';
	num = n;
	if (num < 0)
	{
		str[0] = '-';
		num *= (-1);
	}
	else if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa_for_long(long n)
{
	int		len;
	char	*str;

	len = count_digits(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	long_to_str(n, str, len);
	return (str);
}
