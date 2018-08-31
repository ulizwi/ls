/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umvuyisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:29:31 by umvuyisi          #+#    #+#             */
/*   Updated: 2018/08/05 21:30:07 by umvuyisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the unsigned integer n to the standard output.
*/

void	ft_putunbr(uintmax_t n)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		ft_putchar(c);
	}
	else
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
}
