/*
** tetriminos.c for tetriminos in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Fri Feb 26 00:24:33 2016 Berdrigue BONGOLO BETO
** Last update Mon Mar 14 14:46:14 2016 Berdrigue BONGOLO BETO
*/

#include "tetris.h"

int		draw_tetrimino_to_board(t_tetriminos tetrimino)
{
  int		i;
  int		j;
  t_point	pos;
  int		shape;

  i = 0;
  pos = tetrimino.top_left;
  while (i < tetrimino.size)
    {
      j = 0;
      while (j < tetrimino.size)
  	{
  	  if (tetrimino.shape[g_tetris.curr_shape][i][j] != 0)
  	    {
  	      shape = tetrimino.shape[g_tetris.curr_shape][i][j];
  	      g_tetris.gameboard[i + pos.y][j + pos.x] = shape;
  	    }
  	  j++;
  	}
      i++;
    }
  if ((g_tetris.game_over = is_game_over()))
    return (1);
  send_next_tetrimino();
  return (1);
}

void		draw_curr_tetriminos(t_tetriminos tetrimino)
{
  int		i;
  int		j;
  t_point	pos;

  i = 0;
  while (i < tetrimino.size)
    {
      j = 0;
      while (j < tetrimino.size)
	{
	  if (tetrimino.shape[g_tetris.curr_shape][j][i] != 0)
	    {
	      pos.x = i + tetrimino.top_left.x;
	      pos.y = j + tetrimino.top_left.y;
	      wattron(g_tetris.win_board, COLOR_PAIR(tetrimino.color));
	      mvwprintw(g_tetris.win_board, pos.y, pos.x, "*");
	      wattroff(g_tetris.win_board, COLOR_PAIR(tetrimino.color));
	    }
	  j++;
	}
      i++;
    }
}

void		draw_curr_tetriminos_debug(t_tetriminos tetrimino)
{
  int		i;
  int		j;
  t_point	pos;

  i = 0;
  while (i < tetrimino.size)
    {
      j = 0;
      while (j < tetrimino.size)
  	{
  	  if (tetrimino.shape[g_tetris.curr_shape][i][j] != 0)
  	    {
  	      pos.x = i + tetrimino.top_left.x;
  	      pos.y = j + tetrimino.top_left.y;
  	      wattron(g_tetris.win_board_debug, COLOR_PAIR(tetrimino.color));
  	      mvwprintw(g_tetris.win_board_debug, pos.y, pos.x, "%d",
			tetrimino.shape[g_tetris.curr_shape][i][j]);
  	      wattroff(g_tetris.win_board_debug, COLOR_PAIR(tetrimino.color));
  	    }
  	  j++;
  	}
      i++;
    }
}

void		draw_preview_tetriminos(t_tetriminos *tetriminos)
{
  int		i;
  int		j;
  t_point	pos;
  int		color;

  i = 0;
  color = tetriminos[g_tetris.next_tetriminos].color;
  while (i < tetriminos[g_tetris.next_tetriminos].size)
    {
      j = 0;
      while (j < tetriminos[g_tetris.next_tetriminos].size)
	{
	  if (tetriminos[g_tetris.next_tetriminos].shape[0][j][i] != 0)
	    {
	      pos.x = i + 5;
	      pos.y = j + 2;
	      wattron(g_tetris.win_next_preview, COLOR_PAIR(color));
	      mvwprintw(g_tetris.win_next_preview, pos.y, pos.x, "*");
	      wattroff(g_tetris.win_next_preview, COLOR_PAIR(color));
	    }
	  j++;
	}
      i++;
    }
}

void		free_tetriminos()
{
  int		cp;

  cp = 0;
  while (cp < g_tetris.nb_tetriminos)
    {
      free_alloc_3d((void ***)g_tetris.tetriminos[cp].shape,
      		    g_tetris.tetriminos[cp].size,
      		    g_tetris.tetriminos[cp].size);
      cp++;
    }
}
