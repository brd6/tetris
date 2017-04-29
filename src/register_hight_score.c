/*
** register_hight_score.c for register_hight_score in /home/bongol_b/Epitech-rendu/PSU_2015_tetris/src
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Mar 15 02:47:58 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 19 16:18:26 2016 Berdrigue BONGOLO BETO
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "tetris.h"

int		get_hight_score()
{
  int		fd;
  char		buff[100];
  int		i;

  if ((fd = open(HIGHT_SCORE_FILENAME, O_RDONLY)) == -1)
    return (0);
  i = read(fd, buff, 100);
  buff[i] = 0;
  if (buff[0] == '-' || !my_str_isnum(buff))
    return (0);
  i = my_getnbr(buff);
  close(fd);
  return ((i <= 99999) ? i : 99999);
}

void		register_hight_score()
{
  int		fd;
  int		curr_high_score;
  char		*curr_score;

  if ((curr_high_score = get_hight_score()) == -1)
    return;
  if (curr_high_score >= g_tetris.score)
    return;
  if ((fd = open(HIGHT_SCORE_FILENAME, O_CREAT | O_WRONLY | O_TRUNC,
		 (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH))) == -1)
    return;
  curr_score = my_itoa(g_tetris.score);
  write(fd, curr_score, my_strlen(curr_score));
  close(fd);
}
