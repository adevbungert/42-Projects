/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and_or.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:04:12 by abungert          #+#    #+#             */
/*   Updated: 2016/11/03 19:04:14 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../sh.h"

void		ft_and(t_tree *node, t_env *env_list)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		ft_choose_exec(node->left, env_list);
	}
	else
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 0)
		{
			ft_choose_exec(node->right, env_list);
		}
		else
			exit(1);
	}
}

void		ft_or(t_tree *node, t_env *env_list)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		ft_choose_exec(node->left, env_list);
	}
	else
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) != 0)
		{
			ft_choose_exec(node->right, env_list);
		}
		else
			exit(0);
	}
}
