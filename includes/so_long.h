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

#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
# define RED 0xa80303
# define BLUE 0x0512a1
# define GREEN 0x12c912
# define TEAL 0x0bc2d6
# define PURPLE 0xa107b3
# define YELLOW 0xe6ff05
# define BLACK	0x000000
# define BACKGROUD 0xE2F3FF

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
	int		escape;
	int		w;
	int		a;
	int		s;
	int		d;
}				t_vars;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_map {
	int		width;
	int		height;
	char	pos[100][100];
}				t_map;

bool	validate_map(char	*file);
void    initialise_keysum(t_vars *vars);
void  	put_wall(t_vars vars, int pos_x, int pos_y);
void    put_collectible(t_vars vars, int pos_x, int pos_y);
void    put_char(t_vars vars, int pos_x, int pos_y);
t_map   *initialise_map(char *file);
void    put_exit_open(t_vars vars, int pos_x, int pos_y);
void    put_exit_close(t_vars vars, int pos_x, int pos_y);
void    render_map(t_vars vars, t_map *map, t_data *data);

#endif
