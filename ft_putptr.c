/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:57:33 by nholbroo          #+#    #+#             */
/*   Updated: 2025/02/12 12:59:37 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Converts and prints a pointer address to the standard output.
	The format of a pointer address will always start with "0x" followed by
	the pointer address in hexadecimal format. Like this: "0x40210a".
	If the pointer is invalid (null), it prints "(nil)" to the standard output.
	Returns the amount of digits printed.
*/
int	ft_putptr(unsigned long int n)
{
	char			str[16];
	int				i;
	int				count;

	i = 0;
	count = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	while (n > 0)
	{
		if (n % 16 < 10)
			str[i++] = n % 16 + '0';
		else
			str[i++] = (n % 16) % 10 + 'a';
		n /= 16;
	}
	str[i++] = 'x';
	str[i++] = '0';
	str[i--] = '\0';
	while (i >= 0)
	{
		write(1, &str[i--], 1);
		count++;
	}
	return (count);
}
