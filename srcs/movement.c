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

void    move_a(t_vars *vars)
{
    if (vars->map->char_x >= 2)
    {
        if (vars->map->pos[vars->map->char_y][vars->map->char_x - 1] != '1')
        {
            if (vars->map->pos[vars->map->char_y][vars->map->char_x - 1] == '0')
            {
                put_char((*vars), (vars->map->char_x - 1) * 24, vars->map->char_y * 24);
                put_background((*vars), (vars->map->char_x) * 24, vars->map->char_y * 24);
                vars->map->char_x--;
            }
            else if (vars->map->pos[vars->map->char_y][vars->map->char_x - 1] == 'C')
            {
                put_char((*vars), (vars->map->char_x - 1) * 24, vars->map->char_y * 24);
                put_background((*vars), (vars->map->char_x) * 24, vars->map->char_y * 24);
                vars->map->char_x--;
                vars->map->nb_collectible--;
            }
        }
    }
}

void    move_s(t_vars *vars)
{
    if (vars->map->char_y < vars->map->height)
    {
        if (vars->map->pos[vars->map->char_y + 1][vars->map->char_x] != '1')
        {
            if (vars->map->pos[vars->map->char_y + 1][vars->map->char_x] == '0')
            {
                put_char((*vars), vars->map->char_x * 24, (vars->map->char_y + 1) * 24);
                put_background((*vars), vars->map->char_x * 24, vars->map->char_y * 24);
                vars->map->char_y++;
            }
            else if (vars->map->pos[vars->map->char_y + 1][vars->map->char_x] == 'C')
            {
                put_char((*vars), vars->map->char_x * 24, (vars->map->char_y + 1) * 24);
                put_background((*vars), vars->map->char_x * 24, vars->map->char_y * 24);
                vars->map->char_y++;
                vars->map->nb_collectible--;
            }
        }
    }
}

void    move_d(t_vars *vars)
{
    if (vars->map->char_x < vars->map->width)
    {
        if (vars->map->pos[vars->map->char_y][vars->map->char_x + 1] != '1')
        {
            if (vars->map->pos[vars->map->char_y][vars->map->char_x + 1] == '0')
            {
                put_char((*vars), (vars->map->char_x + 1) * 24, vars->map->char_y * 24);
                put_background((*vars), vars->map->char_x * 24, vars->map->char_y * 24);
                vars->map->char_x++;
            }
            else if (vars->map->pos[vars->map->char_y][vars->map->char_x + 1] == 'C')
            {
                put_char((*vars), (vars->map->char_x + 1) * 24, vars->map->char_y * 24);
                put_background((*vars), vars->map->char_x * 24, vars->map->char_y * 24);
                vars->map->char_x++;;
                vars->map->nb_collectible--;
            }
        }
    }
}

void    move_w(t_vars *vars)
{
    if (vars->map->char_y >= 2)
    {
        if (vars->map->pos[vars->map->char_y - 1][vars->map->char_x] != '1')
        {
            if (vars->map->pos[vars->map->char_y - 1][vars->map->char_x] == '0')
            {
                put_char((*vars), vars->map->char_x * 24, (vars->map->char_y - 1) * 24);
                put_background((*vars), vars->map->char_x * 24, vars->map->char_y * 24);
                vars->map->char_y--;
            }
            else if (vars->map->pos[vars->map->char_y - 1][vars->map->char_x] == 'C')
            {
                put_char((*vars), vars->map->char_x * 24, (vars->map->char_y - 1) * 24);
                put_background((*vars), vars->map->char_x * 24, vars->map->char_y * 24);
                vars->map->char_y--;
                vars->map->nb_collectible--;
            }
        }
    }
}