/*
** utils.c for utils in /home/bongol_b/Epitech-rendu/PSU_2015_tetris
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Feb 22 23:45:50 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 20 14:54:36 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "tetris.h"

int		alloc_3d_int_cond(int ***data, int x, int y)
{
  int		i;

  i = 0;
  while (i < x)
    {
      if ((data[i] = malloc(sizeof(*data[i]) * y)) == NULL)
	return (0);
      i++;
    }
  return (1);
}

int		***alloc_3d_int(int x, int y, int z)
{
  int		***data;
  int		i;
  int		j;

  if ((data = malloc(sizeof(*data) * x)) == NULL)
    return (NULL);
  if (!alloc_3d_int_cond(data, x, y))
    return (NULL);
  i = 0;
  while (i < x)
    {
      j = 0;
      while (j < y)
	{
	  if ((data[i][j] = malloc(sizeof(*data[i][j]) * z)) == NULL)
	    return (NULL);
	  j++;
	}
      i++;
    }
  return (data);
}

void		free_alloc_3d(void ***data, int x, int y)
{
  int		i;
  int		j;

  i = 0;
  while (i < x)
    {
      j = 0;
      while (j < y)
	{
	  free(data[i][j]);
	  j++;
	}
      free(data[i]);
      i++;
    }
  free(data);
}

int		**alloc_2d_int(int x, int y)
{
  int		i;
  int		**res;
  int		j;

  i = 0;
  if ((res = malloc(sizeof(int **) * (x + 1))) == NULL)
    return (NULL);
  while (i < x)
    {
      if ((res[i] = malloc(sizeof(int *) * (y + 1))) == NULL)
	return (NULL);
      j = 0;
      while (j < y)
	res[i][j++] = 0;
      i = i + 1;
    }
  return (res);
}

void		free_alloc_2d(void **data, int y)
{
  int		i;

  i = 0;
  while (i < y)
    {
      free(data[i]);
      i++;
    }
  free(data);
  data = NULL;
}
