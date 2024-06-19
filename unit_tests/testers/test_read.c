/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:20:50 by vscabell          #+#    #+#             */
/*   Updated: 2024/06/19 18:00:54 by cassepipe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_test.h"

void	result(ssize_t (*ft)(int, void *, size_t), int fd)
{
	ssize_t	ret;
	char	buffer[101] = {0};

	ret = ft(fd, buffer, 100);
	printf("buffer = %s\n", buffer);
	printf("return = %zd\n", ret);
	printf("errno = %d\n", errno);
}

void	test(int fd, char funct)
{
	if (funct == ORIG)
		result(read, fd);
	else if (funct == IMPLEM)
		result(ft_read, fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		type;
	int		funct;

	fd = 0;
	fd = 0;
	type = atoi(argv[1]);
	funct = atoi(argv[2]);
	if (argc > 2)
		fd = open(argv[3], O_RDWR);
	if (type == STD)
		test(STDIN_FILENO, funct);
	else if (type == FD_OPEN)
		test(fd, funct);
	else if (type == FD_WRONG)
		test(fd + 5, funct);
	close (fd);
	return (0);
}


