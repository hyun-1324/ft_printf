/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donheo <donheo@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 00:11:40 by donheo            #+#    #+#             */
/*   Updated: 2025/04/17 22:53:25 by donheo           ###   ########.fr       */
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

int		ft_printf_b(const char *format, ...);
int		parse_format_b(const char *format, va_list args);
int		init_parsing_b(const char *format, int *index, va_list args);
int		print_arg_b(t_info *info, va_list args);
int		update_info_b(t_info *info, const char *format, int index);
int		process_zero_b(t_info *info, int index);
void	init_info_b(t_info *info);
int		print_padding_space_b(t_info *info);
int		print_percent_b(t_info *info);
int		print_c_b(t_info *info, va_list args);
int		get_printable_strlen_b(char *s, t_info *info);
int		put_space_b(int printed_bytes, t_info *info);
int		putstr_n_b(char *s, int strlen);
int		print_s_b(t_info *info, va_list args);
char	*fill_unsigned_str_b(unsigned int n, char *str, int len, int tmp);
char	*ft_utoa_b(unsigned int n, t_info *info);
int		put_space_or_zero_b(int printed_bytes, t_info *info);
int		print_u_b(t_info *info, va_list args);
int		put_zero_b(int strlen, t_info *info);
int		put_sign_prefix_b(t_info *info, int di);
int		put_flag_prefix_b(int printed_bytes, t_info *info, int di);
int		putstr_n_for_di_b(char *s, int strlen, t_info *info, int di);
int		calculate_length_of_chars_for_di_b(t_info *info, int strlen, int di);
char	*ft_itoa_for_long_b(long n);
int		print_di_b(t_info *info, va_list args);
char	*change_deciaml_to_hexa_b(t_info *info, unsigned long p);
int		put_hash_b(t_info *info, unsigned long p);
int		put_prefix_width_b(int printed_bytes, t_info *info, \
	unsigned long decimal);
int		put_prefix_b(int printed_bytes, t_info *info, unsigned long decimal);
int		calculate_str_length_b(t_info *info, int strlen, unsigned long decimal);
int		put_zero_for_px_str_b(int strlen, t_info *info);
int		process_px_b(t_info *info, unsigned long decimal, char *str, int strlen);
int		print_px_b(t_info *info, va_list args);
#endif
