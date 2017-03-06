#ifndef PHILO_H
# define PHILO_H

#include <stdbool.h>

enum STATE
{
    THINK = 0,
    EAT,
    REST,
    READY
};

typedef struct s_philo
{
    int bowl;
    pthread_mutex_t stick;
    int state;
} t_philo;

typedef struct s_loop
{
    int nbPhil;
    int maxEat;
} t_loop;

int launchPhilosophy(t_loop const * const philosophers);

#endif /* !PHILO_H */
