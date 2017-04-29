/*
** arg_options.c for arg_options in /home/bongol_b/Epitech-rendu/PSU_2015_tetris
**
** Made by Berdrigue BONGOLO BETO
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Feb 22 21:59:33 2016 Berdrigue BONGOLO BETO
** Last update Sat Mar 19 15:24:19 2016 Berdrigue BONGOLO BETO
*/

#include "my.h"
#include "tetris.h"

int		get_option(t_option *options,
			   char **ops_ch,
			   int i,
			   int key_type)
{
  int		key_index;
  char		*value;

  if ((key_index = get_option_index(options, ops_ch[i])) == -1)
    return (0);
  if (key_type == 1)
    value = ops_ch[i] + my_strlen(options[key_index].key);
  else
    value = ops_ch[i] + my_strlen(options[key_index].key_l);
  if (key_type != 1)
    return (options[key_index].init(value, options[key_index].key_l));
  return (options[key_index].init(ops_ch[i + 1], options[key_index].key_l));
}

int		parse_option(int ac, char **av)
{
  int		i;
  int		key_type;

  i = 1;
  key_type = -1;
  while (i < ac)
    {
      if (av[i][0] == '-')
	{
	  if ((key_type = is_option_valid(g_tetris.options, av[i])) == 0)
	    return (0);
	  if (!get_option(g_tetris.options, av, i, key_type))
	    return (0);
	}
      else if (av[i][0] == '-' && i % 2 == 0)
	return (0);
      i++;
    }
  return (key_type != -1);
}

int		get_user_option(int ac, char **av)
{
  init_defaut_option(g_tetris.options);
  if (ac == 1)
    return (1);
  g_tetris.multi_init_map_size = 0;
  if (parse_option(ac, av) == 0 ||
      g_tetris.multi_init_map_size % 2 != 0)
    return (print_err_msg(OPTION_ERROR_FORMAT, 0));
  free_options(g_tetris.options);
  return (g_tetris.enable_help ? show_option_help(av[0]) : 1);
}
