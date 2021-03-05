#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int ft_strlen(char *s) {
	return((*s != 0) ? ft_strlen(++s)  + 1 : 0 );
}

char    *remalloc(char *s, char c)
{
	char    *str;
	int        x = -1;
	int        i = ft_strlen(s);

	str = malloc(sizeof(char) * (i + 2));
	while (++x < i)
		str[x] = s[x];
	free(s);
	str[i] = c;
	str[i + 1] = 0;
	return (str);
}

int    get_next_line(char **line)
{
	char            c;
	int                x;

	if (line == NULL)
		return (-1);
	*line = malloc(sizeof(char) * 1);
	(*line)[0] = 0;

	while((x = read(0, &c, 1)) >= 0 )
	{
		if (x == 0 || c == '\n')
			return ((x == 0) ? 0 : 1);
		*line = remalloc(*line, c);
	}
	free(*line);
	return -1;
}
