/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:50:08 by aradix            #+#    #+#             */
/*   Updated: 2023/12/06 14:42:36 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	cmp_output(char *s)
{
	int		fd;
	char	buff[100];
	size_t	size;

	fd = open("tmp", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		perror("Error opening file");
		return (false);
	}
	ft_putstr_fd(s, fd);
	lseek(fd, 0, SEEK_SET);
	size = read(fd, buff, 98);
	close(fd);
	buff[size] = '\0';
	if (strcmp(buff, s) == 0)
		return (true);
	return (false);
}

int	main(void)
{
	printf("ft_putstr_fd:        ");
	/* -------------------- TEST 01 -------------------- */
	if (cmp_output("a"))
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	if (cmp_output("weofihweoifhewoifnioen	w	e65f465 t4g 6w4tw6546r6  a"))
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
