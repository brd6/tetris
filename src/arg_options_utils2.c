/*
** arg_options_utils2.c for arg_options_utils2 in /home/bongol_b/Epitech-rendu/PSU_2015_tetris
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Feb 23 12:01:18 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 19 15:35:08 2016 Berdrigue BONGOLO BETO
*/

#include "my.h"
#include "tetris.h"

int		check_mask_numnum(char *value)
{
  int		i;

  i = 0;
  if (value[0] == '-')
    return (0);
  if (value[0] == '+')
    value++;
  while (is_num(value[i]))
    i++;
  if (value[i] != ',')
    return (0);
  i++;
  return (value[i] != 0 && my_str_isnum(&value[i]));
}

int		is_option_mask(char *value_mask, char *value)
{
  if (value_mask == NULL || my_strcmp(value_mask, "null") == 0)
    return (value == NULL || value[0] == 0);
  if (my_strcmp(value_mask, "num") == 0)
    return (value[0] != '-' && my_str_isnum(value));
  if (my_strcmp(value_mask, "num,num") == 0)
    return (check_mask_numnum(value));
  return (0);
}
