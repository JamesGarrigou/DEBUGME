/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:08:12 by rgarrigo          #+#    #+#             */
/*   Updated: 2024/02/24 19:10:55 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_even(int x);

int	main(void)
{
	int	i;

	i = -5;
	while (i < 33)
	{
		if (is_even(i))
			printf("%d is even\n", i);
		else
			printf("%d is odd\n", i);
		i += 7;
	}
	return (0);
}
