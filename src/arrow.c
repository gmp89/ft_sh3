/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 22:28:39 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/04 23:52:42 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*arrow_right(t_list *list)
{
	if (list)
	{
		if (list->next != NULL)
		{
			list = list->next;
			/* *(data->charly) = data->charly.next; */
			tputs(tgetstr("nd", NULL), 1, tputs_putchar);
			/* ft_putstr("[RIGHT]\n"); */
		}
	}
	return (list);
}

t_list	*arrow_left(t_list *list)
{
	if (list)
	{
		if (list->prev != NULL)
		{
			list = list->prev;
			/* *(data->charly) = data->charly.next; */
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
			/* ft_putstr("[RIGHT]\n"); */
		}
	}
	return (list);
}

int		is_arrow(char *buf, t_data *data)
{
	if (buf[0] != 27 && buf[1] != 91)
		return (-1);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
		ft_putstr("[UP]\n");
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
		ft_putstr("[DOWN]\n");
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67)
		data->charly = arrow_right(data->charly);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68)
	{
		data->charly = arrow_left(data->charly);
		/* ft_putstr("[LEFT]\n"); */
	}
	return (0);
}
