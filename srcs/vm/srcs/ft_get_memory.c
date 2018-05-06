#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define HEX "0123456789ABCDEF"

char	*ft_get_hex_memory(void *m, size_t mem_size) // mem_size en octet
{
	char	*ret;
	char	*rusher;
	uint8_t	*tmp;

	if (!m || !(ret = (char*)malloc(mem_size * 2) + 1))
		return (NULL);
	rusher = ret;
	tmp = (uint8_t*)m;
	while (mem_size)
	{
		*rusher++ = HEX[*tmp >> 4];
		*rusher++ = HEX[*tmp & 0x0F];
		++tmp;
		--mem_size;
	}
	*rusher = '\0';
	return (ret);
}

int		main() {
	char	*hex_memory = ft_get_hex_memory("\xff\x2\x63", 3);
	printf("%s\n", hex_memory);
	free(hex_memory);
	return 0;
}
