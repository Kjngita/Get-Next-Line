#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int	fd = open("text1.txt", O_RDONLY);
	char *q = get_next_line(fd);
	//char *w = get_next_line(fd);

	__builtin_printf("%s", q);
	//__builtin_printf("%s", w);

	free(q);
	//free(w);
	close(fd);
}