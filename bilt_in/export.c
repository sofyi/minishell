/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:20:29 by slamhaou          #+#    #+#             */
/*   Updated: 2025/05/28 16:10:24 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../heder_shell.h"

int	chake_args(char *str)
{
	int	i;

	i = 0;
	if (str[i] <= '9' && str[i] >= '0')
		return (1);
	while (str[i])
	{
		if (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z'))
			if (str[i] != '=' && str[i] != '_')
				return (1);
		i++;
	}
	return (0);
}
int	serch_tosawy_(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}
void	print_all_var(t_env_list *env)
{
	while (env)
	{
		if (env->content.last)
			printf("declare -x %s=\"%s\"\n", env->content.first, env->content.last);
		else
			printf("declare -x %s\n", env->content.first);
		env = env->next;
	}
}
int	my_export(t_env_list *env, char **args)
{
	int	i;
	int ret;

	i = 1;  
	ret = 0;
	if (args[i] == NULL)
		print_all_var(env);
	while (args[i])
	{
		if (chake_args(args[i]))
		{
			write_erorr("Minishell: export: ", args[i]);
			write_erorr("not a balid identifier\n", NULL);
			ret = 1;
		}
		else
			ft_lstadd_back(&env,ft_lstnew(args[i]));
		i++;
	}
	return (0);
}
