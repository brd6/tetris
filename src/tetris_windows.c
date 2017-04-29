/*
** tetris_windows.c for tetris_windows in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Feb 24 20:07:33 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 20 14:49:36 2016 Berdrigue BONGOLO BETO
*/

#include "tetris.h"

void		create_win_board()
{
  int		row;
  int		col;
  int		win_score_x;
  int		win_score_y;

  refresh();
  getmaxyx(g_tetris.win_score, win_score_y, win_score_x);
  col = g_tetris.map_size.x + 2;
  row = g_tetris.map_size.y + 2;
  g_tetris.win_board = create_new_win(row, col, (win_score_y * 2) + 7, 1);
  keypad(g_tetris.win_board, TRUE);
  if (win_score_x)
    return;
}

void		create_win_board_debug()
{
  int		row;
  int		col;
  int		win_prev_x;
  int		win_prev_y;
  int		win_prev_mx;
  int		win_prev_my;
  int		size_m;

  if (!g_tetris.enable_debug)
    return;
  getmaxyx(g_tetris.win_next_preview, win_prev_my, win_prev_mx);
  getbegyx(g_tetris.win_next_preview, win_prev_y, win_prev_x);
  size_m = win_prev_x + win_prev_mx + 5;
  col = g_tetris.map_size.x + 2;
  row = g_tetris.map_size.y + 2;
  g_tetris.win_board_debug = create_new_win(row, col, size_m, 1);
  if (win_prev_my && win_prev_y)
    return;
}

void		create_win_score()
{
  g_tetris.win_score = create_new_win(11, 24, 1, 8);
}

void		create_win_next_preview()
{
  int		size_m;
  int		win_board_x;
  int		win_board_y;
  int		win_board_mx;
  int		win_board_my;
  t_point	grid_max;
  t_point	xy;

  grid_max = get_tetrimino_max_grid();
  if (g_tetris.without_next)
    return;
  getmaxyx(g_tetris.win_board, win_board_my, win_board_mx);
  getbegyx(g_tetris.win_board, win_board_y, win_board_x);
  size_m = win_board_x + win_board_mx + 3;
  xy.x = win_board_mx;
  xy.y = win_board_my / 4 + grid_max.x;
  g_tetris.win_next_preview = create_new_win(xy.y, xy.x, size_m, 1);
  if (win_board_my && win_board_y)
    return;
}
