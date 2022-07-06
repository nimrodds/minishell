#include "execution.h"

bool	check_echo_flag(char **argz)
{
	if (argz[1] == NULL)
		return (0);
	if (ft_strncmp(argz[1], "-n", 3) == 0)
		return (1);
	return (0);
}

void	exec_echo(t_command *cmd)
{
	int i;
	
	i = 0;
	if (check_echo_flag(cmd->arg->argz))
		i++;
	while (cmd->arg->argz[++i])
	{
		write(1, cmd->arg->argz[i], ft_strlen(cmd->arg->argz[i]));
		write(1, " ", 1);
	}
	if (!check_echo_flag(cmd->arg->argz))
		write(1, "\n", 1);
}