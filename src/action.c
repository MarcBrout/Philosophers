/*
** action.c for action in /home/duhieu_b/Concurrence/PSU_2016_philo
**
** Made by duhieu_b
** Login   <benjamin.duhieu@epitech.eu>
**
** Started on  Tue Mar  7 19:06:31 2017 duhieu_b
** Last update Wed Mar 15 18:06:53 2017 brout_m
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
  return (0);
}

int philoAction(t_philo *phil)
{
  bool thk;

  thk = false;
  while (!bowlIsEmpty())
    {
      if (!thk)
	think(phil);
      if (eat(phil))
	{
	  thk = true;
	  continue;
	}
      else
	thk = false;
      lphilo_sleep();
      usleep(rand() % 100 + 50);
    }
  pthread_exit(0);
}
