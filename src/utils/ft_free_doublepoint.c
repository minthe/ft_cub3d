/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_doublepoint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:28:22 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/15 16:46:53 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// frees **char
void	ft_free_doublepoint(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		if (to_free[i])
			free(to_free[i]);
		i++;
	}
	if (to_free)
		free(to_free);
}
