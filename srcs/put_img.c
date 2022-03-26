/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/03/24 12:09:32 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void    put_wall(t_vars vars, int pos_x, int pos_y)
{
    int     width;
    int     height;
    void	*wall;

    wall = mlx_xpm_file_to_image(vars.mlx, "./sprite/Wall.xpm", &width, &height);
	if (wall != NULL)
    {
        mlx_put_image_to_window(vars.mlx, vars.win, wall, pos_x, pos_y);
        free(wall);
    }
}

void    put_collectible(t_vars vars, int pos_x, int pos_y)
{
    int     width;
    int     height;
    void    *collectible;

    collectible = mlx_xpm_file_to_image(vars.mlx, "./sprite/Collectible.xpm", &width, &height);
	if (collectible != NULL)
    {
        mlx_put_image_to_window(vars.mlx, vars.win, collectible, pos_x, pos_y);
        free(collectible);
    }
}

void    put_char(t_vars vars, int pos_x, int pos_y)
{
    int     width;
    int     height;
    void    *character;

    character = mlx_xpm_file_to_image(vars.mlx, "./sprite/Character.xpm", &width, &height);
	if (character != NULL)
    {
        mlx_put_image_to_window(vars.mlx, vars.win, character, pos_x, pos_y);
        free(character);
    }
}

void    put_exit(t_vars vars, int pos_x, int pos_y)
{
    int     width;
    int     height;
    void    *exit;

    exit = mlx_xpm_file_to_image(vars.mlx, "./sprite/ExitOpen.xpm", &width, &height);
	if (exit != NULL)
    {
        mlx_put_image_to_window(vars.mlx, vars.win, exit, pos_x, pos_y);
        free(exit);
    }
}