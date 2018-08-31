/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umvuyisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 23:35:27 by umvuyisi          #+#    #+#             */
/*   Updated: 2018/08/31 08:57:42 by umvuyisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <errno.h>

void	show_errno(void)
{
	if(errno==EDOM)		printf("domai error");
	if(errno==EILSEQ)	printf("illegal sequence");
	if(errno==ERANGE)	printf("POLE or range error");
	if(errno==0)		printf("no error");
	printf(" occurred\n");
}

int		main(void)
{
	printf("MATH_ERRNO is %s\n", math_errhandling &	math_errno ? "set" : "not set");

	errno = 0;
	1.0/0.0;
	show_errno();

	errno = 0;
	acos(+1.1);
	show_errno();

	errno = 0;
	log(0.0);
	show_errno();

	errno = 0;
	sin(0.0);
	show_errno();
}
