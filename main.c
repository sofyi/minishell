/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:32:00 by slamhaou          #+#    #+#             */
/*   Updated: 2025/05/30 09:07:20 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heder_shell.h"

t_my_list *ft_lst_new(char *cmd, char **args) 
{
	t_my_list *list = malloc(sizeof(t_my_list));
	if (!list)
		return NULL;
	list->cmd = strdup(cmd);
	list->args = args;
	list->next = NULL;
	return list;
}

char **split_args(char *s) {
	int count = 0;
	char **result = malloc(sizeof(char *) * 100); 
	char *token = strtok(s, " ");
	while (token) {
		result[count++] = strdup(token);
		token = strtok(NULL, " ");
	}
	result[count] = NULL;
	return result;
}

t_my_list *smal_list(char *s)
{
	char **args = split_args(s);
	if (!args || !args[0])
		return NULL;
	return ft_lst_new(args[0], args);
}
int		bilt_in(t_my_list *list, t_env_list **list_env)
{
	if (str_cmp(list->cmd, "pwd"))
		my_pwd();
	else if (str_cmp(list->cmd, "env"))
		my_env(*list_env);
	else if (str_cmp(list->cmd, "cd"))
		my_cd(*list_env,list->args);
	else if (str_cmp(list->cmd, "unset"))
		my_unset(list_env,list->args);
	else if (str_cmp(list->cmd, "export"))
		my_export(*list_env,list->args);
	else 
		return(0);	
	return(1);
}

int main(int ac, char **av, char **env) 
{
	char *input;
	t_my_list *cmd_list;
	t_env_list *e;

	ac = 0;
	av = NULL;
	e = get_list_env(env);
	input = "wee";
	while (input) 
	{
		input = readline("Minishell$ ");
		cmd_list = smal_list(input);
		bilt_in(cmd_list, &e);
		//var_handler()
	}
	return 0;
}