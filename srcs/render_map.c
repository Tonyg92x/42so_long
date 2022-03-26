/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycap_linux.c                                     :+:      :+:    :+:   */
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
static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    render_map(t_vars vars, t_map *map, t_data *data)
{
    int x;
    int y;
    y = 0;
    y = 0;
    ft_printf("Map width = %d\nMap height = %d\n", map->width, map->height);
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            ft_printf("%c", map->pos[y][x]);
            x++;
        }
        ft_printf("\n");
        y++;
    }
    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            if (map->pos[y][x] == '1')
                put_wall(vars, x * 24, y * 24);
            else if (map->pos[y][x] == '0')
                ft_clear_case(data, x * 24, y * 24);
            else if (map->pos[y][x] == 'C')
                put_collectible(vars, x * 24, y * 24);
            else if (map->pos[y][x] == 'P')
                put_char(vars, x * 24, y * 24);
            else if (map->pos[y][x] == 'E')
                put_exit_close(vars, x * 24, y * 24);
            else if (map->pos[y][x] == 'W')
                put_exit_close(vars, x * 24, y * 24);
            x++;
        }
        y++;
    }
}