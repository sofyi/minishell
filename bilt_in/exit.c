/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:21:37 by slamhaou          #+#    #+#             */
/*   Updated: 2025/05/31 18:29:33 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../heder_shell.h"

int	ft_atoi(char *str, int *err)
{
	int	i;
	int	sin;
	unsigned long long	n;

	
	i = 0;
	n = 0;
	sin = 1;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sin = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		n = n * 10 + (str[i] - 48);
		if (((sin == 1 ) && n > LLONG_MAX ) || ((sin == -1) && n > (unsigned long long )LLONG_MAX + 1))
		{
				*err = -1;
			return((int)n);
		}
		i++;
	}
	return ((int)n);
}

int	another_alpha(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}
void	my_exit(char **args)
{
  ////rjee l atoi knto ktshofy long long max
	int	max_exit;
	int	num;
	int	eror;
	
	max_exit = 255;
	eror = 1;
	if (another_alpha(args[1]))
	{
		write(2, "exit\n", 6);
		write(2, "Minishell: exit: ", 18);
		write(2, args[1], ft_strlen(args[1]));
		write(2, ": numeric argument required\n", 28);
		exit (255);
	}
	if	(args[2] != NULL)
	{
		write(2, "exit\n", 5);
		write (2, "Minishell: exit: too many arguments\n", 37);
		return ;
	}
	num = ft_atoi(args[1], &eror);
	printf("%d\n",  num);
	if (eror == -1)
	{
		write(2, "minishell: exit: ", 18);
		write(2, args[1], ft_strlen(args[1]));
		write(2, ": numeric argument required\n", 29);
	}
	exit (num);
}
