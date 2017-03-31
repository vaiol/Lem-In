#ifndef LEM_IN_H
# define LEM_IN_H

# define FD 0

# include "libft/libft.h"

typedef enum	s_command
{
	START,
	END
}				t_command;

typedef struct	s_room
{
	char		*name;
	int 		coord_x;
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
	char		**input;
}				t_info;

#endif
