/*
** alloc_utils.c for alloc_utils in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Mar  2 17:39:00 2016 Berdrigue BONGOLO BETO
** Last update Wed Mar  2 17:41:26 2016 Berdrigue BONGOLO BETO
*/

#include "tetris.h"

void		**alloc_2d(int x, int y, size_t m_size)
{
  int		i;
  void		**res;

  i = 0;
  if ((res = malloc(m_size * (x + 1))) == NULL)
    return (NULL);
  while (i < x)
    {
      if ((res[i] = malloc(m_size * (y + 1))) == NULL)
	return (NULL);
      i = i + 1;
    }
  return (res);
}

void		free_alloc_2d(void **data, int x)
{
  int		i;

  i = 0;
  while (i < x)
    {
      free(data[i]);
      i++;
    }
  free(data);
  data = NULL;
}

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
  while (i <= x)
    {
    if (data[i] != NULL)
      {
  	j = 0;
  	while (j < y)
	  {
	    free(data[i][j]);
	    j++;
	  }
      free(data[i]);
    }
  }
  free(data);
}
