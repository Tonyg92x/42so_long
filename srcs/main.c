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

void	put_square(t_data *img, int color)
{
	int	x;
	int	y;

	x = 60;
	y = 60;
	while (y < 159)
	{
		x = 60;
		while (x < 159)
			my_mlx_pixel_put(img, x++, y, color);
		y++;
	}
}

int	ft_close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	img;

	if (argc != 2)
		return (0);
	if (validate_map(argv[1]) == false)
	{
		ft_putstr_fd("Error : map invalid\n", 2);
		return (1);
	}
	vars.mlx = mlx_init();
	initialise_keysum(&vars);
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "So long");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	put_square(&img, RED);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, ON_KEYDOWN, 1L<<0, ft_close, &vars);
	mlx_loop(vars.mlx);
}
