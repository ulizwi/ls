/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umvuyisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 16:06:18 by umvuyisi          #+#    #+#             */
/*   Updated: 2018/08/28 17:21:24 by umvuyisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

int main(int ac,char **av)
{
	struct dirent **namelist;
	int n;
	
	if(ac < 1)
	{
		exit(EXIT_FAILURE);
	}
	else if (ac == 1)
	{
		n=scandir(".", &namelist,NULL,alphasort);
	}
	else
	{
		n = scandir(av[1], &namelist, NULL, alphasort);
	}
	if(n < 0)
	{
		perror("scandir");
		exit(EXIT_FAILURE);
	}
	else
	{
		while (n–-)
		{
			printf("%s\n",namelist[n]->d_name);
			free(namelist[n]);
		}
		free(namelist);
	}
	exit(EXIT_SUCCESS);
}
