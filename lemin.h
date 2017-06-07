/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 01:43:06 by astepano          #+#    #+#             */
/*   Updated: 2017/04/02 01:43:08 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

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
	t_ant		**ants;
	t_diff		**diffs;
	char		**input;
	int			**matrix;
	int			size;
}				t_info;

int				iscommand(char *str);
int				iscomment(char *str);
int				isint(char *str);
int				room_exist(t_info *in, char **arr);
char			**clean_input(char **file);
t_info			*create_info(char **file);
char			**read_file(void);
void			write_file(char **file, int last_line);
int				add_link(t_info *in, int room1, int room2);
int				add_room(t_info *in, char **arr);
int				add_way(t_info *in, int *way, int len);
int				add_command(t_info *in, int i, int room);
int				parse_input(t_info *in);
void			output_ways(t_info *in);
int				print_ants(t_info *in);
void			create_ants(t_info *in);
int				remove_all(t_info *in);
int				find_all_ways(t_info *in, int last);
void			get_best_ways(t_info *in);
void			build_matrix(t_info *in);
int				visu_diagonal_line(t_room *r1, t_room *r2, char **map);
int				visu_check(int y, int x, char **map);
int				visu_check_left(int y, int x, char **map);
int				visu_check_right(int y, int x, char **map);
void			visu_put_link(t_info *in, char **map, t_link *link);
void			visu_put_map(t_info *in);

#endif
