/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/03/28 15:21:01 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	mov_0(t_vars *vars, char move)
{
	if (move == 'a')
	{
		put_char((*vars), (vars->map->char_x - 1) * 24, vars->map->char_y * 24);
		put_background((*vars), (vars->map->char_x) * 24,
			vars->map->char_y * 24);
		vars->map->char_x--;
	}
	else if (move == 's')
	{
		put_char((*vars), vars->map->char_x * 24, (vars->map->char_y + 1) * 24);
		put_background((*vars), vars->map->char_x * 24, vars->map->char_y * 24);
		vars->map->char_y++;
	}
	else if (move == 'd')
	{
		put_char((*vars), (vars->map->char_x + 1) * 24, vars->map->char_y * 24);
		put_background((*vars), vars->map->char_x * 24, vars->map->char_y * 24);
		vars->map->char_x++;
	}
	else if (move == 'w')
	{
		put_char((*vars), vars->map->char_x * 24, (vars->map->char_y - 1) * 24);
		put_background((*vars), vars->map->char_x * 24, vars->map->char_y * 24);
		vars->map->char_y--;
	}
}

void	won_event(t_vars *vars)
{
	if (vars->map->nb_collectible == 0)
	{
		ft_printf("You Won !\n");
		exit(0);
	}
}
