/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umvuyisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:26:27 by umvuyisi          #+#    #+#             */
/*   Updated: 2018/08/05 21:27:13 by umvuyisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if the character is a digit (number).
*/

int		ft_isdigit(int c)
{
	return (c >= '0' && '9' >= c);
}
