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

bool	quit(int fd, char *str)
{
	if (fd != 0)
		close(fd);
	if (str != NULL)
		free(str);
	return (false);
}

char	*next_str(char	*str, int fd)
{
	char	*temp;

	if (str != NULL)
		free(str);
	str = get_next_line(fd);
	temp = ft_strtrim(str, "\n");
	free(str);
	return (temp);
}

static t_map *init_map(int fd, t_map *map)
{
	int		x;
	int		y;
	char	*str;

	map = malloc(sizeof(t_map));
	str = next_str(NULL, fd);
	map->width = ft_strlen(str);
	y = 0;
	map->nb_collectible = 0;
	while (str != NULL)
	{
		x = 0;
		while (x < map->width)
		{
			if (str[x] == 'P')
			{
				map->char_x = x;
				map->char_y = y;
			}
			if (str[x] == 'E')
			{
				map->exit_x = x;
				map->exit_y = y;
			}
			if (str[x] == 'C')
				map->nb_collectible++;
			map->pos[y][x] = str[x];
			x++;
		}
		str = next_str(str, fd);
		y++;
		if (y > 100)
		{
			free(map);
			return (NULL);
		}
		if (str == NULL)
			break;
	}
	map->height = y;
	if (str != NULL)
		free(str);
	close(fd);
	return (map);
}

t_map	*initialise_map(char *file)
{
	t_map	*map;
	int		fd;
	char	*file_trim;

	fd = 0;
	file_trim = ft_strtrim(file, " ");
	fd = open(file_trim, O_RDONLY);
	if (fd == -1)
	{
		quit(fd, file_trim);
		ft_putstr_fd("Error : Can't open the file.", 2);
		return (NULL);
	}
	map = init_map(fd, map);
	map->nb_movement = 0;
	quit(fd, file_trim);
	return (map);
}