#include "libft.h"

char	*ft_readfd(int fd)
{
	ssize_t	size;
	char	buffer[BUFF_SIZE + 1];
	char	*result;

	result = NULL;
	while ((size = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[size] = '\0';
		if (result == NULL)
			result = ft_strdup("");
		result = ft_strfjoin(result, buffer, FIRST);
	}
	return (result);
}
