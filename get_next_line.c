/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:57:20 by mesasaki          #+#    #+#             */
/*   Updated: 2025/01/18 16:14:51 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnextline.h"

char	*read_joint(int fd, char *handOver);
char	*get_line_from_handOver(char **handOver);
char	*get_next_line(int fd);

char	*read_joint(int fd, char *handOver)
{
	char	*tmp;
	ssize_t	bytesread;
	char	*new_handOver;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp || BUFFER_SIZE >= SIZE_MAX)
		return (NULL);
	bytesread = read(fd, tmp, BUFFER_SIZE);
	if (bytesread <= 0)
	{
		free(tmp);
		return (NULL);
	}
	tmp[bytesread] = '\0';
	if (!handOver)
		handOver = ft_strdup("");
	new_handOver = ft_strjoin(handOver, tmp);
	free(handOver);
	free(tmp);
	return (new_handOver);
}

char	*get_line_from_handOver(char **handOver)
{
	char	*line;
	char	*tmp;
	size_t	i;

	i = 0;
	if (!*handOver)
		return (NULL);
	while ((*handOver)[i] && (*handOver)[i] != '\n')
		i++;
	if ((*handOver)[i] == '\n')
	{
		line = malloc(i + 2);
		if (!line)
			return (NULL);
		ft_memcpy(line, *handOver, i + 1);
		line[i + 1] = '\0';
		tmp = ft_strdup(*handOver + i + 1);
		free(*handOver);
		*handOver = tmp;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*handOver;
	char		*prev;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= SIZE_MAX)
		return (NULL);
	while (!handOver || !ft_strchr(handOver, '\n'))
	{
		prev = handOver;
		handOver = read_joint(fd, handOver);
		if (!handOver)
			return (prev);
	}
	line = get_line_from_handOver(&handOver);
	return (line);
}

int	main(void)
{
	int fd;
	char *return_str;

	fd = open("test.txt", O_RDONLY);
	// fd = 1;
	if (fd < 0)
		return (1);
	// return_str = get_next_line(fd);
	// printf("%s", return_str); // 1文字出力
	// free(return_str);
	// return_str = get_next_line(fd);
	// printf("%s", return_str); // 1文字出力
	// free(return_str);
	// return_str = get_next_line(fd);
	// printf("%s", return_str); // 1文字出力
	// free(return_str);
	// return_str = get_next_line(fd);
	// printf("%s", return_str); // 1文字出力
	// free(return_str);
	// return_str = get_next_line(fd);
	// printf("%s", return_str); // 1文字出力
	// free(return_str);
	// return_str = get_next_line(fd);
	// printf("%s", return_str); // 1文字出力 //
	// free(return_str);
	// int i = 0;
	while (return_str)
	{
		return_str = get_next_line(fd);
		printf("%s", return_str); // 1文字出力
		free(return_str);
		// i++;
	}

	close(fd);
	return (0);
}