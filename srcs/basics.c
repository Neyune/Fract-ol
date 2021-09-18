
#include "fract-ol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[i] == s2[j] && s1[i] != '\0' && s2[j] != '\0')
	{
		i++;
		j++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

int	ft_strisdigit(char *c)
{
	int	i;

	i = 0;
	if (c == NULL)
		return (0);
	if (c[i] == '-' || c[i] == '+')
		i++;
	while (c[i] && c[i] >= '0' && c[i] <= '9')
		i++;
	if (c[i] == ',' || c[i] == '.')
		i++;
	while (c[i] && c[i] >= '0' && c[i] <= '9')
		i++;
	if (c[i])
		return (0);
	return (1);
}

static double dec_part(double nb, char *str, int i)
{
	int	j;
	
	j = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	while (j < i)
	{
		nb /= 10;
		i--;
	}
	return (nb);
}

double	ft_atof(char *str)
{
	double	negatif;
	int		i;
	double	nb;

	negatif = 1;
	i = 0;
	nb = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		negatif = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == ',' || str[i] == '.')
		i++;
	nb = dec_part(nb, str, i);
	return (nb * negatif);
}