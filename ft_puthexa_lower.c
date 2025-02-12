/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:34:49 by nholbroo          #+#    #+#             */
/*   Updated: 2025/02/12 13:03:58 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Converts and prints a number in lowercase hexadecimal format to 
	the standard output.
	Does not take integer overflow/underflow into consideration, so the number
	should always be within unsigned int range.
	Returns the amount of digits printed.
*/
int	ft_puthexa_lower(unsigned int n)
{
	char	str[9];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		if (n % 16 < 10)
			str[i] = n % 16 + '0';
		else
			str[i] = (n % 16) % 10 + 'a';
		n /= 16;
		i++;
	}
	str[i--] = '\0';
	while (i >= 0)
	{
		write(1, &str[i--], 1);
		count++;
	}
	return (count);
}
