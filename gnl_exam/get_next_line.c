#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return(i);
}

char	*remalloc(char *s, char c)
{
	char	*str;
	int		x = 0;
	int		i = ft_strlen(s);

	i = ft_strlen(s);
	str = malloc(sizeof(char) * (i + 2));
	while (x < i)
	{
		str[x] = s[x];
		x++;
	}
	free(s);
	str[i] = c;
	str[i + 1] = 0;
	return (str);
}

int	get_next_line(char **line)
{
	char			c;
	int				x;

	if (line == NULL)
		return (-1);
	*line = malloc(sizeof(char *) * 1);
	(*line)[0] = 0;

		while(1)
		{
			x = read(0, &c, 1);
			if (x < 0)
			{
				free(*line);
				return (-1);
			}
			if (x == 0)
				return 0;
			if (c == '\n')
				return 1;
			*line = remalloc(*line, c);
	}
}

