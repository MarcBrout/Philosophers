/*
** action.c for action in /home/duhieu_b/Concurrence/PSU_2016_philo
**
** Made by duhieu_b
** Login   <benjamin.duhieu@epitech.eu>
**
** Started on  Tue Mar  7 19:06:31 2017 duhieu_b
** Last update Fri Mar 17 10:51:08 2017 brout_m
*/

#include <stdlib.h>
#include <pthread.h>
#include <extern.h>
#include <unistd.h>
#include "philo.h"

static int think(t_philo *phil)
{
  pthread_mutex_lock(&phil->stick);
  lphilo_take_chopstick(&phil->stick);
  lphilo_think();
  lphilo_release_chopstick(&phil->stick);
  pthread_mutex_unlock(&phil->stick);
  usleep(rand() % 75 + 75);
  return (bowlIsEmpty());
}

static int eat(t_philo *phil)
{
  pthread_mutex_lock(RGHT_STCK(phil));
  if (pthread_mutex_trylock(&phil->stick) &&
      !pthread_mutex_unlock(RGHT_STCK(phil)))
    return (1);
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

int philoAction(t_philo *phil)
{
  bool thk;

  thk = false;
  while (!bowlIsEmpty())
    {
      usleep(rand() % 10 + 10);
      if (!allAtBowl(phil->table, phil->size, phil->me))
	continue;
      if (bowlIsEmpty() || (!thk && think(phil)))
	break;
      if (eat(phil) && (thk = true))
	continue;
      else
	thk = false;
      lphilo_sleep();
    }
  pthread_exit(0);
}
