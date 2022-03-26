/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:35:51 by aguay             #+#    #+#             */
/*   Updated: 2022/03/24 12:15:54 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

//	offset the data to get the pixel at the right place in the window
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_keypress(int keycode, t_vars *vars)
{
	ft_printf("Keycode %d has been pressed.\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	ft_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	background;

	if (argc != 2)
		return (0);
	if (validate_map(argv[1]) == false)
	{
		ft_putstr_fd("Error : map invalid\n", 2);
		return (1);
	}
	vars.mlx = mlx_init();
	initialise_keysum(&vars);
	vars.win = mlx_new_window(vars.mlx, 600, 600, "So long");
	background.img = mlx_new_image(vars.mlx, 600, 600);
	background.addr = mlx_get_data_addr(background.img, &background.bits_per_pixel, &background.line_length,
								&background.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, background.img, 0, 0);
	put_wall(vars, 0, 0);
	put_wall(vars, 25, 0);
	mlx_hook(vars.win, ON_KEYDOWN, 1L<<0, ft_keypress, &vars);
	mlx_hook(vars.win, ON_DESTROY, 1L<<0, ft_exit, &vars);
	mlx_loop(vars.mlx);
}
