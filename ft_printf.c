/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:53:00 by nholbroo          #+#    #+#             */
/*   Updated: 2023/12/07 16:34:53 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

// #include <stdio.h>
// #include <limits.h>

// int	main()
// {
// 	int	len;
// 	int	testlen;

// 	len = ft_printf("MINE: Hello %s, how are %c? %i %% out of %u? Upper-hexa: %X Lower-Hexa: %x\n %p\n", "Natalie", 'u', 100, 4294967295U, 4294967295U, 4294967295U, "Hey");
// 	testlen = printf("TEST: Hello %s, how are %c? %i %% out of %u? Upper-hexa: %X Lower-Hexa: %x\n %p\n", "Natalie", 'u', 100, 4294967295U, 4294967295U, 4294967295U, "Hey");
// 	ft_printf("Length: %d\n", len);
// 	printf("Length: %d\n", testlen);
	// ft_printf("%p %p %p\n", 0, LONG_MAX, -1);
	// printf("%p %p %p\n", 0, LONG_MAX, -1);
	// ft_printf("MINE: Hello there\n");
	// printf("TEST: Hello there\n");
	// printf("\n\n\nHello %s %d\n");
	// ft_printf("\n\n\nHello %s %d\n");
//}


// Unsigned int max value: 4294967295
// cc ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_strlen.c ft_putuint.c ft_putpercent.c ft_puthexa_upper.c ft_puthexa_lower.c ft_putptr.c && ./a.out