#include "get_next_line.h"

static char	*buffer_read(int fd, char *reminder)
{
	char	*tmp;
	ssize_t	bytes;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(reminder, '\n') && bytes != 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
			return (free(reminder), free(tmp), NULL);
		tmp[bytes] = '\0';
		reminder = ft_strjoin(reminder, tmp);
		if (!reminder)
			return (free(tmp), NULL);
	}
	free(tmp);
	return (reminder);
}

static char	*correct_line(char *reminder, char *line)
{
	size_t	i;

	i = 0;
	if (!reminder || !reminder[i])
		return (NULL);
	while (reminder[i] && reminder[i] != '\n')
		i++;
	if (reminder[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (reminder[i] && reminder[i] != '\n')
	{
		line[i] = reminder[i];
		i++;
	}
	if (reminder[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*cut_stash(char *reminder)
{
	char	*cut_stash;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!reminder)
		return (NULL);
	while (reminder[i] && reminder[i] != '\n')
		i++;
	if (!reminder[i])
		return (free(reminder), NULL);
	cut_stash = malloc(ft_strlen(reminder) - i + 1);
	if (!cut_stash)
		return (free(reminder), NULL);
	i++;
	while (reminder[i])
		cut_stash[j++] = reminder[i++];
	cut_stash[j] = '\0';
	return (free(reminder), cut_stash);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	reminder = buffer_read(fd, reminder);
	if (!reminder || reminder[0] == '\0')
	{
		free(reminder);
		reminder = NULL;
		return (NULL);
	}
	line = correct_line(reminder, line);
	reminder = cut_stash(reminder);
	return (line);
}
