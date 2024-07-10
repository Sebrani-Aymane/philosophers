#include "philosophers.h"
int is_digit(char *input)
{
    int i = 0;
    while (input[i])
    {
        if (input[i] >= '0' && input[i] <= '9')
            i++;
        else 
            return(0);
    }
    return (1);
}

long	ft_atol(char *str)
{
	long	num;
	int		i;

	num = 0;
	i = 0;

	while (*str >= '0' && *str <= '9')
	{
        if !((*str >= '0' && *str <= '9'))
            return(-1);
		num = (num * 10) + (str[i] - '0');
		if (num > 2147483647)
			return (2147483648);
		str++;
	}
	return (num);
}
void threadmaker(int philo_nbr)
{
    pthrebb

}
int parse_arg(int ac,char **av)
{
    int i = 1;
    long philo_nbr;
    long dienow;
    long eatnow;
    long sleepnow;

    while(ac-- >=1)
    {
        if (!is_digit(av[i++]))
            return(printf("parse error\n"),0);
    }
    philo_nbr = ft_atol(av[1]);
    dienow = ft_atol(av[2]);
    eatnow = ft_atol(av[3]);
    sleepnow = ft_atol(av[4]);
}