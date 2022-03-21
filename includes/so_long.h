/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:38:26 by aguay             #+#    #+#             */
/*   Updated: 2022/03/21 11:47:18 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../MLX42/include/MLX42/MLX42.h"
# define WIDTH 256
# define HEIGHT 256
# define WIDTH_CASE 64
# define HEIGHT_CASE 64

typedef struct map_case
{
	int			width; 
	int			height;
	int			x_pos;
	int			y_pos;
	char		type;
}				t_map_case;

typedef struct map_line
{
	t_map_case	**cases;
	int			y_pos;
	int			nb_cases;
}				t_map_line;

typedef struct map
{
	t_map_line	**line;
	int			nb_x;
	int			nb_y;
}				t_map;

bool	validate_map(char	*file);

#endif
