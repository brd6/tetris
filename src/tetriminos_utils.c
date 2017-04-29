/*
** tetriminos_utils.c for tetriminos_utils in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Mar  5 18:10:46 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 19 18:12:46 2016 Berdrigue BONGOLO BETO
*/

#include "tetris.h"

void		send_next_tetrimino()
{
  t_point	nxt_pos;

  nxt_pos.x = 5;
  nxt_pos.y = 1;
  if (!check_nxt_pos(g_tetris.tetriminos[g_tetris.next_tetriminos],
		       nxt_pos))
    {
      g_tetris.game_over = 1;
      return;
    }
  g_tetris.tetriminos[g_tetris.curr_tetriminos].top_left.y = 0;
  g_tetris.tetriminos[g_tetris.curr_tetriminos
		      ].top_left.x = g_tetris.map_size.x / 2;
  g_tetris.curr_tetriminos = g_tetris.next_tetriminos;
  g_tetris.next_tetriminos = rand_nbr(0, g_tetris.nb_tetriminos);
  g_tetris.curr_shape = 0;
  g_tetris.score += g_tetris.level + (g_tetris.line / 2);
  wclear(g_tetris.win_next_preview);
}

int		check_user_colision(t_tetriminos tetrimino, t_point nxt_pos)
{
  int		i;
  int		j;

  i = 0;
  while (i < tetrimino.size)
    {
      j = 0;
      while (j < tetrimino.size)
	{
	  if (tetrimino.shape[g_tetris.curr_shape][i][j] != 0)
	    {
	      if (nxt_pos.y + i > g_tetris.map_size.y ||
		  nxt_pos.x + j > g_tetris.map_size.x ||
		  nxt_pos.x + j < 1 ||
		  g_tetris.gameboard[i + nxt_pos.y][j + nxt_pos.x] != 0)
		return (0);
	    }
	  j++;
	}
      i++;
    }
  return (1);
}

int		draw_tetrimino_to_board_cond(t_tetriminos tetrimino,
					     t_point nxt_pos,
					     int i,
					     int j)
{
  if (i + nxt_pos.y - 1 == g_tetris.map_size.y ||
      g_tetris.gameboard[i + nxt_pos.y][j + nxt_pos.x] != 0)
    draw_tetrimino_to_board(tetrimino);
  return (0);
}

int		check_nxt_pos(t_tetriminos tetrimino, t_point nxt_pos)
{
  int		i;
  int		j;

  i = 0;
  while (i < tetrimino.size)
    {
      j = 0;
      while (j < tetrimino.size)
	{
	  if (tetrimino.shape[g_tetris.curr_shape][i][j] != 0)
	    {
	      if (nxt_pos.y + i > g_tetris.map_size.y ||
		  nxt_pos.x + j > g_tetris.map_size.x || nxt_pos.x + j < 1 ||
		  g_tetris.gameboard[i + nxt_pos.y][j + nxt_pos.x] != 0)
		return (draw_tetrimino_to_board_cond(tetrimino, nxt_pos, i, j));
	    }
	  j++;
	}
      i++;
    }
  return (1);
}

t_point		get_tetrimino_max_grid()
{
  int		i;
  t_point	max;

  i = 0;
  max.x = 0;
  max.y = 0;
  while (i < g_tetris.nb_tetriminos)
    {
      if (g_tetris.tetriminos[i].grid.x > max.x)
	max.x = g_tetris.tetriminos[i].grid.x;
      if (g_tetris.tetriminos[i].grid.y > max.y)
	max.y = g_tetris.tetriminos[i].grid.y;
      i++;
    }
  return (max);
}
