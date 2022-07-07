/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimrod <nimrod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:22:08 by nsartral          #+#    #+#             */
/*   Updated: 2022/07/07 17:16:42 by nimrod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int	main(int argc, char **argv, char **envp)
{
	int			count;
	char		*str;
	t_command	*cmd;
	t_env *env;
	t_env *tmp;

	(void)argc;
	(void)argv;
	env = env_to_list(envp);
	str = (char *)malloc(sizeof(char) * 4096);
	while (1)
	{
		write(1, "groshell> ", 10);
		count = read(1, str, 4096);
		str[count] = '\0';
		if ((ft_strncmp(str, "exit", 4) == 0) && ft_strlen(str) == 5)
			break ;
		str = environning(str, env);
		cmd = parse_line(str, env);
		tmp = exec_command(cmd, env);
		if (tmp != NULL)
			env = tmp;
	}
	return (0);
}