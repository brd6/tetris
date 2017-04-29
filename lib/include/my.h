/*
** my.h for my in /home/bongol_b/rendu/Piscine_C_workshoplib
**
** Made by berdrigue bongolo-beto
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Oct 16 01:09:57 2015 berdrigue bongolo-beto
** Last update Sat Mar 19 12:57:24 2016 Berdrigue BONGOLO BETO
*/

#ifndef MY_H_
# define MY_H_

char	*my_wordtab_search(char **, char *data, int (*cmp)());
void	my_strswap(char **a, char **b);
char	*my_strstr(char *str,char *to_find);
char	**my_str_split(char *str, char sp);
int	my_strncmp(char *s1,char *s2, int nb);
int	my_strlen(char *str);
int	my_str_isupper(char *str);
int	is_alpha(char c);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isalpha(char *str);
char	*my_strdup(char *src);
char	*my_strcpy(char* dest, char *src);
int	my_strcmp(char *s1,char *s2);
int	my_sort_wordtab(char **);
int	my_putstr(char *str);
int	my_put_nbr(int nb);
void	my_putchar(char c);
void	my_puterr(char *str);
int	my_nbr_len(int nbr);
char	*my_itoa(int nbr);
char	*my_getstr_value(char *str, char separator);
int	my_getnbr(char *str);
void	my_free_wordtab(char **);
int	is_num(char c);
char	*my_strcat(char *dest, char *src);
#endif /* !MY_H_ */
