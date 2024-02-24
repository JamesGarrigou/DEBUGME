/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:32:34 by rgarrigo          #+#    #+#             */
/*   Updated: 2024/02/24 16:36:40 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

int	is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

void	capitalize(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		if (is_lower(s[i]))
			s[i] += 'A' - 'a';
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (2);
	capitalize(argv[1]);
	if (write(1, argv[1], ft_strlen(argv[1])) < 0)
		return (1);
	return (0);
}
