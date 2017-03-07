#ifndef PHILO_H
# define PHILO_H
# define PHILO_LEFT(i, size) ((i) == 0) ? (size) - 1 : (i) - 1
# define PHILO_RIGHT(i, size) ((i) == (size) - 1) ? 0 : (i) + 1

#include <stdbool.h>

enum STATE
{
    READY = 0,
    THINK,
    EAT,
    SLEEP
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

typedef int (*Fcptr)(t_philo *);

int launchPhilosophy(t_loop const * const philosophers);

int philoAction(t_philo *phil);

#endif /* !PHILO_H */
