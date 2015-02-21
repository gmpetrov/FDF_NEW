/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 20:15:16 by gmp               #+#    #+#             */
/*   Updated: 2015/02/21 12:25:58 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_get_data(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	int		**tab;

	i = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf [data_file]\n");
		exit(0);
	}
	i = ft_data_size(argv[1]);
	tab = (int**)malloc((i + 1)* (sizeof(*tab)));
	tab[i + 1] = NULL;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		tab[i] = ft_put_data(line);
		i++;
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
	}
	return (tab);
}

int		ft_tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}

int		ft_data_size(char *file)
{
	int		fd;
	int		i;
	char	*line;
	t_env 	*e;

	e = getEnv();
	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		free(line);
		i++;
	}
	close(fd);
	e->map_heigth = i;
	return (i);
}

int		*ft_put_data(char *str)
{
	char	**chartab;
	int		*tab;
	int		i;
	int		j;

	chartab = ft_strsplit(str, ' ');
	i = ft_tablen(chartab);
	tab = (int*)malloc((i + 1) * (sizeof(*tab)));
	tab[0] = i;
	j = 0;
	while (++j <= i)
		tab[j] = ft_atoi(chartab[j - 1]);
	return (tab);
}