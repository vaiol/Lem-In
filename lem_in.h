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
# define INFINITY 100000

# include "libft/libft.h"

typedef struct	s_way
{
	int			*way;
	int			len;
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

typedef struct	s_info
{
	int			ants;
	int			start;
	int			end;
	t_room		**rooms;
	t_link		**links;
	t_way		**ways;
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
int				add_way(t_info *in, int *way, int distance);
int				add_command(t_info *in, int i, int room);
int				parse_input(t_info *in);
void			build_matrix(t_info *in);
int				find_ways(t_info *in, int last);
void			remove_vertices(t_info *in, int w);
int				remove_all(t_info *in);
void			remove_additional(int *paste, int *distance, int *way);

#endif
