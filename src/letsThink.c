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
        table[i].me = i;
        table[i].size = philosophers->nbPhil;
        table[i].table = table;
        table[i].processed = false;
        pthread_mutex_init(&table[i].stick, NULL);
        ++i;
    }
}

void *threadLaunch(void *philosophe)
{
    t_philo *philo;
    int i;

    philo = philosophe;
    pthread_mutex_lock(&philo->stick);
    if (philo->me == philo->size - 1)
    {
        i = 0;
        while (i < philo->size)
        {
            pthread_mutex_unlock(&philo->table[i].stick);
            ++i;
        }
    }
    if (philoAction(&philo->table[philo->me]))
        return (NULL);
    return (NULL);
}

int launchPhilosophy(t_loop const * const philosophers)
{
    t_philo *table;
    int i;

    if (!(table = malloc(sizeof(*table) * philosophers->nbPhil)))
        return (1);
    initTable(philosophers, table);
    i = 0;
    while (i < philosophers->nbPhil)
    {
        pthread_create(&table[i].thread, NULL, threadLaunch, &table[i]);
        ++i;
    }
    i = 0;
    while (i < philosophers->nbPhil)
    {
        pthread_join(table[i].thread, NULL);
        ++i;
    }
    return (0);
}
