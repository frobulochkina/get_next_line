#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int				i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*s;
	unsigned char	*tmp;
	size_t			i;

	s = malloc(count * size);
	tmp = (unsigned char*)s;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < count)
	{
		tmp[i] = '\0';
		i++;
	}
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*newcon;
	size_t			i;
	size_t			j;
	size_t			len_s1;
	size_t			len_s2;

	if ((s1 == 0 && s2 == 0) || s1 == 0)
		return (NULL);
	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(newcon = (char*)malloc(sizeof(char*) * (len_s1 + len_s2 + 1))))
		return (0);
	while (i < len_s1 || i < (len_s1 + len_s2))
	{
		while (i < len_s1)
		{
			newcon[i] = s1[i];
			i++;
		}
		newcon[i++] = s2[j++];
	}
	newcon[i] = '\0';
	return (newcon);
}

char	*ft_strdup(const char *s1)
{
	char			*news1;
	int				i;
	int				size;

	size = 0;
	while (s1[size])
		size++;
	if (!(news1 = ft_calloc(size + 1, sizeof(char))))
		return (0);
	i = 0;
	while (s1[i])
	{
		news1[i] = s1[i];
		i++;
	}
	news1[i] = '\0';
	return (news1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	size_t			j;

	j = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		if (!(subs = ft_calloc(1, sizeof(char))))
			return (0);
		subs[0] = '\0';
		return (subs);
	}
	else if (ft_strlen(s) < len ||
	(!(subs = ft_calloc(len + 1, sizeof(char)))))
	{
		if (!(subs = ft_calloc((ft_strlen(s) - start) + 1, sizeof(char))))
			return (0);
	}
	while (s[start] && j < len)
		subs[j++] = s[start++];
	subs[len] = '\0';
	return (subs);
}
