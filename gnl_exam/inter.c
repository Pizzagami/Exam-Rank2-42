#include <unistd.h>

int main(int ac, char **av)
{
	int tab[200] = {0};
	int i = 0;
	char *s1 = av[1];
	char *s2 = av[2];
	if(ac == 3)
	{
		while(s2[i])
		{
			tab[(int)s2[i]] = 1;
			i++;
		}
		i = 0;
		while(s1[i])
		{
			if(tab[(int)s1[i]] == 1)
			{
				tab[(int)s1[i]] = 0;
				write(1, &s1[i], 1);
			}
			i++;
		}
	}
	write(1,"\n",1);
	return 0;
}
