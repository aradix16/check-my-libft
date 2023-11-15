/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:33:29 by aradix            #+#    #+#             */
/*   Updated: 2023/11/15 16:47:20 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

volatile sig_atomic_t	segfault_occurred = 0;
jmp_buf					jump_buffer;

void	segfault_handler(int signo)
{
	(void)signo;
	segfault_occurred = 1;
	longjmp(jump_buffer, 1);
}

int	main(void)
{
	// PART 1
	printf("ft_isalpha:          ");
	test_ft_is(ft_isalpha, isalpha);
	printf("ft_isdigit:          ");
	test_ft_is(ft_isdigit, isdigit);
	printf("ft_isalnum:          ");
	test_ft_is(ft_isalnum, isalnum);
	printf("ft_isascii:          ");
	test_ft_is(ft_isascii, isascii);
	printf("ft_isprint:          ");
	test_ft_is(ft_isprint, isprint);
	printf("ft_strlen:           ");
	test_ft_strlen();
	printf("ft_memset:           ");
	test_ft_memset();
	return (0);
}