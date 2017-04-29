/*
** debug_info_utils.c for Tetris in /home/franco_k/Projets/PSU/PSU_2015_tetris/src
** 
** Made by Matthieu FSC
** Login   <franco_k@epitech.net>
** 
** Started on  Sat Mar 19 17:29:19 2016 Matthieu FSC
** Last update Sat Mar 19 17:29:19 2016 Matthieu FSC
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"
#include "get_next_line.h"
#include "tetris.h"

char		**get_files_in_dir(char *dir)
{
  char		**files;
  DIR		*rep;
  struct dirent	*curr_file;
  int		j;

  if ((files = malloc(sizeof(*files) * (count_file_in_dir(dir) + 1))) == NULL ||
      (rep = opendir(dir)) == NULL)
    return (NULL);
  j = 0;
  while ((curr_file = readdir(rep)) != NULL)
    {
      if (my_strcmp(curr_file->d_name, ".") != 0 &&
	  my_strcmp(curr_file->d_name, "..") != 0)
  	{
	  files[j++] = my_strdup(curr_file->d_name);
  	}
    }
  files[j] = 0;
  closedir(rep);
  return (files);
}

void		print_tetrimino_line(char *line)
{
  int		i;
  int		j;

  i = 0;
  while (line[i])
    {
      if (line[i] == '*')
	j = i;
      i++;
    }
  i = 0;
  while (line[i])
    {
      if (i > j)
	break;
      my_putchar(line[i]);
      i++;
    }
}

void		print_tetrimino_shape(int fd, t_point row_col)
{
  char		*line;
  int		i;

  line = get_next_line2(fd);
  i = 0;
  while ((line = get_next_line2(fd)) != NULL)
    {
      if (line != NULL || line[0] != 0)
	{
	  print_tetrimino_line(line);
	  if (i < row_col.y)
	    my_putchar('\n');
	  i++;
	}
      free(line);
    }
}
