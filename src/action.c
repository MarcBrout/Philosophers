/*
** action.c for action in /home/duhieu_b/Concurrence/PSU_2016_philo
**
** Made by duhieu_b
** Login   <benjamin.duhieu@epitech.eu>
**
** Started on  Tue Mar  7 19:06:31 2017 duhieu_b
** Last update Thu Mar  9 17:48:03 2017 brout_m
*/

#include <stdlib.h>
#include <pthread.h>
#include <extern.h>
#include <stdio.h>
#include <unistd.h>
#include "philo.h"

pthread_mutex_t bowl = PTHREAD_MUTEX_INITIALIZER;
int g_bowl;

bool bowlIsEmpty()
{
  int remain;

  pthread_mutex_lock(&bowl);
  remain = g_bowl;
  pthread_mutex_unlock(&bowl);
  return (remain < 1);
}

void update_g_bowl(int value)
{
  pthread_mutex_lock(&bowl);
  if (g_bowl > value)
    g_bowl = value;
  pthread_mutex_unlock(&bowl);
}

void think(t_philo *phil)
{
  pthread_mutex_lock(&phil->stick);
  lphilo_take_chopstick(&phil->stick);
  lphilo_think();
  lphilo_release_chopstick(&phil->stick);
  pthread_mutex_unlock(&phil->stick);
  usleep(100);
}

void eat(t_philo *phil)
{
  while (pthread_mutex_trylock(&phil->stick));
  while (pthread_mutex_trylock(RGHT_STCK(phil)));
  lphilo_take_chopstick(&phil->stick);
  lphilo_take_chopstick(RGHT_STCK(phil));
  lphilo_eat();
  --phil->bowl;
  update_g_bowl(phil->bowl);
  lphilo_release_chopstick(RGHT_STCK(phil));
  lphilo_release_chopstick(&phil->stick);
  pthread_mutex_unlock(RGHT_STCK(phil));
  pthread_mutex_unlock(&phil->stick);
  usleep(100);
}

int philoAction(t_philo *phil)
{
  while (!bowlIsEmpty())
    {
      think(phil);
      if (bowlIsEmpty())
	break;
      eat(phil);
      if (bowlIsEmpty())
	break;
      lphilo_sleep();
    }
  pthread_exit(0);
}
