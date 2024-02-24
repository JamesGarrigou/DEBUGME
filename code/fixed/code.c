/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:05:20 by rgarrigo          #+#    #+#             */
/*   Updated: 2024/02/24 18:26:16 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	f(char *s, int i)
{
	int	j;

	j = i;
	i = -1;
	while (++i <= j)
		if (s[i] > 0x60 && s[i] < 0x7B)
			s[i] &= ~0x20;
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return (2);
	i = 0;
	while (*(argv[1] + i))
		++i;
	f(argv[1], i);
	if (write(1, argv[1], i) < 0)
		return (1);
	return (0);
}
