#include "execution.h"

int	main(int argc, char **argv, char **envp)
{
	int count;
	char *str;
	(void)argc;
	(void)argv;
	(void)envp;

	str = (char *)malloc(sizeof(char) * 4096);
	while (1)
	{
		write(1, "> ",  2);
		count = read(1, str, 4096);
		str[count] = '\0';
		if ((ft_strncmp(str, "exit", 4) == 0) && ft_strlen(str) == 5)
			break;
		parse_line(str, envp);
	}
	return (0);
}
