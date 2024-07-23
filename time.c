#include "philo.h"

long current_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void usleep_ms(long ms)
{
    usleep(ms * 1000);
}
