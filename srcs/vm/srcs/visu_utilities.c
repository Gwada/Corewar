#include "visu.h"

char	*ft_get_hex_memory(void *m, size_t mem_size)
{
	char	*ret;
	char	*rusher;
	uint8_t	*tmp;

	if (!m || !(ret = (char*)malloc(mem_size * 2)))
		return (NULL);
	rusher = ret;
	tmp = (uint8_t*)m;
	while (mem_size)
	{
		*rusher++ = HEX_DIGIT[*tmp >> 4];
		*rusher++ = HEX_DIGIT[*tmp & 0x0F];
		++tmp;
		--mem_size;
	}
	return (ret);
}

void	ft_bzero(void *m, size_t len)
{
	uint64_t	*lw;

	while (len % 8)
	{
		*(uint8_t *)m++ = (uint8_t)0;
		--len;
	}
	if (len)
	{
		lw = (uint64_t *)m;
		while (len)
		{
			*lw++ = (uint64_t)0;
			len -= 8;
		}
	}
}
