/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 16:26:42 by rkieboom      #+#    #+#                 */
/*   Updated: 2020/12/01 17:17:31 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <malloc/malloc.h>

size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char const *src);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);

static void	ft_strlen_test()
{
	int result1, result2;
	char str1[]= "iubfsdnihtujht";
	char str2[]= "gijfdiogjmorg9nt0bue90nu9ru9guf9bdun89e8nu89ty89yibnyt9nb89y89tybn8ub894589u89b4u";
	char str3[]= "";

	result1 = strlen(str1);
	result2 = ft_strlen(str1);
	if (result1 != result2)
		printf("Error, ft_strlen!\n");
	result1 = strlen(str2);
	result2 = ft_strlen(str2);
	if (result1 != result2)
		printf("Error, ft_strlen!\n");
	result1 = strlen(str3);
	result2 = ft_strlen(str3);
	if (result1 != result2)
		printf("Error, ft_strlen!\n");
}

static void	ft_strcpy_test()
{
	char *str1 = strdup("halooo");
	char *str2 = strdup("goedeavond");
	char *str3 = strdup("hele lange stringggggg");
	char *str5 = strdup("halooo");
	char *str6 = strdup("goedeavond");
	char *str7 = strdup("hele lange stringggggg");

	strcpy(str2, str1);
	ft_strcpy(str6, str5);
	if (strcmp(str2, str6) != 0)
		printf("Error, strcpy!\n\n");

	strcpy(str3, str2);
	ft_strcpy(str7, str6);
	if (strcmp(str3, str7) != 0)
		printf("Error, strcpy!\n\n");

	strcpy(str2, "");
	ft_strcpy(str7, "");
	if (strcmp(str2, str7) != 0)
		printf("Error, strcpy!\n\n");
}

static void	ft_write_test()
{
	int result1, result2;

	result1 = write(1, "Halloo\n", 7);
	result2 = ft_write(1, "Halloo\n", 7);
	if (result1 != result2)
		printf("Error, write!\\");

	result1 = write(1, "", 1);
	result2 = ft_write(1, "", 1);
	if (result1 != result2)
		printf("Error, write!\n\n");
	result2 = write(5, "", 1);
	if (errno)
		printf("Error, %s!\n\n", strerror(errno));
	errno = 0;

}

static void	ft_read_test()
{
	int fd1, fd2;
	int result1, result2;
	char buf1[1000], buf2[1000];

	fd1 = open("ft_read.s", O_RDONLY);
	fd2 = open("ft_read.s", O_RDONLY);

	result1 = read(fd1, buf1, 1000);
	buf1[result1] = '\0';

	result2 = ft_read(fd2, buf2, 1000);
	buf2[result2] = '\0';
	if ((result1 != result2) || (strcmp(buf1, buf2) != 0))
		printf("Error, read!\n\n");
	close(fd1);
	close(fd2);

	read(5, buf1, 1000);
	if (errno)
		printf("Error, %s!\n\n", strerror(errno));
}

static void		ft_strcmp_test()
{
	int result1, result2;
	char str1[]= "fjisngs";
	char str2[]= "fjisnga";
	char str3[]= "fji5";
	char str4[]= "";

	result1 = strcmp(str1, str2);
	result2 = ft_strcmp(str1, str2);
	if (result1 != result2)
		printf("Error, strcmp!\n\n");

	result1 = strcmp(str2, str1);
	result2 = ft_strcmp(str2, str1);
	if (result1 != result2)
		printf("Error, strcmp!\n\n");

	result1 = strcmp(str1, str3);
	result2 = ft_strcmp(str1, str3);
	if (result1 != result2)
		printf("Error, strcmp!\n\n");

	result1 = strcmp(str3, str4);
	result2 = ft_strcmp(str3, str4);
	if (result1 != result2)
		printf("Error, strcmp!\n\n");

	result1 = strcmp(str4, str3);
	result2 = ft_strcmp(str4, str3);
	if (result1 != result2)
		printf("Error, strcmp!\n\n");
}

static void		ft_strdup_test()
{
	char *str1;
	char *str2;

	str1 = strdup("dijohfdfnogdfi");
	str2 = ft_strdup("dijohfdfnogdfi");
	if (malloc_size(str1) != malloc_size(str2) || strcmp(str1, str2) != 0)
		printf("Error, strdup!\n\n");
	free(str1);
	free(str2);
	str1 = strdup("");
	str2 = ft_strdup("");
	if (malloc_size(str1) != malloc_size(str2) || strcmp(str1, str2) != 0)
		printf("Error, strdup!\n\n");

	free(str1);
	free(str2);
}

int	main(void)
{
	ft_strlen_test();
	ft_strcpy_test();
	ft_write_test();
	ft_read_test();
	ft_strcmp_test();
	ft_strdup_test();
	return (0);
}
