/*
** checks.c for  in /home/brout_m/rendu/system/PSU_2016_philo
**
** Made by brout_m
** Login   <marc.brout@epitech.eu>
**
** Started on  Fri Mar 17 10:43:51 2017 brout_m
** Last update Fri Mar 17 10:50:27 2017 brout_m
*/

#include <pthread.h>
#include "philo.h"

static pthread_mutex_t bowl = PTHREAD_MUTEX_INITIALIZER;
int g_bowl;

void update_g_bowl(int value)
{
  pthread_mutex_lock(&bowl);
  if (g_bowl > value)
    g_bowl = value;
  pthread_mutex_unlock(&bowl);
}

bool	bowlIsEmpty()
{
  int	remain;

  pthread_mutex_lock(&bowl);
  remain = g_bowl;
  pthread_mutex_unlock(&bowl);
  return (remain < 1);
}

int		allAtBowl(t_philo *table, int size, int me)
{
  int		i;
  static int	first = 1;

  i = 0;
  if (!first)
    {
      pthread_mutex_lock(&bowl);
      if (table[me].bowl != g_bowl && !pthread_mutex_unlock(&bowl))
	return (1);
      while (i < size)
	{
	  if (table[i].bowl != g_bowl)
	    {
	      pthread_mutex_unlock(&bowl);
	      return (0);
	    }
	  ++i;
	}
      pthread_mutex_unlock(&bowl);
    }
  else
    first = 0;
  return (1);
}
