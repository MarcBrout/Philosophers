/*
** letsThink.c for philo in /home/brout_m/rendu/system/PSU_2016_philo
**
** Made by brout_m
** Login   <marc.brout@epitech.eu>
**
** Started on  Thu Mar  9 16:43:39 2017 brout_m
** Last update Thu Mar  9 16:44:36 2017 brout_m
*/

#include <stdlib.h>
#include <pthread.h>
#include "philo.h"

int g_bowl;

static void	initTable(t_loop const * const philosophers,
			  t_philo * const table)
{
  int		i;

  i = 0;
  g_bowl = philosophers->maxEat;
  while (i < philosophers->nbPhil)
    {
      table[i].bowl = philosophers->maxEat;
      table[i].me = i;
      table[i].size = philosophers->nbPhil;
      table[i].table = table;
      pthread_mutex_init(&table[i].stick, NULL);
      ++i;
    }
}

void		*threadLaunch(void *philosophe)
{
  t_philo	*philo;
  int		i;

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
  philoAction(&philo->table[philo->me]);
  return (NULL);
}

int		launchPhilosophy(t_loop const * const philosophers)
{
  t_philo	*table;
  int		i;

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
