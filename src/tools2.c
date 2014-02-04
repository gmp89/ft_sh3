/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 16:54:41 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/04 21:41:24 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_tab(char **tabl)
{
	int		i;

	i = 0;
	while (tabl[i] != 0)
	{
		ft_putstr(tabl[i]);
		ft_putchar('\n');
		i++;
	}
}

int		tputs_putchar(int c)
{
	write(isatty(STDOUT_FILENO), &c, 1);
	return (1);
}
