/*
** utils2.c for utils2 in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Mar 19 14:53:10 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 20 12:10:49 2016 Berdrigue BONGOLO BETO
*/

#include <time.h>
#include <stdlib.h>
#include "my.h"
#include "tetris.h"

int		print_err_msg(char *msg, int code_return)
{
  my_puterr(msg);
  return (code_return);
}

char	*concat_rep_str(char *str1, char *str2)
{
  char	*tmp;

  tmp = malloc(my_strlen(str1) + my_strlen(str2) + 2);
  if (tmp == NULL)
    return (0);
  tmp[0] = 0;
  if (str1[my_strlen(str1) - 1] != '/')
    {
      my_strcat(tmp, str1);
      my_strcat(tmp, "/");
      tmp[my_strlen(str1) + 1] = 0;
    }
  else
    {
      my_strcat(tmp, str1);
      tmp[my_strlen(str1)] = 0;
    }
  my_strcat(tmp, str2);
  return (tmp);
}

int	rand_nbr(int min, int max)
{
  int	res;

  res = min + rand() % (max);
  while (res > max || res < min)
    {
      srand(time(NULL));
      res = min + rand() % (max);
    }
  return (res);
}

int	check_tetrimino_grid(int x, int y)
{
  return (!(x > g_tetris.map_size.x || y > g_tetris.map_size.y));
}
