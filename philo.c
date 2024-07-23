#include "philo.h"

void print_status(t_philo *philo, const char *status)
{
    long timestamp = current_time() - philo->data->start_time;
    pthread_mutex_lock(&philo->data->print_lock);
    printf("%ld %d %s\n", timestamp, philo->id, status);
    pthread_mutex_unlock(&philo->data->print_lock);
}

void eat(t_philo *philo)
{
    pthread_mutex_lock(philo->left_fork);
    print_status(philo, "has taken a fork");
    pthread_mutex_lock(philo->right_fork);
    print_status(philo, "has taken a fork");
    print_status(philo, "is eating");
    philo->last_meal = current_time();
    usleep_ms(philo->data->time_to_eat);
    philo->meals_eaten++;
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
}

void *philosopher_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    while (1)
    {
        print_status(philo, "is thinking");
        eat(philo);
        print_status(philo, "is sleeping");
        usleep_ms(philo->data->time_to_sleep);
    }
    return NULL;
}
