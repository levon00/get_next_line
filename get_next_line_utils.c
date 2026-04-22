/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhalaty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:10:01 by lkhalaty          #+#    #+#             */
/*   Updated: 2026/04/22 18:10:04 by lkhalaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

static void	ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static void	ft_strcat(char *dst, char *src)
{
	size_t	dst_len;
	size_t	i;

	i = 0;
	dst_len = ft_strlen(dst);
	while (src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*result;

	if (!str1)
	{
		str1 = (char *)malloc(1);
		if (!str1)
			return (NULL);
		str1[0] = '\0';
	}
	if (!str2)
		return (free(str1), NULL);
	result = malloc (ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!result)
		return (free(str1), NULL);
	ft_strcpy(result, str1);
	ft_strcat(result, str2);
	free(str1);
	return (result);
}
