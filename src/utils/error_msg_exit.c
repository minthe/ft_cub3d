/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:19:39 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/28 13:22:30 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	error_exit(t_var *var)
{
	cleanup(var);
	ft_free_struct(var);
	free(var);
	exit (EXIT_FAILURE);
}

// outputs str as error message and exits
void	error_msg_exit(t_var *var, char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	cleanup(var);
	ft_free_struct(var);
	free(var);
	exit (EXIT_FAILURE);
}

// outputs str as error message and exits
void	error_msg(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit (EXIT_FAILURE);
}
