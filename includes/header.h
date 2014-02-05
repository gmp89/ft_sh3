/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 15:49:20 by gpetrov           #+#    #+#             */
/*   Updated: 2014/02/05 19:00:06 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define MAX_KEY_STRING 5

/* # include <sys/uio.h> */
/* # include <signal.h> */
# include <termios.h>
# include <curses.h>
# include <term.h>
# include "libft.h"

/*
** Struct
*/

typedef struct		s_env
{
	char			*str;
	struct s_env	*next;
}					t_env;

typedef struct		s_list
{
	char			c;
	int				printed;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_li
{
	struct s_list	*ptr;
	struct s_li		*next;
	struct s_li		*prev;
}					t_li;

typedef struct	s_data
{
	int			i;
	int			cursor;
	int			tmp;
	int			real_cursor;
	int			pid;
	char		buff[MAX_KEY_STRING];
	char		*name_cmd;
	char		**env;
	char		*prompt;
	char		**argv;
	char		*home;
	char		*path;
	char		*dir_cmd;
	char		*pwd;
	char		*old_pwd;
	t_list		*list;
	t_list		*charly;
	t_li		*charly2;
	t_li		*hist;
}				t_data;

/*
** Prototypes
*/

int		ft_get_cmd(t_data *data);
char	*ft_get_user(char **tabl, t_data *data);
int		ft_count_c(char *str, char c);
char	**ft_get_path(char **tabl);
int		ft_exec(t_data *data);
int		ft_exec_cmd(t_data *data);
char	*ft_direct_exec(t_data *data);
void	ft_get_pwd(t_data *data, char **env);
void	ft_cd_help(t_data *data);
void	print_pid_error(void);
void	ft_cmd_error(void);
void	ft_set_prompt(t_data *data);
void	ft_print_tab(char **tabl);
void	ft_setenv(t_data *data, char *str);
int		ft_checkenv(t_data *data, char *str);
int		ft_unsetenv(t_data *data, char *str);

/*
**	termcaps
*/

int		tputs_putchar(int c);
void	raw_term_mode(void);
void	default_term_mode(void);

int		is_arrow(char *buf, t_data *data);
t_list	*arrow_right(t_list *list, t_data *data);
t_list	*arrow_left(t_list *list, t_data *data);
t_li	*is_up(t_li *list, t_data *data);

void	ft_while(t_data *data);
void	ft_cursor_move_offset(t_data *data);
int		is_delete(char *buf, t_data *data);
int		is_return(char *buf, t_data *data);
void	key_return(t_data *data);

/*
**	List
*/

void	ft_add_elem(t_list **list, char c, t_data *data);
void	ft_print_list(t_list *list);
t_list	*del_elem(t_list *list, t_data *data);
void	key_return(t_data *data);
t_li	*add_list(t_li *list, t_data *data);
void	ft_print_history(t_li *list);

#endif
