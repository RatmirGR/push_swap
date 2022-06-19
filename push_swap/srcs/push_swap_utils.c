#include "../includes/push_swap.h"

long	ft_atoi(const char *nptr)
{
	int		i;
	long	sign;
	long	num;
	ssize_t	len;

	i = 0;
	len = ft_strlen(nptr);
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		++i;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = -sign;
	num = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + (nptr[i] - '0');
		++i;
	}
	if (len != i)
		num = 0;
	return (sign * num);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)&big[0]);
	i = 0;
	while (big[i] && (len--))
	{
		j = 0;
		while (big[i + j] == little[j] && (j <= len))
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			++j;
		}
		++i;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] < s2[i])
			return (-1);
		++i;
	}
	if (s1[i] != '\0')
		return (1);
	if (s2[i] != '\0')
		return (-1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		++i;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}
