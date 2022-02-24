#include "get_next_line.h"

size_t	ft_space_n(const char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (0);
}

char	*ft_processing(char **ostatok, char *buf_line)
{
	char			*tmp;

	if (*ostatok == NULL)
	{
		*ostatok = ft_strdup(buf_line);
		if (!*ostatok)
			return (NULL);
	}
	else
	{
		tmp = *ostatok;
		*ostatok = ft_strjoin(*ostatok, buf_line);
		if (!*ostatok)
		{
			free(tmp);
			return (NULL);
		}
		free(tmp);
	}
	return (*ostatok);
}

int		ft_write_to_line(char **ostatok, char **line, int rd)
{
	int				len;
	char			*tmp;

	if (ft_strchr(*ostatok, '\n'))
	{
		len = ft_space_n(*ostatok);
		if (!(*line = ft_substr(*ostatok, 0, len)))
			free(ostatok);
		tmp = *ostatok;
		if (!(*ostatok = ft_substr(*ostatok, len + 1, ft_strlen(*ostatok))))
		{
			free(*line);
			free(tmp);
		}
		free(tmp);
	}
	else if ((ft_strchr(*ostatok, '\0') && rd == 0))
	{
		len = ft_strlen(*ostatok);
		if (!(*line = ft_substr(*ostatok, 0, ft_strlen(*ostatok))))
			free(ostatok);
		free(*ostatok);
	}
	return ((!*line || !*ostatok) ? -1 : 1);
}

int		get_next_line(int fd, char **line)
{
	int				rd;
	char			buf_line[BUFFER_SIZE + 1];
	static	char	*ostatok;

	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	while (((rd = read(fd, buf_line, BUFFER_SIZE)) >= 0))
	{
		buf_line[rd] = '\0';
		if (!(ostatok = ft_processing(&ostatok, buf_line)))
			return (-1);
		if (ft_strchr(ostatok, '\n'))
			return (ft_write_to_line(&ostatok, line, rd));
		else if (ft_strchr(ostatok, '\0') && rd == 0)
		{
			if (ft_write_to_line(&ostatok, line, rd) == -1)
				return (-1);
			ostatok = NULL;
			break ;
		}
	}
	return ((rd < 0) ? -1 : 0);
}
