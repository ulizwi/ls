/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umvuyisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 19:09:57 by umvuyisi          #+#    #+#             */
/*   Updated: 2018/08/29 21:57:15 by umvuyisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <string.h>
#include <dirent.h>

/* int		main(int ac, char **av)
{
	DIR *mydir;
	struct dirent *myfile;
	struct stat mystat;

	char buf[512];
	mydir = opendir(av[1]);
	while((myfile = readdir(mydir)) != NULL)
	{
		sprintf(buf, "%s/%s", av[1], myfile->d_name);
		lstat(buf, &mystat);
		printf("%lld",mystat.st_size);
		printf("%s\n", myfile->d_name);
	}
	closedir(mydir);
} */

int main(int argc, char **argv)
{
    DIR *dp;
    struct dirent *dirp;

    if ((dp = opendir(argv[1])) == NULL)
        printf(“can’t open %s”, argv[1]);

    while ((dirp = readdir(dp)) != NULL){
        struct stat fileStat;
        stat(dirp->d_name,&fileStat);

        printf(dirp->d_name);
        printf(“—————————\n”);
        printf(“File Size: \t\t%d bytes\n”,fileStat.st_size);
        printf(“Number of Links: \t%d\n”,fileStat.st_nlink);
        printf(“File inode: \t\t%d\n”,fileStat.st_ino);

        printf(“File Permissions: \t”);
        printf( (S_ISDIR(fileStat.st_mode)) ? “d” : “-“);
        printf( (fileStat.st_mode & S_IRUSR) ? “r” : “-“);
        printf( (fileStat.st_mode & S_IWUSR) ? “w” : “-“);
        printf( (fileStat.st_mode & S_IXUSR) ? “x” : “-“);
        printf( (fileStat.st_mode & S_IRGRP) ? “r” : “-“);
        printf( (fileStat.st_mode & S_IWGRP) ? “w” : “-“);
        printf( (fileStat.st_mode & S_IXGRP) ? “x” : “-“);
        printf( (fileStat.st_mode & S_IROTH) ? “r” : “-“);
        printf( (fileStat.st_mode & S_IWOTH) ? “w” : “-“);
        printf( (fileStat.st_mode & S_IXOTH) ? “x” : “-“);
        printf(“\n\n”);

        printf(“The file %s a symbolic link\n”, (S_ISLNK(fileStat.st_mode)) ? “is” : “is not”);
    }
    return 0;
}
