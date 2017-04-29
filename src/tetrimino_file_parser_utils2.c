/*
** tetrimino_file_parser_utils2.c for tetrimino_file_parser_utils2 in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Mar  2 12:38:49 2016 Berdrigue BONGOLO BETO
** Last update Sun Mar 20 14:45:53 2016 Berdrigue BONGOLO BETO
*/

#include "tetris.h"

int			check_first_line(char *line)
{
  int			i;
  int			space_cpt;
  int			nbr_cpt;

  i = 0;
  space_cpt = 0;
  nbr_cpt = 0;
  if (!(line[i] >= '0' && line[i] <= '9'))
    return (0);
  while (line[i])
    {
      if (space_cpt > 2 || nbr_cpt > 3)
	return (0);
      nbr_cpt += cpt_number(line, &i);
      if (line[i] == 0)
	break;
      if (line[i] == ' ')
	space_cpt++;
      else
	return (0);
      i++;
    }
  return ((space_cpt == 2 && nbr_cpt == 3));
}

int			check_second_line(char *line, int col)
{
  int			k;

  k = 0;
  while (line[k])
    {
      if ((line[k] != ' ' && line[k] != '*'))
	return (0);
      if (k >= col && line[k] != ' ')
      	return (0);
      k++;
    }
  return (k);
}
