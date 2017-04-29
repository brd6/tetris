/*
** ncurses_utils.c for ncurses_utils.c in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Feb 23 23:00:37 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 19 15:49:39 2016 Berdrigue BONGOLO BETO
*/

#include <unistd.h>
#include <sys/ioctl.h>
#include "my.h"
#include "game_engine.h"
#include "tetris.h"

int		check_win()
{
  struct winsize w;

  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  if (w.ws_col < WIN_WIDTH || w.ws_row < WIN_HEIGHT)
    return (0);
  return (1);
}

void		init_ncurses_color()
{
  init_pair(COLOR_COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
  init_pair(COLOR_COLOR_RED, COLOR_RED, COLOR_BLACK);
  init_pair(COLOR_COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
  init_pair(COLOR_COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
  init_pair(COLOR_COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
  init_pair(COLOR_COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(COLOR_COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
  init_pair(COLOR_COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
}

void		print_colored_string(int x, int y, int color, char *str)
{
  attron(COLOR_PAIR(color));
  mvwprintw(stdscr, y, x, "%s", str);
  attroff(COLOR_PAIR(color));
}

WINDOW		*create_new_win(int n_lines, int n_cols, int pos_x, int pos_y)
{
  WINDOW	*new_win;

  new_win = newwin(n_lines, n_cols, pos_y, pos_x);
  box(new_win, 0, 0);
  wrefresh(new_win);
  return (new_win);
}

int		init_ncurses()
{
  g_tetris.screen_main = newterm(NULL, stdin, stdout);
  if (!check_win())
    {
      my_puterr(WINDOW_SIZE_ERROR);
      g_game_engine.game_state = PAUSED;
      return (0);
    }
  clear();
  noecho();
  curs_set(0);
  g_game_engine.game_state = RUNNING;
  if (has_colors() == FALSE)
    {
      my_putstr(NO_COLOR_ERROR);
      return (0);
    }
  start_color();
  init_ncurses_color();
  return (1);
}
