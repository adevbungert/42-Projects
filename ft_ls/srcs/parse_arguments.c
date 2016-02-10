/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abungert <abungert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:32:25 by abungert          #+#    #+#             */
/*   Updated: 2016/01/29 10:50:14 by abungert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_option(char *arg, t_ls_args *ls_args)
{
	while (*arg)
	{
		if (!ft_strchr(ls_args->authorized_options, *arg) || !ft_isalnum(*arg))
		{
			ft_putstr("ls : illegal option -- ");
			ft_putchar(*arg);
			ft_putchar('\n');
			ft_putstr("usage: ls [-");
			ft_putstr(ls_args->authorized_options);
			ft_putendl("] [file ...]");
			exit(0);
		}
		arg++;
	}
	return (1);
}

static int	store_requested_dir(char *dir_name, t_ls_args *ls_args,
									t_files **tmp)
{
	t_files			*new_dir;

	if (!(new_dir = get_file_info(dir_name, 0)))
		return (0);
	if (new_dir->type != 'd')
	{
		if (new_dir->type == 'l' && !ft_strchr(ls_args->options, 'l'))
		{
			if (!(new_dir = get_file_info(dir_name, 1)))
				return (0);
		}
		else
		{
			lst_add_end(tmp, lst_copy_link(new_dir));
			return (1);
		}
	}
	lst_add_end(&(ls_args->dirs), new_dir);
	return (1);
}

static void	modify_options(char **options)
{
	char	*tmp;

	if (ft_strchr(*options, 'g'))
	{
		tmp = ft_strjoin(*options, "l");
		ft_memdel((void **)options);
		*options = ft_strdup(tmp);
	}
	if (ft_strchr(*options, 'f'))
	{
		tmp = ft_strjoin(*options, "a");
		ft_memdel((void **)options);
		*options = ft_strdup(tmp);
	}
}

static void	print_while(t_files *file, t_ls_args *ls_args)
{
	t_files *tmp;

	while (file)
	{
		print_file(file, ls_args, 0, 0);
		tmp = file;
		file = file->next;
		free(tmp);
	}
	ft_putchar('\n');
}

void		check_arguments(int ac, char **av, t_ls_args *ls_args)
{
	int			i;
	char		*args_list;
	t_files		*tmp;

	tmp = NULL;
	i = 0;
	args_list = ft_strnew(2);
	while (++i < ac && av[i][0] == '-' && is_option(&av[i][1], ls_args))
	{
		args_list = ft_mem_realloc(args_list,
				ft_strlen(args_list) + ft_strlen(av[i]));
		args_list = ft_strcat(args_list, &av[i][1]);
	}
	modify_options(&args_list);
	ls_args->options = ft_strdup(args_list);
	ft_memdel((void **)&args_list);
	(i == ac) ? store_requested_dir(".", ls_args, &tmp) : 0;
	while (i < ac)
	{
		if (!store_requested_dir(av[i], ls_args, &tmp))
			print_error(av[i], 1);
		i++;
	}
	if (tmp)
		print_while(sort_from_options(tmp, ls_args->options, 1), ls_args);
}
