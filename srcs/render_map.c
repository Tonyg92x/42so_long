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

void put_background(t_vars vars, int pos_x, int pos_y)
{
    int     width;
    int     height;
    void	*background;

    background = mlx_xpm_file_to_image(vars.mlx, "./sprite/Background.xpm", &width, &height);
	if (background != NULL)
    {
        mlx_put_image_to_window(vars.mlx, vars.win, background, pos_x, pos_y);
        free(background);
    }
}

void    render_map(t_vars vars, t_map *map)
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
                put_background(vars, x * 24, y * 24);
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