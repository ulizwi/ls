/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umvuyisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 23:12:45 by umvuyisi          #+#    #+#             */
/*   Updated: 2018/08/30 17:12:28 by umvuyisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int		ls(char *str)
{
	struct	dirent		*d;
	DIR					*dir;

	if ((dir = opendir(str)) == NULL)
	{
		return (0);
	}
	
	while ((d = readdir(dir)) != NULL )
	{
		printf("%s\n", d->d_name);
		
	}
}

int		main(int argc, char **argv)
{
	ls(argv[1]);
}
