/*
** env_utils.c for env_utils in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Mar  4 12:52:46 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 19 15:57:31 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

int		env_search(char *str, char *to_find)
{
  return (my_strstr(str, to_find) != NULL ? 0 : 1);
}

char		*get_user_term(char **env)
{
  char		*str;

  if (env == NULL || env[0] == NULL || env[0][0] == 0)
    return (0);
  str = my_wordtab_search(env, "TERM", env_search);
  return ((str != NULL && str[0] != 0) ? my_getstr_value(str, '=') : NULL);
}
