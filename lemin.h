/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:44:43 by astepano          #+#    #+#             */
/*   Updated: 2017/06/12 16:44:44 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define FD 0
# define MAP_SIZE 80
# define INFINITY 100000

# include "libft/libft.h"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_ant
{
	int			name;
	int			way;
	int			move;
}				t_ant;

typedef struct	s_way
{
	int			*way;
	int			len;
	int			ants;
}				t_way;

typedef struct	s_room
{
	char		*name;
	int			coord_x;
	int			coord_y;
}				t_room;

typedef struct	s_link
{
	int			room1;
	int			room2;
}				t_link;

typedef struct	s_diff
{
	int			*ways;
	int			len;
}				t_diff;

typedef struct	s_info
{
	int			ants_count;
	int			start;
	int			end;
	t_room		**rooms;
	t_link		**links;
	t_way		**ways;
	t_way		**all_ways;
	t_ant		**ants;
	t_diff		**diffs;
	char		**input;
	int			**matrix;
	int			size;
	int			put_map;
	int			put_moves;
	int			put_ways;
	int			put_all_ways;
	int			put_hide;
	int			put_clean;
	int			put_ant_moves;
	int			put_ants;
}				t_info;

int				iscommand(char *str);
int				iscomment(char *str);
int				isint(char *str);
int				room_exist(t_info *in, char **arr);
t_info			*create_info(char **file);
char			**read_file(void);
void			output_file(t_info *in, char **file, int last_line);
int				add_link(t_info *in, int room1, int room2);
int				add_room(t_info *in, char **arr);
int				add_way(t_info *in, int *way, int len);
int				add_command(t_info *in, int i, int room);
int				add_diff(t_info *in, int *arr, int maxlen);
int				parse_input(t_info *in);
void			output_all_ways(t_info *in);
void			output_ways(t_info *in);
void			output_result(t_info *in, int last, char **file);
int				output_ant_moves(t_info *in);
void			output_res(t_info *in, int moves, int **am);
void			create_ants(t_info *in, int last);
int				remove_all(t_info *in);
int				find_all_ways(t_info *in, int last);
void			get_best_ways(t_info *in, int last);
void			build_matrix(t_info *in);
void			find_diffs(t_info *in, int last);
void			parse_commands(t_info *in, int last_line, char **file);
int				visu_diagonal_line(t_room *r1, t_room *r2, char **map);
int				visu_check(int y, int x, char **map);
int				visu_check_left(int y, int x, char **map);
int				visu_check_right(int y, int x, char **map);
int				visu_put_link(t_info *in, char **map, t_link *link);
void			visu_put_map(t_info *in);
void			visu_add_lines(int *links, t_info *in, char **map);
int				visu_rdd(int x, t_room *r1, t_room *r2, char **map);
int				visu_rud(int x, t_room *r1, t_room *r2, char **map);
int				visu_ldd(int x, t_room *r1, t_room *r2, char **map);
int				visu_lud(int x, t_room *r1, t_room *r2, char **map);

#endif
