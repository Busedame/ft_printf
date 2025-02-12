/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:53:00 by nholbroo          #+#    #+#             */
/*   Updated: 2025/02/12 13:08:50 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Takes a format type (s for string, c for char, etc.), and calls a function 
	to write the value to the standard output, depending on the type.
	Returns the amount of characters written.
	@param frmt_tp Format type (type identifier). For more info about the
	different types, check this repo's README.
	@param argv The current argument of the list ("..." from ft_printf() 
	function).
*/
static int	ft_putargv(char frmt_tp, va_list argv)
{
	if (frmt_tp == 'c')
		return (ft_putchar(va_arg(argv, int)));
	if (frmt_tp == 's')
		return (ft_putstr(va_arg(argv, char *)));
	if (frmt_tp == 'd' || frmt_tp == 'i')
		return (ft_putnbr(va_arg(argv, int)));
	if (frmt_tp == 'u')
		return (ft_putuint(va_arg(argv, unsigned int)));
	if (frmt_tp == 'X')
		return (ft_puthexa_upper(va_arg(argv, unsigned int)));
	if (frmt_tp == 'x')
		return (ft_puthexa_lower(va_arg(argv, unsigned int)));
	if (frmt_tp == 'p')
		return (ft_putptr(va_arg(argv, unsigned long int)));
	return (0);
}

/*
Prints to the standard output.

@param txt The text to be printed (including type identifiers, like '%s', '%d', 
etc).
@param ... The value of the type identifiers (if any). E.g. if a '%s' is defined
in the 'txt' string, a corresponding string is expected as a value in '...'. The
'...' format makes it possible to receive an undefined amount of arguments.

Example usage: ft_printf("%s\n", "Hello, world!");

Return value: 
Upon success, returns amount of characters printed.
Upon error, returns -1.
*/
int	ft_printf(const char *txt, ...)
{
	va_list	argv;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(argv, txt);
	if (!txt)
		return (-1);
	while (txt[i] != '\0')
	{
		if (txt[i] == '%' && txt[i + 1] == '%')
		{
			count += ft_putpercent();
			i++;
		}
		else if (txt[i] == '%')
			count += ft_putargv(txt[++i], argv);
		else
			count += ft_putchar(txt[i]);
		i++;
	}
	va_end(argv);
	return (count);
}

/*
int	main()
{
	int	len;
	int	testlen;

	len = ft_printf("MY FUNCTION: Hello %s, how are %c? %i %% out of %u? Upper-hexa: %X Lower-Hexa: %x\n %p\n", "Natalie", 'u', 100, 4294967295U, 4294967295U, 4294967295U, "Hey");
	testlen = printf("OR FUNCTION: Hello %s, how are %c? %i %% out of %u? Upper-hexa: %X Lower-Hexa: %x\n %p\n", "Natalie", 'u', 100, 4294967295U, 4294967295U, 4294967295U, "Hey");
	ft_printf("MY FUNCTION, length: %d\n", len);
	printf("OR FUNCTION, length: %d\n", testlen);
	ft_printf("MY FUNCTION: %p %p %p %p\n", 0, LONG_MAX, -1, "Hello\n");
	printf("OR FUNCTION: %p %p %p %p\n", 0, LONG_MAX, -1, "Hello\n");
}
*/