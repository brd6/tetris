/*
** gen_tetriminos_rotation.c for gen_tetriminos_rotation in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Mar 15 00:34:08 2016 Berdrigue BONGOLO BETO
** Last update Tue Mar 15 01:13:47 2016 Berdrigue BONGOLO BETO
*/

#include "tetris.h"

void		gen_tetriminos_rotation()
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i < g_tetris.nb_tetriminos)
    {
      j = 0;
      while (j < 3)
	{
	  shape_rotation(g_tetris.tetriminos[i].shape[j],
			 g_tetris.tetriminos[i].size,
			 g_tetris.tetriminos[i].shape[j + 1]);
	  j++;
	}
      i++;
    }
}
