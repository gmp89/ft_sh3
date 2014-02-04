/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:50:35 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/04 23:55:06 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* int		ft_while(t_data *d, struct termios *term, t_list *list) */
/* { */
/* 	while (42) */
/* 	{ */
/* 		ft_bzero(d->read_char, 3); */
/* 		read(0, d->read_char, 3); */
/* 		if (is_rtn(d->read_char)) */
/* 		{ */
/* 			ft_quit(term); */
/* 			final_print(list); */
/* 			return (1); */
/* 		} */
/* 		if (ft_while_help(d, term, list, d->read_char)) */
/* 			; */
/* 		else if (is_arrow(d->read_char, d, list) == 0) */
/* 			; */
/* 		else if (is_spc(d->read_char,  list, d) == 0) */
/* 			; */
/* 		else if (is_del(d->read_char)) */
/* 			list = ft_del_elem(list, d, term); */
/* 		if (list == NULL) */
/* 			return (0); */
/* 		ft_putstr(d->read_char); */
/* 	} */
/* 	return (0); */
/* } */

void	raw_term_mode(void)
{
	struct termios	tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag &= ~(ECHO | ICANON);
	/* tattr.c_oflag &= ~(OPOST); */
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	tgetent(NULL, getenv("TERM"));
	return ;
}

void	default_term_mode(void)
{
	struct termios	tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tattr.c_lflag |= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &tattr);
	return ;
}

void	printable_char(t_data *data)
{
	data->cursor++;
	ft_add_elem(&data->list, *data->buff, data);
	/* ft_putchar(*data->buff); */
	ft_print_list(data->list);
	/* ft_putchar('\n'); */
}

void	ft_while(t_data *data)
{
	data->list = (t_list *)malloc(sizeof(t_list));
	data->list = NULL;
	data->cursor = 0;
	while (42)
	{
		/* ft_putstr("$> "); */
		ft_memset(data->buff, 0, MAX_KEY_STRING);
		read(STDIN_FILENO, data->buff, MAX_KEY_STRING);
		if (ft_isprint(*data->buff) == 1)
			printable_char(data);
		else if (is_arrow(data->buff, data) == 0)
			;
		else
			printf("KEY : [%d] [%d] [%d]\n",
	(unsigned int)data->buff[0],
	(unsigned int)data->buff[1],
	(unsigned int)data->buff[2]);
	}
}

int		main(int ac, char **av, char **env)
{
	t_data	data;

	(void)ac;
	(void)av;
	(void)env;
	raw_term_mode();
	ft_while(&data);
	default_term_mode();
	return (0);
}

/* int		main(int ac, char **av, char **env) */
/* { */
/* 	t_data		data; */
/* 	char		*tmp; */

/* 	(void)ac; */
/* 	(void)av; */
/* 	if (env == NULL) */
/* 		return (0); */
/* 	tmp = NULL; */
/* 	data.env = env; */
/* 	data.old_pwd = getcwd(tmp, 4096); */
/* 	ft_set_prompt(&data); */
/* 	while (42) */
/* 	{ */
/* 		ft_get_pwd(&data, env); */
/* 		ft_putstr(data.pwd + 43); */
/* 		ft_putstr(" $> "); */
/* 		if (ft_get_cmd(&data) == 0) */
/* 		{ */
/* 			if (ft_exec_cmd(&data) == 0) */
/* 				free(data.name_cmd); */
/* 		} */
/* 	} */
/* 	return (0); */
/* } */

/* int		ft_exec(t_data *data) */
/* { */
/* 	char	*tmp; */
/* 	char	**path; */
/* 	int		i; */
/* 	int		t; */

/* 	path = ft_get_path(data->env); */
/* 	i = 0; */
/* 	while (path[i] != 0) */
/* 	{ */
/* 		tmp = ft_strjoin(path[i], data->name_cmd); */
/* 		t = access(tmp, X_OK); */
/* 		execve(tmp, data->argv, data->env); */
/* 		free(tmp); */
/* 		i++; */
/* 	} */
/* 	execve(data->name_cmd, data->argv, data->env); */
/* 	if (t == -1 && ft_strcmp(data->name_cmd, "exit") != 0) */
/* 		ft_cmd_error(); */
/* 	return (0); */
/* } */

/* int		ft_exec_cmd(t_data *data) */
/* { */
/* 	int		ret; */

/* 	if (ft_strcmp(data->name_cmd, "setenv") == 0 && data->argv[1]) */
/* 		ft_setenv(data, data->argv[1]); */
/* 	if (ft_strcmp(data->name_cmd, "unsetenv") == 0 && data->argv[1]) */
/* 		ft_unsetenv(data, data->argv[1]); */
/* 	if (ft_strcmp(data->name_cmd, "cd") == 0) */
/* 		ft_cd_help(data); */
/* 	data->pid = fork(); */
/* 	if (data->pid == -1) */
/* 		print_pid_error(); */
/* 	if (data->pid == 0 && ft_strcmp(data->name_cmd, "cd") != 0 */
/* 	 && ft_strcmp(data->name_cmd, "setenv") != 0 && */
/* 	 ft_strcmp(data->name_cmd, "unsetenv") != 0) */
/* 	{ */
/* 		ft_exec(data); */
/* 		exit(0); */
/* 	} */
/* 	if (data->pid > 0) */
/* 		wait(&ret); */
/* 	return (0); */
/* } */
