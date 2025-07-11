#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while(begin_list != NULL)
	{
		if (begin_list != NULL)
			(*f)(begin_list->data);
		else
			begin_list = begin_list->next;
	}
}

// void print_bits(unsigned char octet)
// {
// 	int i = 8;
// 	unsigned char bit;

// 	while (i--)
// 	{
// 		bit = (octet >> i & 1) + '0';
// 		write(1, &bit, 1);
// 	}
// }

// unsigned char swap_bits(unsigned char octet)
// {
// 	return ((octet >> 4 | octet << 4));
// }

// unsigned char revbits(unsigned char octect)
// {
// 	int i = 8;
// 	unsigned char res = 0;

// 	while (i--)
// 	{
// 		res = (res << 1 | octect & 1);
// 		octect = octect >> 1;
// 	}
// 	return (res);
// }

// int main()
// {
// 	unsigned char num = 111;
	
// 	print_bits(num);
// 	print_bits(revbits(num));
// 	return (0);
// }

// void print_hex(int nmb)
// {
// 	char hexator[] = "0123456789abcdef";

// 	if (nmb >= 16)
// 		print_hex(nmb / 16);
// 	nmb = hexator[nmb % 16];
// 	write(1, &nmb, 1);
// }

// int main(int ac, char **av)
// {
// 	if (ac == 2)
// 		print_hex(ft_atoi(av[1]));
// 	write(1, "\n", 1);
// 	return (0);
// }

// typedef struct s_list
// {
// 	struct s_list	*next;
// 	void			*data;
// }					t_list;


// void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
// {
// 	while (begin_list != NULL)
// 	{
// 		if (begin_list->data != NULL)
// 			(*f)(begin_list->data);
// 		 begin_list =  begin_list->next;
// 	}
// }


// void rotstr(char *av)
// {
// 	int i = 0;

// 	while (av[i] && av[i] == ' ' || av[i] == '\t') /*skip over white space if exists*/
// 		i++;
// 	while (av[i] && av[i] != ' ' && av[i] != '\t') /*skip over first word*/
// 		i++;
// 	while (av[i] && av[i] == ' ' || av[i] == '\t') /*skip over white space*/
// 		i++;
// 	while (av[i])
// 	{
// 		if (av[i] != ' ' && av[i] != '\t') /*write each character*/
// 		{
// 			write(1, &av[i], 1);
// 			i++;
// 		}
// 		else
// 		{
// 			write(1, " ", 1); /* make space*/
// 			while (av[i] && av[i] == ' ' || av[i] == '\t') /*skip over white space*/
// 				i++;
// 		}
// 	}
// 	i = 0;
// 	while (av[i] && av[i] == ' ' || av[i] == '\t') /*skip over white space if exists*/
// 		i++;
// 	while (av[i] && av[i] != ' ' && av[i] != '\t') /*skip over first word*/
// 		{
// 			write(1, &av[i], 1);
// 			i++;
// 		}
// }

// int main(int ac, char **av)
// {
// 	if (ac > 1)
// 		rotstr(av[1]);
// 	write(1, "\n", 1);
// 	return (0);
// }


// void sort_int_tab(int *tab, unsigned int size)
// {
// 	int sorted = 0;
// 	int temp = 0;
// 	int i;

// 	while (sorted < size)
// 	{
// 		i = 0;
// 		while (i < size - 1)
// 		{
// 			if (tab[i] < tab[i + 1])
// 				i++;
// 			else
// 			{
// 				temp = tab[i];
// 				tab[i] = tab[i + 1];
// 				tab[i + 1] = temp;
// 				i++;
// 			}
// 		}
// 		sorted++;
// 	}
// }

// unsigned int lcm(unsigned int a, unsigned int b)
// {
// 	unsigned int i = 0;

// 	if (a == 0 | b == 0)
// 		return (0);
// 	if (a > b)
// 		i = a;
// 	else
// 		i = b;
// 	printf("a = %i, b = %i, i = %i\n", a, b, i);
// 	if (i % a == 0 && i % b == 0)
// 		return (i);
// 	while (i)
// 		{
// 			i++;
// 			if (i % a == 0 && i % b == 0)
// 				return (i);
// 		}
// }

// unsigned char swap_bits(unsigned char octet)
// {
// 	return ((octet >> 4 | octet << 4));
// }

// int main(int ac, char **av)
// {
// 	int i = 0;
// 	int j = 0;
// 	int k = 0;
// 	int len = 0;

// 	if (ac == 3)
// 	{
// 		while (av[1][i])
// 		{
// 			len++;
// 			i++;
// 		}
// 		i = 0;
// 		while (i < len && av[2][j])
// 		{
// 			if (av[1][i] == av[2][j++])
// 				i++;
// 			if (i == len)
// 				while (av[1][k])
// 					write(1, &av[1][k++], 1);
// 		}
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }


// int	ft_strlen(char *str)
// {
// 	int i = 0;

// 	while (str[i])
// 		i++;
// 	return (i);
// }

// int main(int ac, char **av)
// {
// 	int i = 0;
// 	int end = 0;

// 	if (ac == 2)
// 	{
// 		i = ft_strlen(av[1]) - 1;
// 		while (av[1][i] == ' ' || av[1][i] == '\n' || av[1][i] == '\t')
// 			i--;
// 		end = i;
// 		while (av[1][i] != ' ' && av[1][i] != '\n' && av[1][i] != '\t')
// 			i--;
// 		i++;
// 		while (i <= end)
// 		{
// 			write(1, &av[1][i], 1);
// 			i++;
// 		}
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }


// int	ft_isprime(int n)
// {
// 	int i = 2;
// 	while (i <= n / 2)
// 	{
// 		if (n % i == 0)
// 			return(0);
// 		i++;
// 	}
// 	return (1);
// }

// void ft_putnum(int n)
// {
// 	char c;

// 	if (n >= 10)
// 		ft_putnum(n / 10);
// 	c = n % 10 + '0';
// 	write(1, &c, 1);
// }

// int main(int ac, char **av)
// {
// 	int i = 0;
// 	int n = 0;
// 	int sum = 0;

// 	if (av[1][i] < '1' || av[1][i] > '9' || ac != 2)
// 		return(write(1, "0\n", 2));
// 	if (av[1][i] == '1' && av[1][1] == '\0')
// 		return(write(1, "0\n", 2));
// 	while (av[1][i])
// 	{
// 		if (av[1][i] >= '0' && av[1][i] <= '9')
// 			n = n * 10 + (av[1][i] - '0');
// 		else
// 			return(write(1, "0\n", 2));
// 		i++;
// 	}
// 	while (n > 1)
// 	{
// 		if (ft_isprime(n))
// 			sum += n;
// 		n--;
// 	}
// 	ft_putnum(sum);
// 	write(1, "\n", 1);
// 	return (0);
// }

// int main(int ac, char **av)
// {
// 	int i = 0;

// 	while (av[1][i])
// 	{
// 		if (av[1][i] >= 65 && av[1][i] <= 90)
// 		{
// 			write(1, "_", 1);
// 			av[1][i] += 32;
// 		}
// 		write(1, &av[1][i], 1);
// 		i++;
// 	}
// 	write(1, "\n",1);
// 	return(0);
// }


// char	*rev_print(char *str)
// {
// 	char *rev;

// 	rev = malloc(sizeof(char) * strlen(str) + 1);

// 	free
// }


/*NOTE the recursion for this function is kind of wanky
you recurse through the number, before writing the character for it
seems that the number should come out in reverse instead, but does not
void putnum(int i)
{
	if (i > 9)
		putnum(i/10);
	write(1, &"0123456789"[i%10], 1);
}
*/

/*
gcc -g -O0 your_program.c -o your_program

break main
run
next     # Step to next line in the same function
step     # Step into a function
echo Return value is $?.\n

| Command                 | What it does                                      |
| ----------------------- | ------------------------------------------------- |
| `break main`            | Set a breakpoint at `main()`                      |
| `break filename.c:line` | Break at a specific line                          |
| `next`                  | Step over to the next line                        |
| `step`                  | Step into functions                               |
| `continue`              | Continue execution until next breakpoint or crash |
| `print var`             | Print variable                                    |
| `bt`                    | Print backtrace                                   |
*/

// void print_bits(unsigned char octet)
// {
// 	int i = 8;
// 	unsigned char n = 0;

// 	while (i--)
// 	{
// 		n = (octet >> i & 1) + '0';
// 		write(1, &n, 1);
// 	}
// }