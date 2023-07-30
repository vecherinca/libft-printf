#include "pipex.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{	
	void	*output;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb * size < size)
		return (0);
	output = (void *)malloc(size * nmemb);
	if (!output)
		return (NULL);
	ft_bzero(output, nmemb * size);
	return (output);
}