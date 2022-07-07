#include "execution.h"

char *get_content(char *envp)
{
	char *str;
	int i;
	int j;
	
	i = -1;
	j = -1;
	while (envp[++i] && envp[i] != '=')
		;
	++i;
	while (envp[i + ++j])
		;
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (str == NULL)
		return (NULL);
	str[j] = '\0';
	j = -1;
	while (envp[i + ++j])
		str[j] = envp[i + j];
	return (str);
}

char *get_name(char *envp)
{
	char *str;
	int i;
	
	i = -1;
	while (envp[++i] && envp[i] != '=')
		;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	i = -1;
	while (envp[++i] && envp[i] != '=')
		str[i] = envp[i];
	return (str);
}

int	has_equal(char *str)
{
	int i;
	
	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
			return (i);
	}
	return (0);
}

bool	check_envp(char **envp)
{
	int i;
	
	i = -1;
	while (envp[++i])
	{
		if (has_equal(envp[i]) < 1)
			return (printf("wrong env variable"), 0);
	}
	return (1);
}

t_env	*env_to_list(char **envp)
{
	int i;
	t_env *env;
	
	if (envp[0] == NULL)
		return (printf("no env"), NULL);
	if (check_envp(envp) == 0)
		return (NULL);
	i = -1;
	while (envp[++i])
		add_back_lst(&env, new_lst(get_name(envp[i]), get_content(envp[i])));
	return (env);
}

void	read_list(t_env *env)
{
	t_env *tmp;
	
	tmp = env;
	while (tmp != NULL)
	{
		printf("%s\n", tmp->name);
		printf("%s\n", env->content);
		tmp = tmp->next;
	}
}