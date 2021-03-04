#include <libc.h>
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
	printf("%d\n",i);
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

int ret_line(char **line, char *s, int i, int *x)
{
	int j = 0;
	while(s[i] != 0 && s[i] != '\n')
	{
		(*line)[j] = s[i];
		j++;
		i++;
	}
	*x = 1;
	if (s[i] == 0)
		*x = 0;
	return (i + 1);
}

int	get_next_line(char **line)
{
	static char *s = NULL;
	static int i = 0;
	char			c;
	int				x;

	if(s == NULL)
	{
		s = malloc(sizeof(char *) * 1);
		s[0] = 0;
	}
	if (line == NULL)
		return (-1);
	if (i == 0)
	{
		while((x = read(0, &c, 1)) > 0)
			s = remalloc(s, c);
	}
	printf("coucou\n");
	i = ret_line(line, s, i, &x);
	printf("%d\n %s\n",x, *line);
	return (x);
}

