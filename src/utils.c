/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:35:20 by sevyesil          #+#    #+#             */
/*   Updated: 2025/11/26 22:43:38 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	are_chars_valid(char empty, char obs, char full)
{
	if (!(ft_is_printable(empty)
			&& ft_is_printable(obs)
			&& ft_is_printable(full)))
		return (0);
	else if (empty == obs || empty == full || obs == full)
		return (0);
	return (1);
}

int	str_to_positive_int(char *str, int len)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (i < len)
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
		{
			return (-1);
		}
		else
		{
			nb = nb * 10 + (str[i] - '0');
		}
		i++;
	}
	return (nb);
}

int	get_clean_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	if (i > 0 && str[i - 1] == '\n')
	{
		i--;
	}
	return (i);
}

int	get_line_length(char *map_start)
{
	int	i;

	i = 0;
	while (map_start[i] && map_start[i] != '\n')
		i++;
	return (i);
}

t_square	find_max_square(int **dp, t_map *map)
{
	t_square	result;
	int			i;
	int			j;

	result.size = 0;
	result.row = 0;
	result.col = 0;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (dp[i][j] > result.size)
			{
				result.size = dp[i][j];
				result.row = i;
				result.col = j;
			}
			j++;
		}
		i++;
	}
	return (result);
}
