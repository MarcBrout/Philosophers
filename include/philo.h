#ifndef PHILO_H
# define PHILO_H

#include <stdbool.h>

enum STATE
{
    READY = 0,
    THINK,
    EAT,
    REST
};

typedef struct s_philo
{
    int bowl;
    int me;
    int state;
    struct s_philo *table;
    pthread_t thread;
    pthread_mutex_t stick;
    int size;
    bool processed;
} t_philo;

typedef struct s_loop
{
    int nbPhil;
    int maxEat;
} t_loop;

int launchPhilosophy(t_loop const * const philosophers);

#endif /* !PHILO_H */
