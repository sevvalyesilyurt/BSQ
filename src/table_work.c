/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:28:47 by sevyesil          #+#    #+#             */
/*   Updated: 2025/11/26 22:29:24 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_min(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

void	fill_dp_table(int **dp, t_map *map)
{
	int	i;
	int	j;
	int	min_val;

	i = 1;
	while (i < map->rows)
	{
		j = 1;
		while (j < map->cols)
		{
			if (map->map_data[i][j] == map->obs)
				dp[i][j] = 0;
			else if (map-> map_data[i][j] == map->empty)
			{
				min_val = ft_min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
				dp[i][j] = min_val + 1;
			}
			j++;
		}
		i++;
	}
}

int	ft_is_printable(char c)
{
	return (c <= 126 && c >= 32);
}
