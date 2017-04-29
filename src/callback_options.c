/*
** callback_options.c for callback_option in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Feb 24 16:08:02 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 19 15:50:14 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

int		cbk_init_option_key(char *value, char *key_l)
{
  if ((value == NULL || value[0] == 0) ||
      is_option_valid(g_tetris.options, value))
    return (0);
  if (my_strcmp(key_l, "--key-left=") == 0)
    g_tetris.gamepad.user_key_left = my_strdup(value);
  else if (my_strcmp(key_l, "--key-right=") == 0)
    g_tetris.gamepad.user_key_right = my_strdup(value);
  else if (my_strcmp(key_l, "--key-turn=") == 0)
    g_tetris.gamepad.user_key_turn = my_strdup(value);
  else if (my_strcmp(key_l, "--key-drop=") == 0)
    g_tetris.gamepad.user_key_drop = my_strdup(value);
  else if (my_strcmp(key_l, "--key-quit=") == 0)
    g_tetris.gamepad.user_key_quit = my_strdup(value);
  else if (my_strcmp(key_l, "--key-pause=") == 0)
    g_tetris.gamepad.user_key_pause = my_strdup(value);
  return (1);
}

int		cbk_init_option(char *value, char *key_l)
{
  int		nb;

  if (my_strcmp(key_l, "--level=") == 0 && (value == NULL || value[0] == 0))
      return (0);
  if (my_strcmp(key_l, "--level=") == 0 &&
      is_option_mask("num", value) && (nb = my_getnbr(value)) >= 1)
    {
      g_tetris.level = nb;
      return (1);
    }
  if ((value == NULL || value[0] == 0) ||
      is_option_valid(g_tetris.options, value))
    {
      if (my_strcmp(key_l, "--without-next") == 0)
	g_tetris.without_next = 1;
      else if (my_strcmp(key_l, "--help") == 0)
	g_tetris.enable_help = 1;
      else if (my_strcmp(key_l, "--debug") == 0)
	g_tetris.enable_debug = 1;
      return (1);
    }
  return (0);
}

int		cbk_init_option_mapsize(char *value, char *key_l)
{
  char		**array_num;
  int		nb;
  int		nb2;

  if ((value == NULL || value[0] == 0) || my_strcmp(key_l, "--map-size=") != 0)
    return (0);
  array_num = my_str_split(value, ',');
  if (is_option_mask("num,num", value) && (nb = my_getnbr(array_num[0])) >= 1 &&
    (nb2 = my_getnbr(array_num[1])) >= 1)
    {
      g_tetris.map_size.y = nb;
      g_tetris.map_size.x = nb2;
    }
  else if (is_option_mask("num", value) && (nb = my_getnbr(value)) >= 1)
    {
      if (g_tetris.multi_init_map_size % 2 == 0)
	g_tetris.map_size.y = nb;
      else
	g_tetris.map_size.x = nb;
      g_tetris.multi_init_map_size++;
    }
  else
    return (0);
  free(array_num);
  return (1);
}
