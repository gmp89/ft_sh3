/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 22:28:39 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/06 19:58:21 by gpetrov          ###   ########.fr       */
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
	if (charly)
	{
		/* if (charly->next != NULL) */
		/* { */
			if (charly->next)
			{
				charly = charly->next;
				ft_print_list(charly->ptr, data);
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
			ft_print_list(list->ptr, data);
			list = list->prev;
		}
		else
		{
			if (list->ptr)
				ft_print_list(list->ptr, data);
		}
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

char	*ft_make_string(t_list *list)
{
	t_list	*tmp;
	int		i;
	char	*str;

	i = 0;
	tmp = list;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	tmp = list;
	i = 0;
	while (tmp)
	{
		str[i] = tmp->c;
		i++;
		tmp = tmp->next;
	}
	str[i] = 0;
	return (str);
}

void	key_return(t_data *data)
{
	data->prompt = ft_make_string(data->list);
	/* ft_putstr("\n----TEST-----\n"); */
	/* ft_putstr(data->prompt); */
	data->hist = add_list(data->hist, data);
	data->charly2 = data->charly2->next;
	ft_putstr("\n");
	if (ft_get_cmd(data) == 0)
	{
		if (ft_exec_cmd(data) == 0)
			free(data->name_cmd);
	}
	ft_get_pwd(data, data->env);
	ft_putstr(data->pwd + 43);
	ft_putstr(" $> ");
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
