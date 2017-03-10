/*
** letsThink.c for philo in /home/brout_m/rendu/system/PSU_2016_philo
**
** Made by brout_m
** Login   <marc.brout@epitech.eu>
**
** Started on  Thu Mar  9 16:43:39 2017 brout_m
** Last update Fri Mar 10 17:01:01 2017 brout_m
*/

#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include "philo.h"

int g_bowl;
static pthread_barrier_t barrier;

static int	initTable(t_loop const * const philosophers,
			  t_philo * const table)
{
  int		i;

  i = 0;
  g_bowl = philosophers->maxEat;
  if (pthread_barrier_init(&barrier, NULL, philosophers->nbPhil))
    return (1);
  while (i < philosophers->nbPhil)
    {
      table[i].bowl = philosophers->maxEat;
      table[i].me = i;
      table[i].size = philosophers->nbPhil;
      table[i].table = table;
      if (pthread_mutex_init(&table[i].stick, NULL))
	return (1);
      ++i;
    }
  return (0);
}

static void	*threadLaunch(void *philosophe)
{
  t_philo	*philo;

  philo = philosophe;
  pthread_barrier_wait(&barrier);
  philoAction(&philo->table[philo->me]);
  return (NULL);
}

t_philo		*createTable(t_loop const * const philosophers)
{
  t_philo	*table;

  if (!(table = malloc(sizeof(*table) * philosophers->nbPhil)))
    return (NULL);
  if (initTable(philosophers, table))
    {
      free(table);
      return (NULL);
    }
  return (table);
}

int		launchPhilosophy(t_loop const * const philosophers, t_philo *table)
{
  int		i;

  i = 0;
  srand(time(0));
  while (i < philosophers->nbPhil)
    {
      if (pthread_create(&table[i].thread, NULL, threadLaunch, &table[i]))
	return (1);
      ++i;
    }
  i = 0;
  while (i < philosophers->nbPhil)
    {
      pthread_join(table[i].thread, NULL);
      pthread_mutex_destroy(&table[i].stick);
      ++i;
    }
  pthread_barrier_destroy(&barrier);
  return (0);
}
