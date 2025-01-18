/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:57:20 by mesasaki          #+#    #+#             */
/*   Updated: 2025/01/13 19:34:28 by mesasaki         ###   ########.fr       */
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
	bytesread = read(fd, tmp, BUFFER_SIZE); //読み込んだバイト数をリターン
	if (bytesread <= 0)                     //読み込んだがEOF,何もなかった、もしくはエラーの場合
	{
		free(tmp);
		return (NULL);
	}
	tmp[bytesread] = '\0'; //めっちゃ大事
	if (!handOver)
		handOver = ft_strdup(""); // handOverがNULLなら空文字列で初期化？？？？？？？？？？？・
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
	if (!*handOver) //この処理いるか要確認
		return (NULL);
	while ((*handOver)[i] && (*handOver)[i] != '\n')
		i++;
	if ((*handOver)[i] == '\n')
	{
		line = malloc(i + 2); // 改行含む + '\0'
		if (!line)
			return (NULL);
		ft_memcpy(line, *handOver, i + 1);
		line[i + 1] = '\0';
		tmp = ft_strdup(*handOver + i + 1); // 残りを tmp にコピー（改行の後ろから）
		free(*handOver);                    //ここでhandOver解放
		*handOver = tmp;                    //改行のあとの残りの文字たちが入った。
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*prev;
	static char	*handOver;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > SSIZE_MAX)
		return (NULL);
	while (!handOver || !ft_strchr(handOver, '\n'))
	{
		prev = handOver;                     //以前の保持
		handOver = read_joint(fd, handOver); //新しいデータを読み込んで上書き
		if (!handOver)                       //読み込んだ結果、EOFの場合
			return (prev);
		if (prev == handOver && *prev != '\0') //すべて読んだが、新しいものはなかった// 残っている内容を返却
			return (line = ft_strdup(prev), free(prev), handOver = NULL, line);
		if (prev == handOver)
			return (NULL);
	}
	line = get_line_from_handOver(&handOver); //実行後handOverはfreeされる
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