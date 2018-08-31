/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umvuyisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:29:57 by umvuyisi          #+#    #+#             */
/*   Updated: 2018/08/05 21:30:01 by umvuyisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Computes the length of the string s.
*/

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}
