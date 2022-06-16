#include "../minitalk.h"

int	ft_bin_to_uc(char *str)
{
	int	res;

	res = 0;
	if (str[0] == '1')
		res += 128;
	if (str[1] == '1')
		res += 64;
	if (str[2] == '1')
		res += 32;
	if (str[3] == '1')
		res += 16;
	if (str[4] == '1')
		res += 8;
	if (str[5] == '1')
		res += 4;
	if (str[6] == '1')
		res += 2;
	if (str[7] == '1')
		res += 1;
	return (res);
}

void f_sig(int sig, siginfo_t *meta, void *context)
{
	// char					c;
	static char	*str;

	(void)context;
	if (sig == SIGUSR1)
	{
		str = ft_strjoin(str, "1");
	}
	else if (sig == SIGUSR2)
	{
		str = ft_strjoin(str, "0");
	}
	if (ft_strlen(str) == 8)
	{
		if (ft_bin_to_uc(str) == '\0')
			ft_putchar('\n');
		else
			ft_putchar(ft_bin_to_uc(str));
		free(str);
		str = NULL;
	}
	kill(meta->si_pid, SIGUSR1);
}