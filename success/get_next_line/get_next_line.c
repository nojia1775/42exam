#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *ft_strdup(char *str)
{
	int i = 0;
	char *dest;

	while(str[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while(str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}


char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	char line[70000];
	static int buffer_pos;
	static int buffer_readed;
	int i = 0;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	while(1)
	{
		if(buffer_pos >= buffer_readed)
		{
			buffer_readed = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_readed <= 0)
				break;
		}
		line[i++] = buffer[buffer_pos++];
		if(line[i - 1] == '\n')
			break;
	}
	line[i] = '\0';
	if(i == 0)
		return(NULL);
	return(ft_strdup(line));
}