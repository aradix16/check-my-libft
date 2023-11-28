/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradix <aradix@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 22:14:08 by aradix            #+#    #+#             */
/*   Updated: 2023/11/22 23:16:35 by aradix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check-my-libft.h"

static bool	cmp_output(int c)
{
	int	ret;
	int	expected_ret;

	ret = ft_isalnum(c);
	expected_ret = isalnum(c);
	if ((ret == 0 && expected_ret == 0) || (ret > 0 && expected_ret > 0))
		return (true);
	return (false);
}

int	main(void)
{
	printf("ft_isalnum:          ");
	int	c;
	/* -------------------- TEST 01 -------------------- */
	c = 0;
	while (c <= 127 && cmp_output(c))
		c++;
	if (c == 128)
		printf("%s 1:[OK]", GREEN);
	else
		printf("%s 1:[KO]", RED);
	/* -------------------- TEST 02 -------------------- */
	while (c <= 200 && cmp_output(c))
		c++;
	if (c == 201)
		printf("%s 2:[OK]", GREEN);
	else
		printf("%s 2:[KO]", RED);
	/* -------------------------------------------------- */
	printf("\x1b[0m\n");
}
