#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int	fd;

	fd = open("", O_RDONLY);

	get_next_line(fd);
}