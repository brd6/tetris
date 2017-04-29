/*
** tetrimino_file_parser.c for tetrimino_file_parser in /home/bongol_b/Epitech-rendu/PSU_2015_tetris
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Feb 23 16:36:30 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 20 14:45:19 2016 Berdrigue BONGOLO BETO
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "get_next_line.h"
#include "tetris.h"

void			record_line_in_struct(char *line, int *j, int *i)
{
  int			k;
  int			z;

  k = 0;
  z = 0;
  if (is_num(line[0]))
    return;
  while (line[k])
    {
      if (line[k] != ' ')
	g_tetris.tetriminos[*j].shape[0][*i][z] = g_tetris.tetriminos[*j].color;
      z++;
      k++;
    }
  *i = *i + 1;
}

int			check_tetrimino_file(char *filename,
					     int *row,
					     int *col,
					     int *color)
{
  int			fd;
  char			*line;
  int			row_cp;
  int			len;
  int			maxlen;

  if ((fd = open(filename, O_RDONLY)) == -1 ||
      (line = get_next_line2(fd)) == NULL || !check_first_line(line) ||
      !set_head_info(line, row, col, color))
    return (0);
  row_cp = 0;
  len = 0;
  maxlen = 0;
  while ((line = get_next_line2(fd)) != NULL)
    {
      if (line[0] != 0 && ((len = check_second_line(line, *col)) == 0))
      	return (0);
      if (len > maxlen)
      	maxlen = len;
      if (line[0] != 0)
      	row_cp++;
      free(line);
    }
  close(fd);
  return (row_cp == *row && maxlen >= *col && check_tetrimino_grid(*row, *col));
}

int			set_tetrimino_shape_info(int *j,
						 int row,
						 int col,
						 int color)
{
  int			max;

  max = GET_MAX(row, col);
  g_tetris.tetriminos[*j].shape = alloc_3d_int(5, max, max);
  if (g_tetris.tetriminos[*j].shape == NULL)
    return (0);
  g_tetris.tetriminos[*j].size = max;
  g_tetris.tetriminos[*j].top_left.y = 1;
  g_tetris.tetriminos[*j].top_left.x = (g_tetris.map_size.x / 2);
  g_tetris.tetriminos[*j].color = color;
  g_tetris.tetriminos[*j].grid.x = row;
  g_tetris.tetriminos[*j].grid.y = col;
  init_empty_tetriminos(g_tetris.tetriminos[*j]);
  return (1);
}

int			read_tetrimino_file(char *filen, int *j)
{
  int			row;
  int			col;
  int			color;
  int			fd;
  char			*line;
  char			*filename;
  int			i;

  if ((filename = concat_rep_str(TETRIMINOS_DIRECTORY, filen)) == NULL)
    return (0);
  if (!check_tetrimino_file(filename, &row, &col, &color) ||
      (fd = open(filename, O_RDONLY)) == -1 ||
      !set_tetrimino_shape_info(j, row, col, color))
    return (0);
  i = 0;
  while ((line = get_next_line2(fd)) != NULL)
    {
      record_line_in_struct(line, j, &i);
      free(line);
    }
  *j = *j + 1;
  free(filename);
  close(fd);
  return (1);
}

int			tetrimino_parse()
{
  DIR		*rep;
  struct dirent	*curr_file;
  int		nb_file;
  int		j;

  if ((nb_file = count_file_in_dir(TETRIMINOS_DIRECTORY)) == 0)
    return (0);
  g_tetris.tetriminos = malloc(sizeof(*g_tetris.tetriminos) * (nb_file + 1));
  if (g_tetris.tetriminos == NULL ||
      (rep = opendir(TETRIMINOS_DIRECTORY)) == NULL)
    return (0);
  j = 0;
  g_tetris.nb_tetriminos = nb_file;
  while ((curr_file = readdir(rep)) != NULL)
    {
      if (my_strcmp(curr_file->d_name, ".") != 0 &&
  	  my_strcmp(curr_file->d_name, "..") != 0 &&
	  check_file_ext(curr_file->d_name, TETRIMINOS_FILE_EXT))
  	{
  	  if (!read_tetrimino_file(curr_file->d_name, &j))
	    g_tetris.nb_tetriminos--;
  	}
    }
  closedir(rep);
  return (g_tetris.nb_tetriminos > 0);
}
