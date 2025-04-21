/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:11:40 by donheo            #+#    #+#             */
/*   Updated: 2025/04/18 10:00:51 by donheo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

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

int		ft_printf(const char *format, ...);
int		parse_format(const char *format, va_list args);
int		init_parsing(const char *format, int *index, va_list args);
int		print_arg(t_info *info, va_list args);
int		update_info(t_info *info, const char *format, int index);
int		process_zero(t_info *info, int index);
void	init_info(t_info *info);
int		print_padding_space(t_info *info);
int		print_percent(t_info *info);
int		print_c(t_info *info, va_list args);
int		get_printable_strlen(char *s, t_info *info);
int		put_space(int printed_bytes, t_info *info);
int		putstr_n(char *s, int strlen);
int		print_s(t_info *info, va_list args);
char	*fill_unsigned_str(unsigned int n, char *str, int len, int tmp);
char	*ft_utoa(unsigned int n, t_info *info);
int		put_space_or_zero(int printed_bytes, t_info *info);
int		print_u(t_info *info, va_list args);
int		put_zero(int strlen, t_info *info);
int		put_sign_prefix(t_info *info, int di);
int		put_flag_prefix(int printed_bytes, t_info *info, int di);
int		putstr_n_for_di(char *s, int strlen, t_info *info, int di);
int		calculate_length_of_chars_for_di(t_info *info, int strlen, int di);
char	*ft_itoa_for_long(long n);
int		print_di(t_info *info, va_list args);
char	*change_deciaml_to_hexa(t_info *info, unsigned long p);
int		put_hash(t_info *info, unsigned long p);
int		put_prefix_width(int printed_bytes, t_info *info, \
	unsigned long decimal);
int		put_prefix(int printed_bytes, t_info *info, unsigned long decimal);
int		calculate_str_length(t_info *info, int strlen, unsigned long decimal);
int		put_zero_for_px_str(int strlen, t_info *info);
int		process_px(t_info *info, unsigned long decimal, char *str, int strlen);
int		print_px(t_info *info, va_list args);
#endif
