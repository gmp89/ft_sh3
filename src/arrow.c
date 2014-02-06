/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 22:28:39 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/06 17:59:26 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*arrow_right(t_list *list, t_data *data)
{
	if (list)
	{
		if (list->next == NULL && data->cursor != data->real_cursor)
		{
			data->cursor++;
			tputs(tgetstr("nd", NULL), 1, tputs_putchar);
		}
		else if (list->next != NULL)
		{
			data->cursor++;
			list = list->next;
			tputs(tgetstr("nd", NULL), 1, tputs_putchar);
		}
	}
	return (list);
}

t_list	*arrow_left(t_list *list, t_data *data)
{
	if (list)
	{
		if (list->prev == NULL)
		{
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
			data->cursor--;
		}
		if (list->prev != NULL)
		{
			data->cursor--;
			list = list->prev;
			tputs(tgetstr("le", NULL), 1, tputs_putchar);
		}
	}
	return (list);
}

int		is_arrow(char *buf, t_data *data)
{
	if (buf[0] != 27 && buf[1] != 91)
		return (-1);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
		data->charly2 = is_up(data->charly2, data);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
		data->charly2 = is_down(data->charly2, data);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 67)
		data->charly = arrow_right(data->charly, data);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 68)
		data->charly = arrow_left(data->charly, data);
	return (0);
}

t_li	*is_down(t_li *charly, t_data *data)
{
	data->i = 0;
	if (charly)
	{
		/* if (charly->next != NULL) */
		/* { */
			if (charly->next)
			{
				charly = charly->next;
				ft_print_list(charly->ptr);
			}
		/* } */
	}
	return (charly);
}

t_li	*is_up(t_li *list, t_data *data)
{
	data->i = 0;
	if (list)
	{
		/* if (list->prev != NULL) */
		/* { */
		if (list->prev != NULL)
		{
			
			ft_print_list(list->ptr);
			list = list->prev;
		}
		else
			ft_print_list(list->ptr);
		/* } */
	}
	return (list);
}

int		is_delete(char *buf, t_data *data)
{
	data->i = 0;
	if (buf[0] != 127 && buf[1] != 0 && buf[2] != 0)
		return (-1);
	if (buf[0] == 127 && buf[1] == 0 && buf[2] == 0)
		data->charly = del_elem(data->charly, data);
	return (0);
}

void	key_return(t_data *data)
{
	data->hist = add_list(data->hist, data);
	data->charly2 = data->charly2->next;
	ft_putstr("\n");
}

int		is_return(char *buf, t_data *data)
{
	data->i = 0;
	if (buf[0] != 10)
		return (-1);
	if  (buf[0] == 10)
		key_return(data);
	return (0);
}
