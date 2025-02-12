/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nholbroo <nholbroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:25:21 by nholbroo          #+#    #+#             */
/*   Updated: 2025/02/12 13:02:48 by nholbroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Helper function for ft_putuint().
	Converts and prints an unsigned integer to the standard output.
	Does not take integer overflow/underflow into consideration, so the number
	should always be within unsigned int range.
	Returns the amount of digits printed.
*/
static int	ft_nbwrite(char *str, unsigned int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
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

/*
	Converts and prints an unsigned integer to the standard output.
	Does not take integer overflow/underflow into consideration, so the number
	should always be within unsigned int range.
	Returns the amount of digits printed.
*/
int	ft_putuint(unsigned int n)
{
	char	str[11];
	int		i;

	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
	return (ft_nbwrite(str, n) + i);
}
