/*
** tetrimino_file_parser_utils.c for tetrimino_file_parser_utils in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Mar  1 23:08:48 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 20 13:07:04 2016 Berdrigue BONGOLO BETO
*/

#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include "tetris.h"

int			cpt_number(char *line, int *i)
{
  int			i_bak;

  i_bak = *i;
  while (line[*i] && (is_num(line[*i])))
    *i = *i + 1;
  return (*i > i_bak);
}

int			check_file_ext(char *filename, char *ext)
{
  int			i;
  int			k;

  i = 0;
  k = 0;
  while (filename[i])
    {
      if (filename[i] == '.')
	k = i;
      i++;
    }
  return (k > 0 && my_strcmp(filename + k, ext) == 0);
}

int			count_file_in_dir(char *directory)
{
  DIR		*rep;
  struct dirent	*curr_file;
  int		cp;

  cp = 0;
  if ((rep = opendir(directory)) == NULL)
    return (0);
  while ((curr_file = readdir(rep)) != NULL)
    {
      if (my_strcmp(curr_file->d_name, ".") != 0 &&
	  my_strcmp(curr_file->d_name, "..") != 0 &&
	  check_file_ext(curr_file->d_name, TETRIMINOS_FILE_EXT))
	cp++;
    }
  closedir(rep);
  return (cp);
}

int			set_head_info(char *line,
				      int *row,
				      int *col,
				      int *color)
{
  int			i;

  i = 0;
  *col = my_getnbr(line);
  while (line[i] && is_num(line[i]))
    i++;
  i++;
  *row = my_getnbr(&line[i]);
  while (line[i] && is_num(line[i]))
    i++;
  i++;
  *color = my_getnbr(&line[i]);
  return (*row > 0 && *col > 0 && *color > 0);
}

void			init_empty_tetriminos(t_tetriminos tetrimino)
{
  int			l;
  int			k;
  int			q;

  l = 0;
  while (l < 5)
    {
      k = 0;
      while (k < tetrimino.size)
	{
	  q = 0;
	  while (q < tetrimino.size)
	    {
	      tetrimino.shape[l][k][q] = 0;
	      q++;
	    }
	  k++;
	}
      l++;
    }
}
