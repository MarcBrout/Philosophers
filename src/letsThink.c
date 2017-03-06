#include <stdlib.h>
#include <pthread.h>
#include "philo.h"

static void initTable(t_loop const * const philosophers,
                      t_philo * const table)
{
    int i;

    i = 0;
    while (i < philosophers->nbPhil)
    {
        table[i].bowl = philosophers->maxEat;
        table[i].state = READY;
        pthread_mutex_init(&table[i].stick, NULL);
        ++i;
    }
}

int launchPhilosophy(t_loop const * const philosophers)
{
    t_philo *table;

    if (!(table = malloc(sizeof(*table) * philosophers->nbPhil)))
        return (1);
    initTable(philosophers, table);
    return (0);
}
