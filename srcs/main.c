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

int	ft_keypress(int keycode, t_vars *vars)
{
	if (keycode == vars->escape)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == vars->a)
		move_a(vars);
	else if (keycode == vars->s)
		move_s(vars);
	else if (keycode == vars->d)
		move_d(vars);
	else if (keycode == vars->w)
		move_w(vars);
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
	t_map	*map;

	if (argc != 2)
		return (0);
	if (validate_map(argv[1]) == false)
	{
		ft_putstr_fd("Error : map invalid\n", 2);
		return (1);
	}
	map = initialise_map(argv[1]);
	vars.map = map;
	vars.mlx = mlx_init();
	initialise_keysum(&vars);
	vars.win = mlx_new_window(vars.mlx, map->width * 24, map->height * 24, "So long");
	background.img = mlx_new_image(vars.mlx, 600, 600);
	background.addr = mlx_get_data_addr(background.img, &background.bits_per_pixel, &background.line_length,
								&background.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, background.img, 0, 0);
	render_map(vars, map);
	map->pos[map->char_y][map->char_x] = '0';
	mlx_hook(vars.win, ON_KEYDOWN, 1L<<0, ft_keypress, &vars);
	mlx_hook(vars.win, ON_DESTROY, 1L<<0, ft_exit, &vars);
	mlx_loop(vars.mlx);
	free(map);
}
