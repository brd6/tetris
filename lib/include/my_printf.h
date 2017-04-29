/*
** my_printf.h for my_printf in /home/bongol_b/rendu/PSU_2015_my_printf
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Nov  2 09:06:00 2015 berdrigue bongolo-beto
** Last update Sat Mar 12 14:11:33 2016 Berdrigue BONGOLO BETO
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

# include <stdarg.h>

typedef	struct	s_pf_format
{
  char		flags[3];
  char		*field_width;
  char		*precision;
  char		length_modifier;
  char		conv_char;
}		t_pf_format;

typedef	struct	s_printf
{
  char		*type;
  int		(*func)(va_list ap, t_pf_format *format);
}		t_printf;

void		reset_len_p(t_pf_format *ptf_format, int *width, int *);
int		my_putnbr_base_x(long nbr, char *base);
int		prt_cond2(int width, int len_p, char *str, t_pf_format *ptf_f);
int		prt_cond(int width, int len_p, char *str, t_pf_format *ptf_f);
int		my_atoi_x(char *nbr);
int		my_putnstr_x(char *str, int n);
void		check_width_and_precision2(int *, int *, char *, t_pf_format *);
void		check_width_and_precision(int *wd, int *lp, int, t_pf_format *);
int		set_prec_len(int *len, t_pf_format *ptf_format, va_list ap);
void		nbr_limit_check(int *nbr, long *nbr2, int *sign);
void		nbr_space_handler(t_pf_format *ptf_f, int nbr, int *cp);
int		print_nchar(char c, int n);
void		check_width(int *width, int cp);
void		set_width(int *width, t_pf_format *ptf_format, va_list ap);
char		*my_strcpy_x(char *dest, char *src);
int		my_strlen_x(char *str);
int		check_format(char *str);
void		skip_space(char *str, int *i);
int		check_next_char(char *format);
int		my_get_char_pos_x(char *str, char c);
int		my_putchar_x(char c);
int		my_putstr_x(char *str);
char		*my_strdup_x(char *src);
int		my_put_nbr_x(int nb);
int		my_nbr_len_x(long nbr);
int		my_putnbr_x(long nb);
char		*convert_base_x(char *nbr, char *base_from, char *base_to);
long		my_getnbr_base_x(char *str, char *base);
char		*my_revstr_x(char *str);
char		*my_itoa_x(long nbr);
int		my_printf(char *format, ...);
void		init_flags(char flag, int *flag_cp, t_pf_format *, int *);
void		init_struct(t_printf *, char *, int (*func)(va_list,
							    t_pf_format *));
void		init_ptf_format(char *format, int *i, t_pf_format *, int *);
int		is_alpha_x(char c, int flag);
int		is_num_x(char c, int flag);
int		cp_str_nbr(char *format, int start);
char		*get_str_nbr(char *format, int *i);
int		print_char(va_list ap, t_pf_format *format);
int		print_nbr(va_list ap, t_pf_format *format);
int		print_str(va_list ap, t_pf_format *format);
int		print_nil(va_list ap, t_pf_format *format);
int		print_percent(va_list ap, t_pf_format *format);
int		print_octal(va_list ap, t_pf_format *format);
int		print_unsigned_nbr(va_list ap, t_pf_format *format);
int		print_hexa(va_list ap, t_pf_format *format);
int		print_pointer(va_list ap, t_pf_format *format);
int		print_ncount(va_list ap, t_pf_format *format);
int		print_binary(va_list ap, t_pf_format *format);
int		print_str2(va_list ap, t_pf_format *format);
#endif /* !MY_PRINTF_H_ */
