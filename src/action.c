/*
** action.c for action in /home/duhieu_b/Concurrence/PSU_2016_philo
**
** Made by duhieu_b
** Login   <benjamin.duhieu@epitech.eu>
**
** Started on  Tue Mar  7 19:06:31 2017 duhieu_b
** Last update Fri Mar 17 10:20:38 2017 brout_m
*/

#include <stdlib.h>
#include <pthread.h>
#include <extern.h>
#include <unistd.h>
#include "philo.h"

static pthread_mutex_t bowl = PTHREAD_MUTEX_INITIALIZER;
int g_bowl;

static bool bowlIsEmpty()
{
  int remain;

  pthread_mutex_lock(&bowl);
  remain = g_bowl;
  pthread_mutex_unlock(&bowl);
  return (remain < 1);
}

static void update_g_bowl(int value)
{
  pthread_mutex_lock(&bowl);
  if (g_bowl > value)
    g_bowl = value;
  pthread_mutex_unlock(&bowl);
}

static void think(t_philo *phil)
{
  pthread_mutex_lock(&phil->stick);
  lphilo_take_chopstick(&phil->stick);
  lphilo_think();
  lphilo_release_chopstick(&phil->stick);
  pthread_mutex_unlock(&phil->stick);
  usleep(rand() % 75 + 75);
}

static int eat(t_philo *phil)
{
  pthread_mutex_lock(RGHT_STCK(phil));
  if (pthread_mutex_trylock(&phil->stick))
    {
      pthread_mutex_unlock(RGHT_STCK(phil));
      return (1);
    }
  lphilo_take_chopstick(&phil->stick);
  lphilo_take_chopstick(RGHT_STCK(phil));
  lphilo_eat();
  --phil->bowl;
  update_g_bowl(phil->bowl);
  lphilo_release_chopstick(RGHT_STCK(phil));
  lphilo_release_chopstick(&phil->stick);
  pthread_mutex_unlock(RGHT_STCK(phil));
  pthread_mutex_unlock(&phil->stick);
  usleep(rand() % 75 + 75);
  return (0);
}

int allAtBowl(t_philo *table, int size, int me)
{
  int i;
  static int first = 1;

  i = 0;
  if (!first)
    {
      pthread_mutex_lock(&bowl);
      if (table[me].bowl != g_bowl)
	{
	  pthread_mutex_unlock(&bowl);
	  return (1);
	}
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

int philoAction(t_philo *phil)
{
  bool thk;

  thk = false;
  while (!bowlIsEmpty())
    {
      usleep(rand() % 10 + 10);
      if (!allAtBowl(phil->table, phil->size, phil->me))
	continue ;
      if (bowlIsEmpty())
	break;
      if (!thk)
	think(phil);
      if (bowlIsEmpty())
	break;
      if (eat(phil))
	{
	  thk = true;
	  continue;
	}
      else
	thk = false;
      if (bowlIsEmpty())
	break;
      lphilo_sleep();
    }
  pthread_exit(0);
}
