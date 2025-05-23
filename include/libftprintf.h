/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:11:40 by donheo            #+#    #+#             */
/*   Updated: 2025/05/24 17:11:37 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

// Struct to store format specifier and flag information
typedef struct s_info
{
	char	type;
	int		minus;
	int		zero;
	int		period;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		precision;
}		t_info;

// Core helper functions for parsing and initialization
int		update_info(t_info *info, const char *format, int index);
int		process_zero(t_info *info, int index);
void	init_info(t_info *info);
int		ft_printf(const char *format, ...);

// Functions for printing each format specifier
int		print_c(t_info *info, va_list args);
int		print_s(t_info *info, va_list args);
int		print_u(t_info *info, va_list args);
int		print_di(t_info *info, va_list args);
int		print_px(t_info *info, va_list args);

// Helper functions for print_di
int		print_di_str(char *s, int strlen, t_info *info, int di);
int		compute_print_len_di(t_info *info, int strlen, int di);
int		count_digits(long n);
void	long_to_str(int n, char *str, int len);
char	*ft_itoa_for_long(long n);

// Helper functions for print_px
int		print_hash(t_info *info, unsigned long p);
int		print_px_padding(int printed_bytes, t_info *info, \
unsigned long decimal, int *count);
int		print_prefix_with_width(int printed_bytes, t_info *info, \
	unsigned long decimal);
int		print_prefix(int printed_bytes, t_info *info, unsigned long decimal);
int		print_leading_zeros_px(int strlen, t_info *info);

// Common utility functions for printing specifiers
int		print_space(int printed_bytes, t_info *info);
int		print_zero(int strlen, t_info *info);

#endif
