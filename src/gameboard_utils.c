/*
** gameboard_utils.c for gameboard_utils in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Mar 19 13:36:32 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 19 14:51:46 2016 Berdrigue BONGOLO BETO
*/

#include "tetris.h"

int		check_complete_line(int row)
{
  int		i;

  i = 0;
  while (i < g_tetris.map_size.x)
    {
      if (g_tetris.gameboard[row][i + 1] == 0)
	return (0);
      i++;
    }
  return (1);
}

void		delete_complete_line(int row)
{
  int		i;
  int		j;

  j = row;
  while (j > 0)
    {
      i = 0;
      while (i <= g_tetris.map_size.x)
	{
	  g_tetris.gameboard[j + 1][i] = g_tetris.gameboard[j][i];
	  i++;
	}
      j--;
    }
}

int		check_all_complete_line()
{
  int		j;
  int		cp;

  j = g_tetris.map_size.y;
  while (j >= 0)
    {
      if ((cp = check_complete_line(j)))
	{
	  g_tetris.line += cp;
	  if (g_tetris.line % 10 == 0)
	    g_tetris.level++;
	  delete_complete_line(j - 1);
	}
      j--;
    }
  return (1);
}
