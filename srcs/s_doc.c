/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_doc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:35:56 by msorin            #+#    #+#             */
/*   Updated: 2017/11/17 13:15:29 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

static char		*st_set_name(char *name)
{
	char	*ret;

	if (!ft_strcmp(name, ""))
		ret = ft_strdup("/");
	else
		ret = ft_strdup(name);
	return (ret);
}

static t_doc	*st_new_doc(void)
{
	t_doc	*tmp;

	if (!(tmp = (t_doc*)malloc(sizeof(t_doc))))
		return (NULL);
	tmp->name = NULL;
	tmp->path = NULL;
	tmp->usr = NULL;
	tmp->grp = NULL;
	tmp->mtime = 0;
	tmp->sub_dir = NULL;
	tmp->stat = NULL;
	tmp->to_print = NULL;
	tmp->err = NULL;
	return (tmp);
}

t_doc			*insert_value(char *name, char *path, int flag, int init)
{
	t_doc	*tmp;

	if (!(tmp = st_new_doc()))
		return (NULL);
	tmp->name = init ? st_set_name(name) : ft_strdup(name);
	tmp->path = ft_strdup(path);
	tmp->stat = malloc(sizeof(t_stat));
	if (lstat(path, tmp->stat))
		tmp->err = set_error(tmp->name, errno);
	else
	{
		tmp->usr = set_usr(tmp->stat->st_uid);
		tmp->grp = set_grp(tmp->stat->st_gid);
		tmp->mtime = tmp->stat->st_mtime;
	}
	if (flag & 1)
		ft_strdel(&name);
	if (flag & 2)
		ft_strdel(&path);
	return (tmp);
}

/*
** We use un pointer to a t_doc array for easyest usage
** The functions stat and lstat need the absolute path of a file / folder
** so we have to keep in memory the pwd
*/

void			set_arg(t_ls *ls, char **av, int ac, int i)
{
	int		j;
	t_doc	**data;
	char	*name;
	t_doc	*tmp;

	tmp = NULL;
	j = -1;
	if (!(data = malloc(sizeof(t_doc*) * (ac - i + 1))))
		ft_error_init();
	while (++j + i < ac)
	{
		name = ft_strsplit_last(av[i + j], '/', 1);
		data[j] = insert_value(name, av[i + j], 1, 1);
	}
	if (j == 0)
	{
		data[0] = insert_value(".", ls->pwd, 0, 1);
		j++;
	}
	data[j] = NULL;
	ls->arg = data;
}
