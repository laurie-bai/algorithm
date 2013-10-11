//将绝对路径转换成相对路径。
//例如 input: /home/news/../tmp/game/../; 
//ouptut: /home/tmp/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *converse_path(char *src)
{
	if (src == NULL)
		return NULL;
	int  i, j, len;
	int  point_cnt;
	char *dst;

	i = j = 0;
	len = strlen(src);
	dst = malloc(sizeof(len));
	if (dst == NULL)
	{
		printf("error: malloc\n");
		return NULL;
	}
	while (src[i] != '\0')
	{
		while (src[i] != '.')
			dst[j++] = src[i++];
		point_cnt = 0;
		while (src[i] == '.')
		{
			i++;
			point_cnt++;
		}
		if (point_cnt == 2)
		{
			j -= 2;
			while (dst[j] != '/' && j >= 0)
				j--;
			if (j < 0)
				j += 2;
		}
	}
	dst[j] = '\0';
	
	return dst;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return -1;
	printf("%s\n", converse_path(argv[1]));
	return 0;
}
