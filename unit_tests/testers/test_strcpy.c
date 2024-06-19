/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscabell <vscabell@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:49:31 by vscabell          #+#    #+#             */
/*   Updated: 2024/06/19 17:57:50 by cassepipe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_test.h"

static void	result(char *(*ft)(char*, const char*), char *src)
{
	char	dst[100];

	bzero(dst, 1);
	printf("src = %s\n", src);
	printf("return = %s\n", ft(dst, src));
}

int			main(int argc, char **argv)
{
	int		funct;
	char	*input;

	funct = atoi(argv[1]);
	input = argv[2];
	(void)argc;
	if (funct == ORIG)
		result(strcpy, input);
	else if (funct == IMPLEM)
		result(ft_strcpy, input);
	return (0);
}
