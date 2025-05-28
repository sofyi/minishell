/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heder_shell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slamhaou <slamhaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:47:26 by slamhaou          #+#    #+#             */
/*   Updated: 2025/05/28 16:18:29 by slamhaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HEDER_SHELL_H
# define HEDER_SHELL_H

//-----------INCLUDE-------------

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#define SUCCESS 0
#define	ERORR	1

//-----------EXECUTION----------
//.
//			SAFIYA
//.
//------------------------------

typedef struct data_env
{
	char	*first;
	char	*last;
}t_data;

typedef struct s_list
{
	t_data			content;
	struct s_list	*next;
}t_env_list;

typedef struct my_list
{
	char 	*cmd;
	char 	**args;
	struct my_list *next;
}t_my_list;

typedef	struct variabel
{
	int		i;
	char	*path;
	char	*new_path;
	char	**split_path;
}t_var;


t_env_list	*get_list_env(char **env);
t_env_list	*ft_lstnew(void *content);
void		ft_lstadd_back(t_env_list **lst, t_env_list *new);
int			ft_strlen(char *str);
int			str_cmp(char *s1, char *s2);
char		**ft_split(char *str, char sep);
char		*str_join(char *s1, char *s2);
char		*str_dup(char *s);
void		free_tab(char **str);
char		*my_get_env(char *str, t_env_list *env);
//////
int		my_pwd(void);
void	my_env(t_env_list *env);
int		my_cd(t_env_list *ev, char **arg);
int		my_unset(t_env_list **en, char **args);
int		my_export(t_env_list *env, char **args);
int		write_erorr(char *str, char *var);
# endif
