/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umvuyisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:29:43 by umvuyisi          #+#    #+#             */
/*   Updated: 2018/08/05 21:30:04 by umvuyisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function begins printing from the address specified (wcs) until it
** reaches the terminating null wide character.
** This terminating null wide character is not printed to the standard output.
*/

int		ft_putwstr(wchar_t *wcs)
{
	int		len;

	len = 0;
	while (*wcs)
	{
		ft_putwchar(*wcs);
		len += ft_wclen(*wcs);
		wcs += 1;
	}
	return (len);
}
