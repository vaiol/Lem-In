#include "lem-in.h"

void	error(void)
{
	ft_printf("ERROR\n");
	exit(1);
}

int		iscommand(char *str)
{
	if (ft_strequ(str, "##start") || ft_strequ(str, "##end"))
		return (1);
	return (0);
}

int		iscomment(char *str)
{
	if (str[0] == '#' && !iscommand(str))
		return (1);
	return (0);
}

int		isint(char *str)
{
	unsigned int	result;
	int				minus;
	size_t			i;

	i = 0;
	minus = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		   || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		minus = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	result = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		result = result * 10 + (str[i] - 48);
		if (result >= 2147483648 || (result > 2147483648 && minus))
			return (0);
		i++;
	}
	return (1);
}

int		get_room(t_info *in, char *name)
{
	int	i;

	if (in->rooms == NULL)
		return (-1);
	i = 0;
	while (in->rooms[i])
	{
		if (ft_strequ(in->rooms[i]->name, name))
			return (i);
		i++;
	}
	return (-1);
}

int		add_link(t_info *in, int room1, int room2)
{
	t_link	**links;
	int		i;
	int		len;

	len = 0;
	while (in->links && in->links[len])
		len++;
	links = (t_link **)malloc(sizeof(t_link *) * (len + 2));
	i = 0;
	while (i < len)
	{
		links[i] = in->links[i];
		i++;
	}
	links[i] = (t_link *)malloc(sizeof(t_link));
	links[i]->room1 = room1;
	links[i]->room2 = room2;
	links[i + 1] = NULL;
	if (in->links)
		free(in->links);
	in->links = links;
	return (i);
}

int		parse_link(t_info *in, int i)
{
	int		room1;
	int		room2;
	int		count;
	char	**arr;

	arr = ft_strsplit(in->input[i], '-');
	count = 0;
	while (arr[count])
		count++;
	if (count != 2)
	{
		ft_arrdel(arr);
		return (0);
	}
	room1 = get_room(in, arr[0]);
	room2 = get_room(in, arr[1]);
	ft_arrdel(arr);
	if (room1 < 0 || room2 < 0)
		return (0);
	add_link(in, room1, room2);
	return (1);
}

int		add_room(t_info *in, char **arr)
{
	t_room	**rooms;
	int		i;
	int		len;

	len = 0;
	while (in->rooms && in->rooms[len])
		len++;
	rooms = (t_room **)malloc(sizeof(t_room *) * (len + 2));
	i = 0;
	while (i < len)
	{
		rooms[i] = in->rooms[i];
		i++;
	}
	rooms[i] = (t_room *)malloc(sizeof(t_room));
	rooms[i]->name = ft_strdup(arr[0]);
	rooms[i]->coord_x = ft_atoi(arr[1]);
	rooms[i]->coord_y = ft_atoi(arr[2]);
	rooms[i + 1] = NULL;
	if (in->rooms)
		free(in->rooms);
	in->rooms = rooms;
	return (i);
}

int		add_command(t_info *in, int i, int room)
{
	if (ft_strequ(in->input[i - 1] + 2, "start"))
	{
		if (in->start != -1)
			return (0);
		in->start = room;
		return (1);
	}
	else if (ft_strequ(in->input[i - 1] + 2, "end"))
	{
		if (in->end != -1)
			return (0);
		in->end = room;
		return (1);
	}
	return (0);
}

int 	room_exist(t_info *in, char **arr)
{
	int		i;
	char	*name;
	int		x;
	int		y;

	if (in->rooms == NULL)
		return (0);
	name = arr[0];
	x = ft_atoi(arr[1]);
	y = ft_atoi(arr[2]);
	i = 0;
	while (in->rooms[i])
	{
		if (ft_strequ(name, in->rooms[i]->name))
			return (1);
		if (x == in->rooms[i]->coord_x && y == in->rooms[i]->coord_y)
			return (1);
		i++;
	}
	return (0);
}

int		parse_room(t_info *in, int i)
{
	int		room;
	int		count;
	char	**arr;

	arr = ft_strsplit(in->input[i], ' ');
	count = 0;
	while (arr[count])
		count++;
	if (count != 3 || arr[0][0] == 'L' || ft_strcchr(arr[0], '-')
		|| !isint(arr[1]) || !isint(arr[2]) || room_exist(in, arr))
	{
		ft_arrdel(arr);
		return (0);
	}
	room = add_room(in, arr);
	ft_arrdel(arr);
	if (iscommand(in->input[i - 1]))
		return (add_command(in, i, room));
	return (1);
}

int		parse_ant(t_info *in)
{
	in->ants = ft_atoi(in->input[0]);
	if (in->ants <= 0 || !isint(in->input[0]))
		return (0);
	return (1);
}

int 	parse_input(t_info *in)
{
	int	command;
	int	i;

	if (!(i = parse_ant(in)))
		return (0);
	if (iscommand(in->input[i]))
		i++;
	command = 1;
	while (in->input[i] && parse_room(in, i))
	{
		i++;
		command = 0;
		if (iscommand(in->input[i]))
		{
			i++;
			command = 1;
		}
	}
	if (command)
		return (i);
	while (in->input[i] && parse_link(in, i))
		i++;
	return (i);
}

char	**clean_input(char **file)
{
	char	**input;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (file && file[i])
		i++;
	input = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (file[i])
	{
		if (iscommand(file[i]) && file[i + 1])
		{
			input[j++] = file[i++];
			input[j++] = file[i++];
		}
		else if (iscomment(file[i]))
			i++;
		else
			input[j++] = file[i++];
	}
	input[j] = NULL;
	return (input);
}

t_info	*create_info(char **file)
{
	t_info	*in;

	in = (t_info *)malloc(sizeof(t_info));
	in->ants = -1;
	in->start = -1;
	in->end = -1;
	in->rooms = NULL;
	in->links = NULL;
	in->input = clean_input(file);
	return (in);
}

char	**read_file(void)
{
	char	**input;
	char	*file;

	file = ft_readfd(FD);
	input = ft_strsplit(file, '\n');
	return (input);
}

void	write_file(char **file, int last_line)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (iscomment(file[i]))
			last_line++;
		if (i < last_line)
			ft_printf("%s\n", file[i]);
		free(file[i]);
		i++;
	}
	free(file);
}

int		main(void)
{
	t_info	*in;
	char	**file;
	int		l;

	file = read_file();
	in = create_info(file);
	l = parse_input(in);
	if (!l)
		error();
	write_file(file, l);
	free(in);
	char	*line;
	while (get_next_line(FD, &line))
	{
		ft_printf("%s\n", line);
		free(line);
	}
	return (0);
}
