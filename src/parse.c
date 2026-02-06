/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:24:21 by sevyesil          #+#    #+#             */
/*   Updated: 2025/11/26 22:25:15 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static char	*process_row(char *ptr, t_map *map, int row)
{
	int	len;
	int	j;

	len = get_line_length(ptr);
	if (len != map->cols)
		return (NULL);
	j = 0;
	while (j < map->cols)
	{
		if (ptr[j] != map->empty && ptr[j] != map->obs)
			return (NULL);
		map->map_data[row][j] = ptr[j];
		j++;
	}
	map->map_data[row][j] = '\0';
	ptr += map->cols;
	if (*ptr == '\n')
		ptr++;
	else if (row < map->rows - 1)
		return (NULL);
	return (ptr);
}

int	parse_map_body(char *content, t_map *map)
{
	int		i;
	char	*ptr;

	ptr = skip_first_line(content);
	if (!ptr)
		return (0);
	map->cols = get_line_length(ptr);
	if (map->cols == 0)
		return (0);
	map->map_data = allocate_map_data(map->rows, map->cols);
	if (!map->map_data)
		return (0);
	i = 0;
	while (i < map->rows)
	{
		ptr = process_row(ptr, map, i);
		if (!ptr)
			return (0);
		i++;
	}
	return (1);
}

int	get_first_line_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

int	parse_first_line(char *line, t_map *map)
{
	char	obs;
	char	empty;
	char	full;
	int		len;

	len = get_first_line_len(line);
	if (len < 4)
	{
		return (0);
	}
	empty = line[len - 3];
	obs = line[len - 2];
	full = line[len - 1];
	if (!are_chars_valid(empty, obs, full))
	{
		return (0);
	}
	return (fl_compleate(map, line));
}

int	fl_compleate(t_map *map, char *line)
{
	int		len;
	char	obs;
	char	empty;
	char	full;
	int		rows;

	len = get_first_line_len(line);
	empty = line[len - 3];
	obs = line[len - 2];
	full = line[len - 1];
	rows = str_to_positive_int(line, len - 3);
	if (rows == -1 || rows == 0)
	{
		return (0);
	}
	map->empty = empty;
	map->full = full;
	map->obs = obs;
	map->rows = rows;
	return (1);
}
