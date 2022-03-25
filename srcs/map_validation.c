/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:35:51 by aguay             #+#    #+#             */
/*   Updated: 2022/03/23 09:14:03 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

static bool	quit(int fd, char *str)
{
	if (fd != 0)
		close(fd);
	if (str != NULL)
		free(str);
	return (false);
}

static char	*next_str(char	*str, int fd)
{
	char	*temp;

	if (str != NULL)
		free(str);
	str = get_next_line(fd);
	temp = ft_strtrim(str, "\n");
	free(str);
	return (temp);
}

static bool	is_dot_ber(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] == 'r' && file[i - 2] == 'e'
		&& file[i - 3] == 'b' && file[i - 4] == '.')
		return (true);
	return (false);
}

static bool	main_loop(int fd)
{
	int		i;
	char	*str;
	size_t	size;

	str = next_str(NULL, fd);
	size = ft_strlen(str);
	while (str != NULL)
	{
		if (size != ft_strlen(str))
			return (quit(fd, str));
		i = 0;
		while (str[i])
		{
			if (str[i] == '0' || str[i] == '1' || str[i] == 'C'
				|| str[i] == 'E' || str[i] == 'P')
				i++;
			else
				return (quit(fd, str));
		}
		str = next_str(str, fd);
	}
	if (str != NULL)
		free(str);
	close(fd);
	return (true);
}

bool	validate_map(char	*file)
{
	int			fd;
	char		*file_trim;

	fd = 0;
	file_trim = ft_strtrim(file, " ");
	if (is_dot_ber(file) == false)
		return (quit(fd, file_trim));
	fd = open(file_trim, O_RDONLY);
	if (fd == -1)
	{
		free(file_trim);
		return (quit(fd, NULL));
	}
	if (main_loop(fd) == false)
	{
		free(file_trim);
		return (quit(fd, NULL));
	}
	close(fd);
	free(file_trim);
	return (true);
}
