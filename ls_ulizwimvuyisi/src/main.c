/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umvuyisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 23:17:42 by umvuyisi          #+#    #+#             */
/*   Updated: 2018/08/22 12:16:04 by umvuyisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <grp.h>
#include <sys/dir.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <time.h>
#include <locale.h>
#include <pwd.h>
#include <stdint.h>
#include <langinfo.h>
#include <dirent.h>
#include <fcntl.h>

/* int	main(void)
{
   	struct group* g;
	struct passwd* pw;
	char**	p;

	if (( g = getgrgid( getgid() )) == NULL)
	{
		fprintf( stderr, "getgrgid: NULL pointer\n" );
		return (EXIT_FAILURE);
	}
	printf("group name:%s\n", g->gr_name);
   for(p = g->gr_mem; *p != NULL; p++)
   {
	   printf("\t%s\n", *p);
   }
   return (EXIT_SUCCESS);
} */

/*  struct student {
    char firstName[20];
    char lastName[20];
    char SSN[10];
    float gpa;
}

main()
{
  struct student student_a;

  strcpy(student_a.firstName, "Mongezi");
  strcpy(student_a.lastName, "Makatshu");
  strcpy(student_a.SSN, "00098211" );
  student_a.gpa = 20018.05;

 printf( "First Name: %s\n", student_a.firstName );
 printf( "Last Name: %s\n", student_a.lastName );
 printf( "SNN : %s\n", student_a.SSN );
 printf( "GPA : %f\n", student_a.gpa );
} */

static char perms_buff[30];

const char *get_perms(mode_t mode)
{
  char ftype = '?';

  if (S_ISREG(mode)) ftype = '-';
  if (S_ISLNK(mode)) ftype = 'l';
  if (S_ISDIR(mode)) ftype = 'd';
  if (S_ISBLK(mode)) ftype = 'b';
  if (S_ISCHR(mode)) ftype = 'c';
  if (S_ISFIFO(mode)) ftype = '|';

  sprintf(perms_buff, "%c%c%c%c%c%c%c%c%c%c %c%c%c", ftype,
  mode & S_IRUSR ? 'r' : '-',
  mode & S_IWUSR ? 'w' : '-',
  mode & S_IXUSR ? 'x' : '-',
  mode & S_IRGRP ? 'r' : '-',
  mode & S_IWGRP ? 'w' : '-',
  mode & S_IXGRP ? 'x' : '-',
  mode & S_IROTH ? 'r' : '-',
  mode & S_IWOTH ? 'w' : '-',
  mode & S_IXOTH ? 'x' : '-',
  mode & S_ISUID ? 'U' : '-',
  mode & S_ISGID ? 'G' : '-',
  mode & S_ISVTX ? 'S' : '-');

  return (const char *)perms_buff;
}

char pathname[MAXPATHLEN];

void die(char *msg)
{
  perror(msg);
  exit(0);
}

static int
one (const struct dirent *unused)
{
  return 1;
}
int main()
{
  int count,i;
  struct direct **files;
  struct stat statbuf;
  char datestring[256];
  struct passwd pwent;
  struct passwd *pwentp;
  struct group grp;
  struct group *grpt;
  struct tm time;
  char buf[1024];

  if(!getcwd(pathname, sizeof(pathname)))
    die("Error getting pathnamen");

  count = scandir(pathname, &files, one, alphasort);

  if(count > 0)
  {
    printf("total %d\n",count);

    for (i=0; i<count; ++i)
    {
      if (stat(files[i]->d_name, &statbuf) == 0)
      {
        /* Print out type, permissions, and number of links. */
        printf("%10.10s", get_perms(statbuf.st_mode));
        printf(" %d", statbuf.st_nlink);

        if (!getpwuid_r(statbuf.st_uid, &pwent, buf, sizeof(buf), &pwentp))
          printf(" %s", pwent.pw_name);
        else
          printf(" %d", statbuf.st_uid);

        if (!getgrgid_r (statbuf.st_gid, &grp, buf, sizeof(buf), &grpt))
          printf(" %s", grp.gr_name);
        else
          printf(" %d", statbuf.st_gid);

        /* Print size of file. */
        printf(" %5d", (int)statbuf.st_size);

        localtime_r(&statbuf.st_mtime, &time);
        /* Get localized date string. */
        strftime(datestring, sizeof(datestring), "%F %T", &time);

        printf(" %s %s\n", datestring, files[i]->d_name);
      }

      free (files[i]);
    }

    free(files);
  }
}
