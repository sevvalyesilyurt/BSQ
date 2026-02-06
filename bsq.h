/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muarici <muarici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:21:41 by muarici           #+#    #+#             */
/*   Updated: 2025/11/26 17:06:39 by muarici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_square
{
	int	row;
	int	col;
	int	size;
}	t_square;

typedef struct s_map
{
	int			rows;
	char		obs;
	char		empty;
	char		full;
	int			cols;
	char		**map_data;
	t_square	square;
}	t_map;

int			fl_compleate(t_map *map, char *line);
int			solve_map(t_map *map);
int			ft_is_printable(char c);
int			get_clean_len(char *str);
int			are_chars_valid(char empty, char obs, char full);
int			str_to_positive_int(char *str, int len);
char		*skip_first_line(char *content);
int			get_line_length(char *map_start);
char		**allocate_map_data(int rows, int cols);
void		free_map_data(char **map_data, int count);
void		fill_dp_table(int **dp, t_map *map);
int			ft_min(int a, int b, int c);
t_square	find_max_square(int **dp, t_map *map);
char		*append_buf(char *buf, size_t blen, char *chunk, ssize_t clen);
char		*read_fd_to_buffer(int fd);
char		*read_file(char *filename);
char		*read_stdin(void);
int			**allocate_dp(int rows, int cols);
void		init_dp_borders(int **dp, t_map *map);
int			parse_map_body(char *content, t_map *map);
int			parse_first_line(char *line, t_map *map);
void		print_map(t_map *map);
void		free_dp(int **dp, int rows);
void		mark_square(t_map *map);

#endif /* BSQ_H */
