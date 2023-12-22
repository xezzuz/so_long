/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:06:16 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/22 21:39:50 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// CHECKS IF THE MAP DIMENSION, SHAPE, CHARACTERS ARE VALID
int	ft_is_valid_map(t_game_ctl *game_cp)
{
	if (!game_cp->m_data.matrix[0]
		|| !ft_map_dimensions(game_cp)
		|| !ft_map_objs(game_cp))
		ft_exit_program(game_cp, -3);
	else if (!ft_valid_path(game_cp))
		ft_exit_program(game_cp, 3);
	return (1);
}

// COUNTS HOW MANY LINES THE MAP CONTAINS
int	ft_count_lines(char *map_name)
{
	int		fd;
	int		i;
	char	line[1024];
	int		lines;

	fd = open (map_name, O_RDONLY);
	if (fd == -1)
		ft_exit_program(NULL, 2);
	lines = 1;
	while (read(fd, line, 1024) > 0)
	{
		i = 0;
		while (line[i])
		{
			if (line [i] == '\n')
				lines++;
			line[i] = '\0';
			i++;
		}
	}
	close(fd);
	return (lines);
}

// CHECKS IF THE MAP FILE EXTENSION IS .BER
int	ft_check_map_x(char *map_name)
{
	int		len;

	len = ft_strlen(map_name);
	if (len < 5)
		return (0);
	while (*map_name != '\0')
		map_name++;
	if (ft_strncmp(".ber", map_name - 4, 4) != 0)
		return (0);
	return (1);
}

int	ft_read_and_stock(int fd, t_game_ctl *game_cp)
{
	char	*buffer;
	int		i;

	i = 0;
	game_cp->m_data.matrix
		= ft_calloc(game_cp->m_data.lines + 1, sizeof(char *));
	if (!game_cp->m_data.matrix)
		ft_exit_program(game_cp, 1);
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		game_cp->m_data.matrix[i] = buffer;
		if (i != game_cp->m_data.lines - 1)
			game_cp->m_data.matrix[i][ft_strlen(buffer) - 1] = '\0';
		i++;
	}
	game_cp->m_data.matrix[i] = NULL;
	ft_is_valid_map(game_cp);
	return (1);
}

int	ft_read_map(char *map_name, t_game_ctl *game_cp)
{
	int			fd;

	if (ft_check_map_x(map_name) == 0)
		ft_exit_program(NULL, -1);
	fd = open (map_name, O_RDONLY);
	if (fd == -1)
		ft_exit_program(NULL, 2);
	game_cp->m_data.lines = ft_count_lines(map_name);
	if (game_cp->m_data.lines < 3
		|| game_cp->m_data.lines == 0)
	{
		ft_exit_program(game_cp, -3);
	}
	ft_read_and_stock(fd, game_cp);
	return (close (fd), 1);
}
