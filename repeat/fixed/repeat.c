/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:25:44 by rgarrigo          #+#    #+#             */
/*   Updated: 2024/02/24 18:07:20 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	verif(int argc, char *s)
{
	int	i;
	int	nb_len;

	if (argc != 2)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (!is_digit(s[i]))
			return (-1);
		nb_len = 0;
		while (is_digit(s[i + nb_len]))
			++nb_len;
		if (nb_len >= 5)
			return (-1);
		i += nb_len;
		if (!s[i])
			return (-1);
		++i;
	}
	return (0);
}

int	repeated_size(char *s)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (s[i])
	{
		size += atoi(s + i);
		while (is_digit(s[i]))
			++i;
		++i;
	}
	return (size);
}

char	*repeated(char *s)
{
	char	*output;
	int		count;
	int		i;
	int		j;

	output = malloc(repeated_size(s) + 1);
	if (!output)
		return (NULL);
	j = 0;
	i = 0;
	while (s[i])
	{
		count = atoi(s + i);
		while (is_digit(s[i]))
			++i;
		while (count--)
			output[j++] = s[i];
		++i;
	}
	output[j] = '\0';
	return (output);
}

int	main(int argc, char **argv)
{
	char	*output;

	if (verif(argc, argv[1]) == -1)
		return (2);
	output = repeated(argv[1]);
	if (!output)
		return (1);
	if (output[0])
		printf("%s\n", output);
	free(output);
	return (0);
}
