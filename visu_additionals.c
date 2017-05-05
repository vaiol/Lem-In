#include "visu_hex.h"

static int		count_turns(t_vlink *vlink)
{
	int		j;
	int		count;

	if (vlink == NULL)
		return (INFINITY);
	count = 0;
	j = 0;
	while (j < vlink->len)
	{
		if (vlink->e[j] == '/' || vlink->e[j] == '\\')
			count++;
		j++;
	}
	return (count);
}

void	add_vlink(t_info *in, t_vlink *vlink)
{
	int	i;

	ft_printf("add_link: ");
	if (count_turns(in->vlink) > count_turns(vlink))
	{
		if (in->vlink == NULL)
			in->vlink = (t_vlink *)malloc(sizeof(t_vlink));
		in->vlink->end = vlink->end;
		in->vlink->len = vlink->len;
		i = 0;
		while (i <= in->vlink->len)
		{
			in->vlink->e[i] = vlink->e[i];
			in->vlink->coords[i].x = vlink->coords[i].x;
			in->vlink->coords[i].y = vlink->coords[i].y;
			i++;
		}
	}
}