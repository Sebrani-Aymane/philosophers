#include "philo.h"

int init_data(t_data *data, int argc, char **argv)
{
    int i;

    i = 0;
    if (argc < 5 || argc > 6)
        return (1);
    data->num_philosophers = atoi(argv[1]);
    data->time_to_die = atol(argv[2]);
    data->time_to_eat = atol(argv[3]);
    data->time_to_sleep = atol(argv[4]);
    data->meals_required = (argc == 6) ? atoi(argv[5]) : -1;
    data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
    data->philosophers = malloc(sizeof(t_philo) * data->num_philosophers);
    if (!data->forks || !data->philosophers)
        return (1);
    while (i < data->num_philosophers)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&data->print_lock, NULL);
    data->start_time = current_time();
    i = 0;
    while (i < data->num_philosophers)
    {
        data->philosophers[i].id = i + 1;
        data->philosophers[i].left_fork = &data->forks[i];
        data->philosophers[i].right_fork = &data->forks[(i + 1) % data->num_philosophers];
        data->philosophers[i].last_meal = data->start_time;
        data->philosophers[i].meals_eaten = 0;
        data->philosophers[i].data = data;
        i++;
    }
    return (0);
}

void cleanup(t_data *data)
{
    int i;

    i = 0;
    while ( i < data->num_philosophers)
        pthread_mutex_destroy(&data->forks[i++]);
    pthread_mutex_destroy(&data->print_lock);
    free(data->forks);
    free(data->philosophers);
}

int main(int argc, char **argv)
{
    int i;
    t_data data;

    i = 0;
    if (init_data(&data, argc, argv) != 0)
    {
        printf("Error: Invalid arguments\n");
        return (1);
    }
    while ( i < data.num_philosophers)
    {
        pthread_create(&data.philosophers[i].thread, NULL, philosopher_routine, &data.philosophers[i]);
        i++;
    }
    i = 0;
    while(i < data.num_philosophers)
    {
        pthread_join(data.philosophers[i].thread, NULL);
        i++;
    }
    cleanup(&data);
    return (0);
}
