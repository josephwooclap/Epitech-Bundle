/*
** main.c for main in /home/pereni_j/rendu/MUL_2014_wolf3d
** 
** Made by Pereniguez Joseph
** Login   <pereni_j@epitech.net>
** 
** Started on  Tue Dec 16 16:05:11 2014 Pereniguez Joseph
** Last update Sun Dec 21 14:01:47 2014 Pereniguez Joseph
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "mlx.h"
#include "wolf.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

int             keyboard_input(int key)
{
  if (key == 65307)
    {
      my_putstr("esc\n");
      exit(1);
    }
  else if (key == 65362)
    my_putstr("forward ");
  else if (key == 65364)
    my_putstr("backward ");
  else if (key == 65363)
    my_putstr("right ");
  else if (key == 65361)
    my_putstr("left ");
  return (1);
}

int		manage_sets(t_elem *mlx)
{
  mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
  return (0);
}

int		main()
{
  t_elem	*mlx;

  mlx = malloc(sizeof(t_elem));
  mlx->mlx_ptr = mlx_init();
  mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, WEIGHT, "pereni_j");
  mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, WEIGHT);
  mlx->img = mlx_get_data_addr(mlx->img_ptr, &(mlx->bpp), &(mlx->size_line), &(mlx->endian));
  sky_color(mlx, mlx->x, mlx->y);
  ground_color(mlx, mlx->x, mlx->y);
  mlx_expose_hook(mlx->win_ptr, manage_sets, mlx);
  mlx_key_hook(mlx->win_ptr, keyboard_input, mlx);
  mlx_loop(mlx->mlx_ptr);
  return (0);
}
