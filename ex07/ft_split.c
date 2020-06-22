#include "libft.h"

static char			**ft_malloc_split(char const *s, char d, unsigned int *ui,
		unsigned int *uwc)
{
	unsigned int	word_count;
	unsigned int	i;
	unsigned int	y;

	if (!s)
		return (NULL);
	word_count = 0;
	i = 0;
	while (s[i])
	{
		y = 0;
		while (s[i + y] && s[i + y] != d)
			y += 1;
		if (y > 0)
		{
			word_count += 1;
			if (!s[i += y])
				break ;
		}
		i += 1;
	}
	word_count += 1;
	*ui = -1;
	*uwc = -1;
	return (malloc(word_count * sizeof(char*)));
}

char				**ft_split(char const *s, char d)
{
	char			**output;
	unsigned int	word_count;
	unsigned int	i;
	unsigned int	y;

	if (!s || !(output = ft_malloc_split(s, d, &i, &word_count)))
		return (NULL);
	while ((y = 0) || s[++i])
	{
		while (s[i + y] && s[i + y] != d)
			y += 1;
		if (y > 0)
		{
			if (!(output[++word_count] = ft_substr(s, i, y)))
			{
				if (word_count > 0)
					ft_free_until((void**)output, &output[word_count - 1]);
				free(output);
				return (NULL);
			}
			if (!s[i += y])
				break ;
		}
	}
	return (output + (long)(output[++word_count] = NULL));
}
