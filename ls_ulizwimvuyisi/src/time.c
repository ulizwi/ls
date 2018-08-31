/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umvuyisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:27:11 by umvuyisi          #+#    #+#             */
/*   Updated: 2018/08/22 23:23:14 by umvuyisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <times.h>
#include <sys/times.h>


clock_t times(struct tms *buf)

	struct tms {
		clock_t tms_utime;
		clock_t tms_stime;
		clock_t tms_cutime;
		clock_t tms_cstime;
	};

