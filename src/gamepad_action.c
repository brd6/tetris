/*
** gamepad_action.c for gamepad_action in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Mar  5 15:40:32 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 19 15:59:24 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "game_engine.h"
#include "tetris.h"

void		gamepad_action_pause(char *s, int paused)
{
  if (!check_win())
    paused = 0;
  if (my_strcmp(s, g_tetris.gamepad.user_key_pause) == 0)
    g_game_engine.game_state = (paused) ? RUNNING : PAUSED;
  else if (my_strcmp(s, g_tetris.gamepad.user_key_quit) == 0)
    g_game_engine.game_state = QUIT;
  free(s);
}

void		gamepad_action(char *s)
{
  if (my_strcmp(s, g_tetris.gamepad.user_key_left) == 0)
    action_left();
  else if (my_strcmp(s, g_tetris.gamepad.user_key_right) == 0)
    action_right();
  else if (my_strcmp(s, g_tetris.gamepad.user_key_drop) == 0)
    action_drop();
  else if (my_strcmp(s, g_tetris.gamepad.user_key_turn) == 0)
    action_turn();
  else
    gamepad_action_pause(s, 0);
}
