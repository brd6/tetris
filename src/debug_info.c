/*
** debug_info.c for Tetris in /home/franco_k/Projets/PSU/PSU_2015_tetris/src
**
** Made by Matthieu FSC
** Login   <franco_k@epitech.net>
**
** Started on  Sat Mar 19 17:29:04 2016 Matthieu FSC
** Last update Sun Mar 20 15:16:02 2016 Berdrigue BONGOLO BETO
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "my_printf.h"
#include "get_next_line.h"
#include "tetris.h"

int		print_filename(char *filen)
{
  int			i;
  int			k;
  int			test;

  i = 0;
  k = my_strlen(filen);
  test = check_file_ext(filen, TETRIMINOS_FILE_EXT);
  while (test && filen[i])
    {
      if (filen[i] == '.')
	k = i;
      i++;
    }
  i = 0;
  my_putstr("Tetriminos : Name ");
  while (i < k)
    {
      my_putchar(filen[i]);
      i++;
    }
  my_putstr(" : ");
  return (test);
}

void		show_tetrimino_debug_test(char *filen)
{
  t_point		row_col;
  int			color;
  int			fd;
  char			*filename;

  if (!print_filename(filen) ||
      (filename = concat_rep_str(TETRIMINOS_DIRECTORY, filen)) == NULL ||
      !check_tetrimino_file(filename, &row_col.y, &row_col.x, &color))
    {
      my_putstr("Error\n");
      return;
    }
  my_printf("Size %d*%d : Color %d :\n", row_col.x, row_col.y, color);
  if ((fd = open(filename, O_RDONLY)) == -1)
    return;
  print_tetrimino_shape(fd, row_col);
  free(filename);
}

void		show_tetrimino_debug()
{
  char		**files;
  int		i;

  if ((files = get_files_in_dir(TETRIMINOS_DIRECTORY)) == NULL)
    return;
  my_sort_wordtab(files);
  i = 0;
  while (files[i])
    {
      show_tetrimino_debug_test(files[i]);
      i++;
    }
}

void		show_debug()
{
  char		*s;

  my_putstr("*** DEBUG MODE ***\n");
  print_term_touch("Key Left", g_tetris.gamepad.user_key_left);
  print_term_touch("Key Right", g_tetris.gamepad.user_key_right);
  print_term_touch("Key Turn", g_tetris.gamepad.user_key_turn);
  print_term_touch("Key Drop", g_tetris.gamepad.user_key_drop);
  print_term_touch("Key Quit", g_tetris.gamepad.user_key_quit);
  print_term_touch("Key Pause", g_tetris.gamepad.user_key_pause);
  my_printf("Next : %s\n", (g_tetris.without_next == 1) ? "No" : "Yes");
  my_printf("Level : %d\n", g_tetris.level);
  my_printf("Size : %d*%d\n", g_tetris.map_size.y, g_tetris.map_size.x);
  my_printf("Tetriminos : %d\n", count_file_in_dir(TETRIMINOS_DIRECTORY));
  show_tetrimino_debug();
  my_putstr("Press a key to start Tetris\n");
  s = my_getch2();
  free(s);
  set_term_mode(0);
}
