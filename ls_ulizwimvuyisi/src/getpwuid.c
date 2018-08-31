/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpwuid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umvuyisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 11:40:30 by umvuyisi          #+#    #+#             */
/*   Updated: 2018/08/22 12:16:01 by umvuyisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>

int bufsize;

if ((bufsize = sysconf(_SC_GETPW_R_SIZE_MAX)) == -1)
   	abort();
	
	char buffer[bufsize];
	struct passwd pwd, *result = NULL;
if (getpwuid_r(getuid(), &pwd, buffer, bufsize, &result) != 0 || !result)
	abort();

	printf("%s\n", pwd.pw_dir);
