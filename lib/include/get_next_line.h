/*
** get_next_line.h for get_next_line in /home/bongol_b/rendu/PSU_2015_minishell1/lib/my/include
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Jan 15 16:31:14 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 12 13:44:58 2016 Berdrigue BONGOLO BETO
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (1024)
# endif /* !READ_SIZE */

typedef struct		s_read_line
{
  int			end;
  int			start;
  int			fd;
  int			res;
  char			buffer[READ_SIZE + 1];
  int			read_again;
}			t_read_line;

char		*get_next_line(const int fd);
char		*get_next_line2(const int fd);
#endif /* !GET_NEXT_LINE_H_ */
