/*
** init_defaut_option.c for init_defaut_option in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Feb 23 19:47:38 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 19 15:40:51 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

void		free_options(t_option *options)
{
  int		i;

  i = 0;
  while (i < OPTIONS_NB_MAX)
    {
      if (options[i].key == NULL && options[i].key_l == NULL)
	break;
      free(options[i].key);
      free(options[i].key_l);
      i++;
    }
}

void		set_defaut_option(t_option *option,
				  char *key,
				  char *key_l,
				  int (*init)(char *, char *))
{
  option->key = my_strdup(key);
  option->key_l = my_strdup(key_l);
  option->init = init;
}

void		set_defaut_gamepad()
{
  if ((g_tetris.gamepad.user_key_right = my_strdup(tigetstr("kcuf1"))) == NULL)
    exit(1);
  if ((g_tetris.gamepad.user_key_left = my_strdup(tigetstr("kcub1"))) == NULL)
    exit(1);
  if ((g_tetris.gamepad.user_key_turn = my_strdup(tigetstr("kcuu1"))) == NULL)
    exit(1);
  if ((g_tetris.gamepad.user_key_drop = my_strdup(tigetstr("kcud1"))) == NULL)
    exit(1);
  if ((g_tetris.gamepad.user_key_quit = my_strdup("q")) == NULL)
    exit(1);
  if ((g_tetris.gamepad.user_key_pause = my_strdup(" ")) == NULL)
    exit(1);
}

void		set_defaut_tetris_cmd()
{
  set_defaut_gamepad();
  g_tetris.map_size.y = 20;
  g_tetris.map_size.x = 10;
  g_tetris.level = 1;
  g_tetris.enable_debug = 0;
  g_tetris.enable_help = 0;
  g_tetris.score = 0;
  g_tetris.line = 0;
  g_tetris.high_score = get_hight_score();
  g_tetris.curr_shape = 0;
  g_tetris.without_next = 0;
  g_tetris.curr_tetriminos = 0;
  g_tetris.next_tetriminos = 0;
  g_tetris.game_tick = GAME_SPEED_2 - g_tetris.level * GAME_SPEED;
  g_tetris.game_run = 1;
  g_tetris.game_timer = 0;
  g_tetris.game_over = 0;
}

void		init_defaut_option(t_option *options)
{
  set_defaut_option(options, NULL, "--help", cbk_init_option);
  set_defaut_option(++options, "-l", "--level=", cbk_init_option);
  set_defaut_option(++options, "-kl", "--key-left=", cbk_init_option_key);
  set_defaut_option(++options, "-kr", "--key-right=", cbk_init_option_key);
  set_defaut_option(++options, "-kt", "--key-turn=", cbk_init_option_key);
  set_defaut_option(++options, "-kd", "--key-drop=", cbk_init_option_key);
  set_defaut_option(++options, "-kq", "--key-quit=", cbk_init_option_key);
  set_defaut_option(++options, "-kp", "--key-pause=", cbk_init_option_key);
  set_defaut_option(++options, NULL, "--map-size=", cbk_init_option_mapsize);
  set_defaut_option(++options, "-w", "--without-next", cbk_init_option);
  set_defaut_option(++options, "-d", "--debug", cbk_init_option);
  set_defaut_option(++options, NULL, NULL, NULL);
  set_defaut_tetris_cmd();
}
