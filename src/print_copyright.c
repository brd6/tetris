/*
** print_copyright.c for print_copyright in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Feb 25 15:47:40 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 19 14:46:02 2016 Berdrigue BONGOLO BETO
*/

#include "tetris.h"

void		print_copyright()
{
  int		x;
  int		y;

  getmaxyx(g_tetris.win_score, y, x);
  mvwprintw(stdscr, x - 2, 2, "%s", "EpiTetris(c) - 2042");
  refresh();
  if (y)
    return;
}
