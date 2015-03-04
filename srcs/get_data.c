/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 20:15:16 by gmp               #+#    #+#             */
/*   Updated: 2015/03/04 19:04:31 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int		ft_tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}

static	int		ft_data_size(char *file)
{
	int		fd;
	int		i;
	char	*line;
	t_env	*e;

	e = get_env();
	i = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_usage();
	while (get_next_line(fd, &line) != 0)
	{
		free(line);
		i++;
	}
	close(fd);
	e->map_heigth = i;
	return (i);
}

static	int		*ft_put_data(char *str)
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

int				**ft_get_data(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	int		**tab;

	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) < 0 \
		|| (i = ft_data_size(argv[1])) == 0)
		ft_usage();
	tab = (int**)malloc((i + 1) * (sizeof(*tab)));
	tab[i + 1] = NULL;
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (is_str_nb_only(line) == -1)
			ft_usage();
		tab[i] = ft_put_data(line);
		i++;
		free(line);
	}
	return (tab);
}
