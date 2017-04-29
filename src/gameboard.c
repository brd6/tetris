/*
** gameboard.c for gameboard in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Feb 25 22:57:47 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 19 15:52:43 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "game_engine.h"
#include "tetris.h"

int		init_gameboard()
{
  int		m_size;
  int		i;
  int		j;

  g_tetris.gameboard = malloc(sizeof(int **) * (g_tetris.map_size.y + 1));
  if (g_tetris.gameboard == NULL)
    return (0);
  i = 0;
  while (i <= g_tetris.map_size.y)
    {
      m_size = sizeof(int *) * (g_tetris.map_size.x + 1);
      if ((g_tetris.gameboard[i] = malloc(m_size)) == NULL)
	return (0);
      j = 0;
      while (j <= g_tetris.map_size.x)
	g_tetris.gameboard[i][j++] = 0;
      i++;
    }
  return (1);
}

void		draw_win_board()
{
  int		i;
  int		j;

  i = 0;
  while (++i <= g_tetris.map_size.y)
    {
      j = 0;
      while (++j <= g_tetris.map_size.x)
	{
	  if (g_tetris.gameboard[i][j] != 0)
	    {
	      wattron(g_tetris.win_board, COLOR_PAIR(g_tetris.gameboard[i][j]));
	      mvwprintw(g_tetris.win_board, i, j, "*",
			g_tetris.gameboard[i][j]);
	      wattroff(g_tetris.win_board,
		       COLOR_PAIR(g_tetris.gameboard[i][j]));
	    }
	}
    }
  draw_curr_tetriminos(g_tetris.tetriminos[g_tetris.curr_tetriminos]);
  draw_curr_tetriminos_debug(g_tetris.tetriminos[g_tetris.curr_tetriminos]);
  wborder(g_tetris.win_board, '|', '|', '-', '-', '-', '-', '-', '-');
  wrefresh(g_tetris.win_board);
  if (g_tetris.game_over)
    g_game_engine.game_state = PAUSED;
}

void		draw_win_board_debug()
{
  int		i;
  int		j;

  if (!g_tetris.enable_debug)
    return;
  i = 0;
  while (i <= g_tetris.map_size.y)
    {
      j = 0;
      while (j <= g_tetris.map_size.x)
	{
	  if (g_tetris.gameboard[i][j] > 0)
	    wattron(g_tetris.win_board_debug,
		    COLOR_PAIR(g_tetris.gameboard[i][j]));
	  mvwprintw(g_tetris.win_board_debug, i, j, "%d",
		    g_tetris.gameboard[i][j]);
	  if (g_tetris.gameboard[i][j] > 0)
	    wattroff(g_tetris.win_board_debug,
		     COLOR_PAIR(g_tetris.gameboard[i][j]));
	  j++;
	}
      i++;
    }
  wborder(g_tetris.win_board_debug, '|', '|', '-', '-', '-', '-', '-', '-');
  wrefresh(g_tetris.win_board_debug);
}

int		is_game_over()
{
  int		j;

  j = 0;
  while (j <= g_tetris.map_size.x)
    {
      if (g_tetris.gameboard[1][j] != 0)
	return (1);
      j++;
    }
  return (0);
}
