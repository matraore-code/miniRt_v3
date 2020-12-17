/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 03:10:21 by matraore          #+#    #+#             */
/*   Updated: 2020/12/17 05:35:47 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <fcntl.h>
# define BUFFER_SIZE 10 



char	*ft_strjoin_l(char *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	len = ft_strlen(s1) + ft_strlen((char *)s2);
	str = malloc(len * sizeof(char) + 1);
	if (str == NULL)
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[len] = '\0';
	return (str);
}

void	parse_scene(const char *str)
{
	const char *id;
	char		*file;
	char		*data;
	int			fd;
	int			b_r;
	char		Buffer[BUFFER_SIZE + 1];

	id = "RAc";
	file = NULL;
	fd = open(filename, O_RDONLY | O_NOFOLLOW);
	while (b_r = read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[b_r] = '\0';
		file = ft_join_l(file, buffer);
	}
	close(fd);
	data = file;
	while (*file)
	{
		if (*file == '\n')
			file++;


}

int		main(int argc, char **argv)
{
	//char	**file_name;
	size_t	length;

	if ((argc < 2) || (argc > 3))
	{
		ft_putstr_fd("PARAMETER ERROR\n");
		return (0);
	}
	length = ft_strlen(argv[1]);
	if	(length < 3)
	{
		ft_putstr_fd("WORNG NAME OF SCENE");
		return (0);
	}
	argv[1] += length - 3;
	if (ft_strncmp(argv[1], ".rt", 3))
	{
		ft_putstr_fd("WRONG FILE EXTENSION");
		return (0);
	}
	printf("FILENAME SUCCESSFULLY CHECKED");
	return (0);
}

