/*
** shape_rotation.c for shape_rotation in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Mar 14 16:15:55 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 19 14:51:05 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

void		set_rotate_coord(int **final_shape,
				 int **shape_0,
				 int **shape_rt,
				 int size)
{
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  k = 0;
  while (i < size)
    {
      j = 0;
      while (j < size)
	{
	  if (shape_0[i][j] != 0)
	    {
	      final_shape[shape_rt[k][1]][shape_rt[k][0]] = shape_0[i][j];
	      k++;
	    }
	  j++;
	}
      i++;
    }
}

void		correct_rotate(int **shape, int size)
{
  t_point	pcorrect;
  int		i;

  pcorrect.x = 0;
  pcorrect.y = 0;
  i = 0;
  while (shape[i] != NULL)
    {
      if (shape[i][0] > pcorrect.x && shape[i][0] > size)
	pcorrect.x = shape[i][0];
      else if (shape[i][0] < pcorrect.x && shape[i][0] < 0)
	pcorrect.x = shape[i][0];
      if (shape[i][1] > pcorrect.y && shape[i][1] > size)
	pcorrect.y = shape[i][1];
      else if (shape[i][1] < pcorrect.y && shape[i][1] < 0)
	pcorrect.y = shape[i][1];
      i++;
    }
  i = 0;
  while (shape[i] != NULL)
    {
      shape[i][0] = shape[i][0] + (-1 * pcorrect.x);
      shape[i][1] = shape[i][1] + (-1 * pcorrect.y);
      i++;
    }
}

void		do_shape_rotation(int **shape)
{
  int		i;
  t_point	pivot;
  t_point	vrelative;
  t_point	vtransform;

  i = 0;
  pivot.x = shape[0][0];
  pivot.y = shape[0][1];
  while (shape[i] != NULL)
    {
      vrelative.x = shape[i][0] - pivot.x;
      vrelative.y = shape[i][1] - pivot.y;
      vtransform.x = (-1 * vrelative.y);
      vtransform.y = vrelative.x;
      shape[i][0] = pivot.x + vtransform.x;
      shape[i][1] = pivot.y + vtransform.y;
      i++;
    }
}

int		set_shape_rotation(int **shape_0, int **shape_rotate, int size)
{
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  k = 0;
  while (i < size)
    {
      j = 0;
      while (j < size)
	{
	  if (shape_0[i][j] != 0 &&
	      ((shape_rotate[k] = malloc(sizeof(shape_rotate) * 2)) != NULL))
	    {
	      shape_rotate[k][0] = j;
	      shape_rotate[k][1] = i;
	      k++;
	    }
	  j++;
	}
      i++;
    }
  return (k);
}

int		shape_rotation(int **shape_0, int size, int **final_shape)
{
  int		**shape_rotate;
  int		i;

  shape_rotate = malloc(sizeof(*shape_rotate) * (size * size + 1));
  if (shape_rotate == NULL)
    return (0);
  if (!(i = set_shape_rotation(shape_0, shape_rotate, size)))
    return (0);
  shape_rotate[i] = NULL;
  do_shape_rotation(shape_rotate);
  correct_rotate(shape_rotate, size);
  set_rotate_coord(final_shape, shape_0, shape_rotate, size);
  return (1);
}
