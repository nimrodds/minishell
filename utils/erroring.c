/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erroring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:34:19 by nsartral          #+#    #+#             */
/*   Updated: 2022/07/30 13:57:46 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	print_error_message()
{
	if (singleton(0, 0) == 127 || singleton(0, 0) == 2)
		write(2, "command not found\n", ft_strlen("command not found\n"));
	else
		write(2, "need to associate error message", ft_strlen("need to associate error message"));
}

void	ft_error(char *str, int error_type, bool update)
{
	if (update)
	{
		singleton(error_type, 1);
		write(2, str, ft_strlen(str));
	}
	if (!update)
		ft_putnbr_fd(singleton(0, 0), 2);
	write(2, " : ", 3);
	print_error_message();
	// write(2, strerror(singleton(0, 0)), ft_strlen(strerror(singleton(0, 0))));
}
	// exit(singleton(0, 0));
