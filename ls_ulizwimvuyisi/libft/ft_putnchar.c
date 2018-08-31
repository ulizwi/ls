/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umvuyisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:26:48 by umvuyisi          #+#    #+#             */
/*   Updated: 2018/08/05 21:27:19 by umvuyisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the character c to the standard output, n number of times.
*/

void	ft_putnchar(char c, int n)
{
	while (n-- > 0)
		ft_putchar(c);
}
