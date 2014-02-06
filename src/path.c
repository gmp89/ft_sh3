/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 23:14:25 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/06 18:51:28 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_count_c(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

char	**ft_get_path(char **tabs)
{
	char	**path;
	char	**tmp;
	int		i;
	int		j;

	tmp = ft_strsplit(tabs[0] + 5, ':');
	i = ft_count_c(tabs[0], ':') + 1;
	path = (char **)malloc((i + 2) * sizeof(*path));
	path[i + 2] = 0;
	j = 0;
	while (j < i)
	{
		path[j] = ft_strjoin(tmp[j], "/");
		free(tmp[j]);
		j++;
	}
	free(tmp);
	return (path);
}

int		ft_get_cmd(t_data *data)
{
	char	**tabs;

	/* get_next_line(0, &data->prompt); */
	/* ft_bzero(data->prompt, 4095); */
	/* read(0, data->prompt, 4095); */
	/* data->prompt = ft_strtrim(data->prompt); */
	if (ft_strcmp(data->prompt, "exit") == 0)
		_exit(0);
	if (ft_strcmp(data->prompt, "\0") == 0)
		return (1);
	tabs = ft_strsplit(data->prompt, ' ');
	data->name_cmd = tabs[0];
	data->argv = tabs;
	return (0);
}

char	*ft_get_user(char **tabs, t_data *data)
{
	char	*tmp;

	tmp = tabs[4] + 5;
	data->home = tabs[3] + 5;
	return (tmp);
}

char	*ft_direct_exec(t_data *data)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	while (data->prompt[i] != 0)
		i++;
	j = i;
	while (data->prompt[j] != '/')
		j--;
	k = i - j;
	data->dir_cmd = (char *)malloc(sizeof(char) * (j + 1));
	k = 0;
	while (data->prompt[j] != 0)
	{
		data->dir_cmd[k] = data->prompt[j];
		k++;
		j++;
	}
	data->dir_cmd[k] = 0;
	return (data->dir_cmd);
}
