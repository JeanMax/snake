/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:07:11 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/28 19:58:15 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_realloc_str(char *old, size_t new_size)
{
	char	*new;
	size_t	old_size;

	old_size = ft_strlen(old) + 1;
	if (!(new = (char *)ft_memalloc(new_size ? sizeof(old) * new_size : 1)))
		return (NULL);
	if (old)
	{
		ft_memcpy(new, old, (old_size > new_size) ? (new_size) : (old_size));
		ft_memdel((void *)&old);
	}
	return (new);
}

static	char	*ft_splitline(char *line, char **left)
{
	char	*new;
	size_t		len;

	len = 0;
	while (line[len] != '\n' && line[len])
		len++;
	new = ft_strsub(line, 0, len);
	free(*left);
	if (len < ft_strlen(line))
		*left = ft_strsub(line, len + 1, (ft_strlen(line) - (len + 1)));
	free(line);
	return (new);
}

static int			read_it(char **line, int fd)
{
	char        *buff;
	int			ret;

	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (ft_memchr(*line, '\n', ft_strlen(*line)) == NULL)
    {
        while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
        {
            buff[ret] = '\0';
            *line = ft_strcat(ft_realloc_str(*line, ft_strlen(buff) + ft_strlen(*line)), buff);
            if (ft_memchr(*line, '\n', ft_strlen(*line)) != NULL)
                break ;
        }
    }
	free(buff);
	return (ret);
}

int         get_next_line(int const fd, char **line)
{
	static char *left;
	int         ret;
	int         res;

	res = 1;
	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	if (!(*line = ft_strnew(1)))
		return (-1);
	if (left)
	{
		free(*line);
		*line = ft_strdup(left);
	}
	if ((ret = read_it(line, fd)) < 0)
		return (-1);
	*line = ft_splitline(*line, &left);
	res = ((ret < BUFF_SIZE) && *line[0] == '\0') ? 0 : 1;
	return (res);
}
