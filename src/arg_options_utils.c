/*
** arg_options_utils.c for arg_options_utils in /home/bongol_b/Epitech-rendu/PSU_2015_tetris
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Feb 23 03:02:01 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 19 15:24:34 2016 Berdrigue BONGOLO BETO
*/

#include "my.h"
#include "tetris.h"

int		is_option_valid(t_option *options, char *str)
{
  int		i;
  int		keyl_len;

  if (str == NULL || str[0] != '-')
    return (0);
  i = 0;
  while (i < OPTIONS_NB_MAX)
    {
      keyl_len = my_strlen(options[i].key_l);
      if (options[i].key == NULL && options[i].key_l == NULL)
	break;
      if (my_strcmp(str, options[i].key) == 0)
	return (1);
      else if (my_strncmp(str, options[i].key_l, keyl_len) == 0)
	return (2);
      i++;
    }
  return (0);
}

int		get_option_index(t_option *options, char *key)
{
  int		i;
  int		keyl_len;

  i = 0;
  while (i < OPTIONS_NB_MAX)
    {
      keyl_len = my_strlen(options[i].key_l);
      if (options[i].key == NULL && options[i].key_l == NULL)
	break;
      if (my_strcmp(key, options[i].key) == 0)
	return (i);
      else if (my_strncmp(key, options[i].key_l, keyl_len) == 0)
	return (i);
      i++;
    }
  return (-1);
}
