/*
** actions.c for actions in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Mar  5 17:40:36 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 20 00:50:46 2016 Berdrigue BONGOLO BETO
*/

#include <unistd.h>
#include "tetris.h"

void		action_left()
{
  t_point	mv;

  mv = g_tetris.tetriminos[g_tetris.curr_tetriminos].top_left;
  mv.x--;
  if (check_user_colision(g_tetris.tetriminos[g_tetris.curr_tetriminos], mv))
    {
      g_tetris.tetriminos[g_tetris.curr_tetriminos].top_left.x = mv.x;
      wclear(g_tetris.win_board);
    }
}

void		action_right()
{
  t_point	mv;

  mv = g_tetris.tetriminos[g_tetris.curr_tetriminos].top_left;
  mv.x++;
  if (check_user_colision(g_tetris.tetriminos[g_tetris.curr_tetriminos], mv))
    {
      g_tetris.tetriminos[g_tetris.curr_tetriminos].top_left.x = mv.x;
      wclear(g_tetris.win_board);
    }
}

void		action_drop()
{
  t_point	mv;

  mv = g_tetris.tetriminos[g_tetris.curr_tetriminos].top_left;
  mv.y++;
  while (check_user_colision(g_tetris.tetriminos[g_tetris.curr_tetriminos],
			     mv))
    {
      g_tetris.tetriminos[g_tetris.curr_tetriminos].top_left.y = mv.y;
      wclear(g_tetris.win_board);
      mv.y++;
      if (!check_nxt_pos(g_tetris.tetriminos[g_tetris.curr_tetriminos], mv))
	break;
      usleep(1500);
    }
}

void		action_turn()
{
  t_point	bak_pos;
  t_point	top_left;

  bak_pos = g_tetris.tetriminos[g_tetris.curr_tetriminos].top_left;
  if (g_tetris.curr_shape == 3)
    g_tetris.curr_shape = 0;
  else
    g_tetris.curr_shape++;
  while (1)
    {
      top_left = g_tetris.tetriminos[g_tetris.curr_tetriminos].top_left;
      if (!check_user_colision(g_tetris.tetriminos[g_tetris.curr_tetriminos],
			       top_left))
	{
	  if (g_tetris.tetriminos[g_tetris.curr_tetriminos].top_left.x-- <= 0)
	    {
	      g_tetris.tetriminos[g_tetris.curr_tetriminos].top_left = bak_pos;
	      g_tetris.curr_shape--;
	      return;
	    }
	}
      else
	break;
    }
  wclear(g_tetris.win_board);
}
