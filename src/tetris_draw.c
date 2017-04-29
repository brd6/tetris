/*
** tetris_draw.c for tetris_draw in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Feb 24 20:19:48 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 20 00:53:08 2016 Berdrigue BONGOLO BETO
*/

#include <unistd.h>
#include "game_engine.h"
#include "tetris.h"

void		draw_win_score()
{
  int		x;
  int		y;
  int		timer_hour;
  int		timer_min;
  int		timer_sec;

  wclear(g_tetris.win_score);
  timer_hour = (g_tetris.game_timer / 1000000) / 3600;
  timer_min = (g_tetris.game_timer / 1000000) / 60 - timer_hour * 60;
  timer_sec = (g_tetris.game_timer / 1000000) % 60;
  getmaxyx(g_tetris.win_score, x, y);
  mvwprintw(g_tetris.win_score, 2, 2, "High Score");
  mvwprintw(g_tetris.win_score, 2, x + 5, "%6d", g_tetris.high_score);
  mvwprintw(g_tetris.win_score, 3, 2, "Score");
  mvwprintw(g_tetris.win_score, 3, x + 5, "%6d", g_tetris.score);
  mvwprintw(g_tetris.win_score, 5, 2, "Lines");
  mvwprintw(g_tetris.win_score, 5, x + 5, "%6d", g_tetris.line);
  mvwprintw(g_tetris.win_score, 6, 2, "Level");
  mvwprintw(g_tetris.win_score, 6, x + 5, "%6d", g_tetris.level);
  mvwprintw(g_tetris.win_score, 8, 2, "Timer:");
  mvwprintw(g_tetris.win_score, 8, x + 5, " %02d:%02d", timer_min, timer_sec);
  wborder(g_tetris.win_score, '|', '|', '-', '-', '/', '\\', '\\', '/');
  wrefresh(g_tetris.win_score);
  if (y)
    return;
}

void		draw_win_next_preview()
{
  if (g_tetris.without_next)
    return;
  draw_preview_tetriminos(g_tetris.tetriminos);
  wborder(g_tetris.win_next_preview, '|', '|', '-', '-', '/', '\\', '\\', '/');
  usleep(1);
  wrefresh(g_tetris.win_next_preview);
  show_next_preview_title();
}

void		show_next_preview_title()
{
  int		win_next_x;
  int		win_next_y;

  refresh();
  getbegyx(g_tetris.win_next_preview, win_next_y, win_next_x);
  mvwprintw(stdscr, 1, win_next_x + win_next_y, "Next");
}

void		show_pause()
{
  int		win_next_x;
  int		win_next_y;
  int		win_next_mx;
  int		win_next_my;

  getmaxyx(g_tetris.win_board, win_next_my, win_next_mx);
  getbegyx(g_tetris.win_board, win_next_y, win_next_x);
  win_next_y = win_next_y + (win_next_my / 2);
  win_next_x = win_next_x + (win_next_mx / 3);
  wattron(stdscr, A_BOLD);
  mvwprintw(stdscr, win_next_y, win_next_x, "PAUSE");
  wattroff(stdscr, A_BOLD);
  refresh();
}

void		show_game_over()
{
  int		win_next_x;
  int		win_next_y;
  int		win_next_mx;
  int		win_next_my;

  getmaxyx(g_tetris.win_board, win_next_my, win_next_mx);
  getbegyx(g_tetris.win_board, win_next_y, win_next_x);
  win_next_y = win_next_y + (win_next_my / 2);
  win_next_x = win_next_x + (win_next_mx / 3);
  wattron(stdscr, A_BOLD);
  mvwprintw(stdscr, win_next_y, win_next_x, "G A M E  O V E R !");
  wattroff(stdscr, A_BOLD);
  refresh();
  register_hight_score();
  sleep(1);
  g_game_engine.game_state = QUIT;
}
