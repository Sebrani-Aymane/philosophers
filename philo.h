#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_philo
{
    int id;
    pthread_t thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    long last_meal;
    int meals_eaten;
    struct s_data *data;
} t_philo;

typedef struct s_data
{
    int num_philosophers;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    int meals_required;
    pthread_mutex_t *forks;
    pthread_mutex_t print_lock;
    long start_time;
    t_philo *philosophers;
} t_data;

// Function prototypes
long current_time(void);
void usleep_ms(long ms);
void *philosopher_routine(void *arg);
int init_data(t_data *data, int argc, char **argv);
void cleanup(t_data *data);

#endif
