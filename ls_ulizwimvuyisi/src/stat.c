/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umvuyisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 22:59:52 by umvuyisi          #+#    #+#             */
/*   Updated: 2018/08/20 12:47:53 by umvuyisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <grp.h>
#include <stdio.h>

struct stat statbuf;
struct group *grp;

if ((grp = getgrgid(statbuf.st_gid)) != NULL)
	printf("%-8.8s", grp->gr_name);
else
	printf("%-8d", statbuf.st_gid);
