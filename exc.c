/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 17:38:08 by slamhaou          #+#    #+#             */
/*   Updated: 2025/05/28 16:19:44 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heder_shell.h"


char	*my_get_env(char *str, t_env_list *env)
{

	while (env)
	{
		if (str_cmp(str, env->content.first))
			return (env->content.last);
		env = env->next;	
	}
	return (NULL);
}
char	*it_correct_comnd(char *cmd, t_env_list *env)
{
	char	*path;
	char	**split_path;
	char	*new_p;
	int i;

	i = 0;
	path = my_get_env("PATH", env);
	split_path = ft_split(path, ':');
	while (split_path[i])
	{
		new_p = str_join(split_path[i], cmd);
		if (access(new_p, X_OK) == 0)
		{
			free_tab(split_path);	
			return(new_p);
		}
		free(new_p);
		i++;
	}
	free_tab(split_path);
	return (NULL);
}
int		bil_in(t_my_list *list, t_env_list *list_env)
{
	if (str_cmp(list->cmd, "pwd"))
		my_pwd();
	else if (str_cmp(list->cmd, "env"))
		my_env(list_env);
	else 
		return(0);	
	return(1);
}

void	excut_comand(t_my_list *list, t_env_list *list_env)
{
	int b;
	char	*path;
	// int		child;
	char	**arg;
	
	arg = NULL;
	// int status;
	b = bil_in(list, list_env);
	if (b == 0)
	{
	//	arg = return_list_to_arg(list_env);
		path = it_correct_comnd(list->cmd, list_env);
		// if (!path)
		// 	return;
		printf("%s\n",path);
		exit(9);
		// child = fork();
		// if (child == 0)
		// {
		// 	execve(path, list->args, arg);
		// }
		// wait(&status);
		//free_tab(arg);
	}
}
void	exc(t_my_list *list, t_env_list *list_env)
{
	if (!list->next)
	{
		excut_comand(list, list_env);
	}
	else
	{
		while(list)
		{
			excut_comand(list, list_env);
			list = list->next;
		}
	}
}
