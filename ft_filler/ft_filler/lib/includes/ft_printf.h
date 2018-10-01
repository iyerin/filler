/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <iyerin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:44:40 by iyerin            #+#    #+#             */
/*   Updated: 2018/09/24 19:58:55 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include "./libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>

typedef struct	s_flags
{
	char		*text;
	char		minus;
	char		plus;
	char		hash;
	char		zero;
	char		space;
	size_t		width;
	int			precision;
	char		length;
	char		specs;
	char		negative;
	char		antispecs;
	char		charzero;
	char		zero_octal_hex;
	char		prec_zero;
	char		unicode;
}				t_flags;

int				ft_printf(const char *format, ...);
char			*ft_itoa_base(size_t value, size_t base);
int				ft_specifier_is_true (char format);
int				ft_parser(const char *format,
	t_flags **specs, ssize_t *bytes_counter);
void			ft_flag_conversion(char **str, t_flags *specs);
void			ft_l_s_conv(char **str, t_flags *specs,
	size_t base, size_t uni_var);
void			ft_l_u_conv(char **str, t_flags *specs,
	size_t base, size_t uni_var);
int				ft_arg_is_numeric(char format);
void			ft_width_conversion(char **str, t_flags *specs);
void			ft_precision_conv(char **str, t_flags *specs,
	ssize_t init_str_len);
void			ft_arg_s(va_list arg_list, t_flags *specs,
	char **str, wchar_t **unicode_str);
void			ft_arg_c(va_list arg_list, t_flags *specs,
	char **str, wchar_t *unicode_char);
void			ft_arg_d(va_list arg_list, t_flags *specs, char **str);
void			ft_arg_poxu(va_list arg_list, t_flags *specs, char **str);
void			ft_arg_xuoanti(va_list arg_list, t_flags *specs, char **str);
int				ft_print_unicode_str(wchar_t *unicode_str);
void			ft_unicode_conversion(wchar_t *unicode_str, t_flags *specs,
	ssize_t *bytes_counter);
int				ft_find_replace_null_decimal(char const *s);
int				ft_find_replace_null_char(char const *s);
char			*ft_str_to_upper(char *str);
int				ft_countchar(int value);
int				ft_countchar_unicode_str(wchar_t *unicode_str);
size_t			ft_uslen(wchar_t *unicode_str);
int				ft_find_replace_unicode(char const *s, wchar_t unicode_char);
wchar_t			*ft_unicode_precision(wchar_t *unicode_str, t_flags *specs);

#endif
