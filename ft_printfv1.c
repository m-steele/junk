/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:54:48 by peatjohnsto       #+#    #+#             */
/*   Updated: 2024/10/08 15:04:35 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int handle_format(char *format, va_list args)
{
	char c;
	c = va_arg(args, int);
	int in;
	in = va_arg(args, int);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int counter;

	counter = 0;
	va_start(args, format);
	while(*format)
	{
		if(*format == '%')
			format++;
			counter += handle_format(format, args);
	}
	va_end(args);
	return ret;
}

// #include <stdio.h>

// int main()
// {
// 	int result = printf("How many %s\n", "characters?");
// 	printf("%d\n\n", result);
// }