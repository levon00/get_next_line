#include "get_next_line_bonus.h"

static char	*correct_reminder(char *reminder)
{
	char	*correct_reminder;
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
	correct_reminder = malloc(ft_strlen(reminder) - i + 1);
	if (!correct_reminder)
		return (free(reminder), NULL);
	i++;
	while (reminder[i])
		correct_reminder[j++] = reminder[i++];
	correct_reminder[j] = '\0';
	return (free(reminder), correct_reminder);
}

static char	*cut_reminder(char *reminder)
{
	char	*line;
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

static char	*buffer_read(char *reminder, int fd)
{
	ssize_t	bytes;
	char	*tmp;

	bytes = 1;
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
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
	return (free(tmp), reminder);
}

char	*get_next_line(int fd)
{
	static char	*reminder[1024];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1024)
		return (NULL);
	reminder[fd] = buffer_read(reminder[fd], fd);
	if (!reminder[fd] || reminder[fd][0] == '\0')
	{
		free(reminder[fd]);
		reminder[fd] = NULL;
		return (NULL);
	}
	line = cut_reminder(reminder[fd]);
	reminder[fd] = correct_reminder(reminder[fd]);
	return (line);
}
