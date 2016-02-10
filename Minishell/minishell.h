/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:12:45 by abungert          #+#    #+#             */
/*   Updated: 2016/02/10 15:38:37 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct	s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}				t_env;

char			*search_in_env(char *name, t_env *list);
void			change_env_variable(char *name, char *new_value, t_env *list);
int				ft_setenv(char *name, char *value, t_env **head);
int				ft_unsetenv(char *name, t_env **list);
void			print_env(t_env *head);

int				execute_command(char *user_entry, t_env **env_list,
		char **environ);
char			*find_command(char *command, t_env *env_list);

void			change_cwd(char **args, t_env **list);
int				builtin_commands(char *name, char **args, t_env **env_list);

void	catch_signal(void);

#endif
