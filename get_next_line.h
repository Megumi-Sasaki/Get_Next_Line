#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#endif

#include <fcntl.h>
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*read_joint(int fd, char *handOver);
char	*ft_strdup(const char *string);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*get_line_from_handOver(char **handOver);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t len);

#endif