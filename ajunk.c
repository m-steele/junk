#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static char *ft_to_ascii(int n)
{
    char    *str;
    int     nums;
    int     temp;

	nums = 0;
    temp = n;
    while (temp != 0)
    {
        nums++;
        temp /= 10;
    }
    str = (char *)malloc((nums + 1) * sizeof(char));
	if (!str)
		return (NULL);
    str[nums--] = '\0';
    while (n > 0)
    {
        str[nums--] = (n % 10) + '0';
        n /= 10;
    }
    return (str);
}

static char*	ft_neg_ascii(int n)
{
	char 	*str;
	char 	*neg;
	
	if (n < 0)
		n = n * -1;
	neg = ft_to_ascii(n);
	if (!neg)
		return (NULL);
	str = (char *)malloc(ft_strlen(neg) + 2);
	if (!str)
	{
		free(neg);
		return (str);
	}
	str[0] = '-';
	str = ft_strjoin(str, neg);
	free (neg);
		return (str);
}

static char *ft_zero_ascii(int n)
{
	char	*str;

	if (n == -2147483648)
	{
		str = (char *)malloc((12) * sizeof(char));
		str = "-2147483648";
			return (str);
	}
	else
		str = (char *)malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
			return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*neg;

	if (n == 0 || n == -2147483648)
		return (ft_zero_ascii(n));
	else if (n > 0)
	{
		str = ft_to_ascii(n);
		return (str);
	}
	else if (n < 0)
	{
		str = ft_neg_ascii(n);
		return (str);
	}
		else
			return (NULL);
}

int main()
{
	int n = 2147483647;
	printf("Number 1235 is: %s\n", ft_itoa(n));
	return (0);
}