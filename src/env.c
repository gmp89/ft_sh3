/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 16:55:35 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/03 16:56:12 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_setenv(t_data *data, char *str)
{
	int		j;
	int		i;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = data->env;
	while (data->env[j] != 0)
		j++;
	data->env = (char **)malloc(sizeof(char *) * (j + 2));
	while (tmp[i] != 0)
	{
		data->env[i] = ft_strdup(tmp[i]);
		i++;
	}
	data->env[i] = ft_strdup(str);
	data->env[i + 1] = 0;
}

int		ft_checkenv(t_data *data, char *str)
{
	int		i;

	i = 0;
	while (data->env[i] != 0)
	{
		if (ft_strcmp(data->env[i], str) == 0)
			return (1);
		i++;
	}
	ft_putstr("[ENV] - Not Found.\n");
	return (0);
}

int		ft_unsetenv(t_data *data, char *str)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = data->env;
	if (ft_checkenv(data, str) == 0)
		return (0);
	while (data->env[i] != 0)
	{
		if (ft_strcmp(data->env[i], str) == 0)
		{
			while (tmp[i] != 0)
			{
				if (tmp[i + 1])
					data->env[i] = ft_strdup(tmp[i + 1]);
				else
					data->env[i] = 0;
				i++;
			}
			break ;
		}
		i++;
	}
	return (0);
}
