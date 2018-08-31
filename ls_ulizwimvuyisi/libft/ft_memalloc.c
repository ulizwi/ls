/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umvuyisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:26:35 by umvuyisi          #+#    #+#             */
/*   Updated: 2018/08/05 21:27:20 by umvuyisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates with malloc() and returns a “fresh” memory area. The memory
** allocated is initialized to 0.
** If the allocation fails, the function returns NULL.
*/

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;

	ptr = NULL;
	if (size)
	{
		if (!(ptr = (unsigned char *)malloc(size)))
			return (NULL);
		while (size)
			ptr[--size] = 0;
	}
	return ((void *)ptr);
}
