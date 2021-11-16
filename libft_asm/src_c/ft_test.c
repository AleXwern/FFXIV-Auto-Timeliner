#include <sys/mman.h>
#include <stdlib.h>

void	*test(size_t len)
{
	void	*ptr;
	ptr = mmap(NULL, len, PROT_READ | PROT_WRITE,
		MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);


}