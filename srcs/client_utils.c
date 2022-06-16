#include "../minitalk.h"

char *convert_bin(unsigned char chr)
{
	char			*result;
	unsigned int	c;
	int				j;

	result = malloc(sizeof(unsigned char) * 9);
	if (!result)
		return (NULL);
	result[8] = '\0';
	j = 7;
	c = (int)chr;
	while (j >= 0)
	{
		if (c % 2 == 1)
			result[j] = '1';
		else
			result[j] = '0';
		j--;
		c /= 2;
	}
	return (result);
}

// unsigned char *convert_bin(int n)
// {
// 	const char		*base = "01";
// 	int				i;
// 	int				j;
// 	unsigned char	*dest;

// 	i = 0;
// 	j = 0;
// 	dest = malloc(sizeof(unsigned char) * 9);
// 	while (j <= 7)
// 	{
// 		dest[i] = base[n % 2];
// 		if (n == 0)
// 			break ;
// 		n /= 2;
// 		i++;
// 		j++;
// 	}
// 	while (i < 8)
// 	{
// 		dest[i] = '0';
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	dest = ft_strrev(dest);
// 	return (dest);
// }

int g_ok = 0;

void send_sig(int pid, char *msg)
{
	int		i = 0;
	int		j;
	char	*bin;

	while (msg[i])
	{
		j = 0;
		bin = convert_bin(msg[i]);
		while (bin[j])
		{
			if (bin[j] == '1')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (!g_ok)
				;
			g_ok = 0;
			j++;
		}
		i++;
		free(bin);
		bin = NULL;
	}
}

void	listen_server_sig(int sig)
{
	(void)sig;
	g_ok = 1;
}