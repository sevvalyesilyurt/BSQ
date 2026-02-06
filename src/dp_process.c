/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:31:03 by sevyesil          #+#    #+#             */
/*   Updated: 2025/11/26 23:07:34 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

int	**allocate_dp(int rows, int cols)
{
	int	**dp;
	int	i;
	int	j;

	i = 0;
	dp = (int **)malloc(rows * sizeof(int *));
	if (!dp)
		return (NULL);
	while (i < rows)
	{
		dp[i] = (int *)malloc(cols * sizeof(int));
		if (!dp[i])
		{
			j = 0;
			while (j < i)
			{
				free(dp[j]);
				j++;
			}
			free(dp);
			return (NULL);
		}
		i++;
	}
	return (dp);
}

void	init_dp_borders(int **dp, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->cols)
	{
		if (map->map_data[0][i] == map->empty)
			dp[0][i] = 1;
		else
			dp[0][i] = 0;
		i++;
	}
	j = 0;
	while (j < map->rows)
	{
		if (map->map_data[j][0] == map->empty)
			dp[j][0] = 1;
		else
			dp[j][0] = 0;
		j++;
	}
}

char	*apd_buff_ret(char *buf)
{
	free(buf);
	return (NULL);
}

char	*append_buf(char *buf, size_t blen, char *chunk, ssize_t clen)
{
	size_t	total;
	char	*newbuf;
	size_t	i;

	i = 0;
	total = blen + (ssize_t)clen + 1;
	newbuf = (char *)malloc(total);
	if (!newbuf)
		return (apd_buff_ret(buf));
	while (i < blen && buf != NULL)
	{
		newbuf[i] = buf[i];
		i++;
	}
	i = 0;
	while (i < (size_t)clen)
	{
		newbuf[i + blen] = chunk[i];
		i++;
	}
	newbuf[blen + (size_t)clen] = '\0';
	free(buf);
	return (newbuf);
}
