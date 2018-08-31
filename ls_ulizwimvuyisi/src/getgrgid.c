/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getgrgid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umvuyisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 21:40:12 by umvuyisi          #+#    #+#             */
/*   Updated: 2018/08/22 12:16:00 by umvuyisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <grp.h>

struct group * getgrgid(gid_t gid);
int	getgrgid_r(gid_t gid, struct group *grp, char *buffer, size_t bufsize, struct group **result);


struct		group
{
	char	*gr_name;
	char	*gr_paawd;
	git_t	gr_gid;
	char	**gr_mem
}
	long	int	intilen = sysconf(_SCGETGR_R_SIZE_MAX)
	size_t len;
	if	(initlen == -1)
	/* default initial length. */
	len = 1024;
	else
	len = (size_t) initlen;
	struct group result;
	struct group *resultp;
	char *buffer = malloc(len);
	if (buffer == NULL)
	...handle error..
	int		e;
	while ((e = getgrgid_r(42, &result, buffer, len, &resultp)) == ERANGE)
	{
		size_t newlen = 2 * len;
	if (newlen < len)
		len = newlen;
		char	*newbuffer = realloc(buffer, len);
	if (newbuffer == NULL)
		...handle error...
		buffer = newbuffer;
	}

	if (e != 0)
	...handle error...
		free (buffer);
