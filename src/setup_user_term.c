/*
** setup_user_term.c for setup_user_term in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Mar  4 14:00:09 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 20 15:12:52 2016 Berdrigue BONGOLO BETO
*/

#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "tetris.h"

void		print_term_touch(char *title, char *term_touch)
{
  int		i;
  int		is_space;

  i = 0;
  is_space = 0;
  my_printf("%s : ", title);
  while (term_touch[i])
    {
      if (term_touch[i] == ' ' && is_space == 0)
	is_space = 1;
      else if (term_touch[i] != ' ')
	is_space = 0;
      if (term_touch[i] == 27)
      	my_putstr("^E");
      else if (is_space == 0)
	my_putchar(term_touch[i]);
      i++;
    }
  if (is_space)
    my_putstr("(space)");
  my_putchar('\n');
}

char			*my_getch()
{
  char			*buff;
  int			ret;

  if ((buff = malloc(sizeof(*buff) * 256)) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 256)) < 1)
    return (NULL);
  buff[ret] = 0;
  return (buff);
}

char			*my_getch2()
{
  char			*s;
  struct termios	term;

  if (ioctl(STDIN_FILENO, TCGETS, &term) == -1)
    return (NULL);
  term.c_lflag &= ~ICANON;
  term.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL);
  term.c_cc[VMIN] = 1;
  term.c_cc[VTIME] = 0;
  if (ioctl(STDIN_FILENO, TCSETS, &term) == -1)
    return (NULL);
  s = tigetstr("smkx");
  if (s == NULL)
    return (0);
  putp(s);
  return (my_getch());
}

int		set_term_mode(int flag)
{
  struct termios	term;
  char			*s;

  if (flag)
    {
      if (ioctl(STDIN_FILENO, TCGETS, &term) == -1)
      	return (my_putstr(TERM_SETUP_FAIL), 0);
      term.c_lflag &= ~ICANON;
      term.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL);
      term.c_cc[VMIN] = 0;
      term.c_cc[VTIME] = 0;
      if (ioctl(STDIN_FILENO, TCSETS, &term) == -1)
      	return (my_putstr(TERM_SETUP_FAIL), 0);
      s = tigetstr("smkx");
      if (s == NULL)
	return (0);
      putp(s);
    }
  if (flag == 0)
    {
      if (ioctl(STDIN_FILENO, TCSETS, &g_tetris.user_term) == -1)
      	return (my_putstr(TERM_SETUP_FAIL), 0);
    }
  return (1);
}
