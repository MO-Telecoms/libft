#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t len;

	if (s == NULL)
		return ;
	len = 0;
	while (s[len] != '\0')
		len++;
	write(fd, s, len);
}
