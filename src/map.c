/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:26:10 by sevyesil          #+#    #+#             */
/*   Updated: 2025/11/26 22:43:34 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		write(1, map->map_data[i], map->cols);
		write(1, "\n", 1);
		i++;
	}
}

char	*skip_first_line(char *content)
{
	int	i;

	i = 0;
	while (content[i] && content[i] != '\n')
	{
		i++;
	}
	if (content[i] == '\0')
	{
		return (NULL);
	}
	return (content + i + 1);
}

char	**allocate_map_data(int rows, int cols)
{
	char	**map_data;
	int		i;

	map_data = (char **)malloc(sizeof(char *) * rows);
	if (!map_data)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		map_data[i] = (char *)malloc(sizeof(char) * (cols + 1));
		if (!map_data[i])
		{
			free_map_data(map_data, i);
			return (NULL);
		}
		i++;
	}
	return (map_data);
}

void	free_map_data(char **map_data, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(map_data[i]);
		i++;
	}
	free(map_data);
}

int	solve_map(t_map *map)
{
	int	**dp;

	dp = allocate_dp(map->rows, map->cols);
	if (!dp)
		return (0);
	init_dp_borders(dp, map);
	fill_dp_table(dp, map);
	map->square = find_max_square(dp, map);
	free_dp(dp, map->rows);
	if (map->square.size > 0)
		mark_square(map);
	return (1);
}
