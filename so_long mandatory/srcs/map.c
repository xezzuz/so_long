/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:06:16 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/24 14:17:53 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	ft_count_lines(int fd)
{
	char	*line;
	int		lines;

	lines = 0;
	line = ft_calloc(2, 1);
	while (read(fd, line, 1) > 0)
	{
		if (line [0] == '\n')
			lines++;
		line[0] = '\0';
	}
	free (line);
	close (fd);
	return (lines + 1);
}

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
		= malloc((game_cp->m_data.lines + 1) * sizeof(char *));
	if (!game_cp->m_data.matrix)
		ft_exit_program(game_cp, 1);
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
		{
			close(fd);
			break ;
		}
		game_cp->m_data.matrix[i++] = buffer;
	}
	game_cp->m_data.matrix[i] = NULL;
	ft_null_term_matrix(game_cp->m_data.matrix);
	ft_is_valid_map(game_cp);
	return (1);
}

int	ft_read_map(char *map_name, t_game_ctl *game_cp)
{
	int			fd;

	if (!ft_check_map_x(map_name))
		ft_exit_program(game_cp, -1);
	fd = open (map_name, O_RDONLY);
	if (fd == -1)
		ft_exit_program(game_cp, 2);
	game_cp->m_data.lines = ft_count_lines(fd);
	if (game_cp->m_data.lines < 3)
		ft_exit_program(game_cp, -3);
	fd = open (map_name, O_RDONLY);
	if (fd == -1)
		ft_exit_program(game_cp, 2);
	ft_read_and_stock(fd, game_cp);
	return (close (fd), 1);
}
