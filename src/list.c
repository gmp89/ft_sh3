/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 19:54:22 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/04 23:55:00 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_add_elem(t_list **list, char c, t_data *data)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *list;
	new = (t_list *)malloc(sizeof(t_list));
	new->c = c;
	new->printed = 0;
	new->next = NULL;
	new->prev = NULL;
	if (*list == NULL)
	{
		*list = new;
		data->charly = new;
		return ;
	}
	if (data->charly->next != NULL)
	{
		new->next = data->charly->next;

		data->charly->next->prev = new;
	}
	new->prev = data->charly;
	data->charly->next = new;
	data->charly = new;
}


void	ft_print_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp != NULL)
	{
		if (tmp->printed == 0)
		{
			ft_putchar(tmp->c);
			tmp->printed = 1;
		}
		tmp = tmp->next;
	}
}
