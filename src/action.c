/*
** action.c for action in /home/duhieu_b/Concurrence/PSU_2016_philo
**
** Made by duhieu_b
** Login   <benjamin.duhieu@epitech.eu>
**
** Started on  Tue Mar  7 19:06:31 2017 duhieu_b
** Last update Thu Mar  9 15:06:35 2017 duhieu_b
*/

#include <stdlib.h>
#include <pthread.h>
#include <extern.h>
#include <stdio.h>
#include "philo.h"

/* int	sleepReady(t_philo *phil) */
/* { */
/*   if (phil->state == READY && */
/*           (phil->table[PHILO_LEFT(phil->me, phil->size)].state == THINK || */
/*                   (phil->table[PHILO_LEFT(phil->me, phil->size)].state == SLEEP && */
/*                    phil->table[PHILO_RIGHT(phil->me, phil->size)].state == THINK))) */
/*   { */
/*       printf("SLEEP1\n"); */
/*       lphilo_sleep(); */
/*       phil->state = SLEEP; */
/*       phil->processed = true; */
/*       return (1); */
/*   } */
/*       return (0); */
/* } */

/* int thinkReady(t_philo *phil) */
/* { */
/*     if (phil->state == READY) */
/*     { */
/*         printf("THINK1\n"); */
/*         lphilo_think(); */
/*         pthread_mutex_lock(&phil->stick); */
/*         lphilo_take_chopstick(&phil->stick); */
/*         pthread_mutex_unlock(&phil->stick); */
/*         phil->state = THINK; */
/*         phil->processed = true; */
/*         return (1); */
/*     } */
/*     return (0); */
/* } */

/* int eat(t_philo *phil) */
/* { */
/*     if (phil->state == THINK) */
/*     { */
/*         pthread_mutex_lock(&phil->stick); */
/*         lphilo_release_chopstick(&phil->stick); */
/*         pthread_mutex_unlock(&phil->stick); */
/*         lphilo_eat(); */
/*         pthread_mutex_lock(&phil->stick); */
/*         lphilo_take_chopstick(&phil->stick); */
/*         pthread_mutex_unlock(&phil->stick); */
/*         pthread_mutex_lock(&phil->table[PHILO_RIGHT(phil->me, phil->size)].stick); */
/*         lphilo_take_chopstick(&phil->table[PHILO_RIGHT(phil->me, phil->size)].stick); */
/*         pthread_mutex_unlock(&phil->table[PHILO_RIGHT(phil->me, phil->size)].stick); */
/*         phil->processed = true; */
/*         phil->bowl -= 1; */
/*         phil->state = EAT; */
/*         return (1); */
/*     } */
/*     return (0); */
/* } */

/* int sleepAfterEat(t_philo *phil) */
/* { */
/*     if (phil->state == EAT) */
/*     { */
/*         printf("SLEEP2\n"); */
/*         pthread_mutex_lock(&phil->stick); */
/*         lphilo_release_chopstick(&phil->stick); */
/*         pthread_mutex_unlock(&phil->stick); */
/*         pthread_mutex_lock(&phil->table[PHILO_RIGHT(phil->me, phil->size)].stick); */
/*         lphilo_release_chopstick(&phil->table[PHILO_RIGHT(phil->me, phil->size)].stick); */
/*         pthread_mutex_unlock(&phil->table[PHILO_RIGHT(phil->me, phil->size)].stick); */
/*         lphilo_sleep(); */
/*         phil->processed = true; */
/*         phil->state = SLEEP; */
/*         return (1); */
/*     } */
/*     return (0); */
/* } */

/* int thinkAfterRest(t_philo *phil) */
/* { */
/*     if (phil->state == SLEEP && ((phil->table[PHILO_LEFT(phil->me, phil->size)].state == EAT && */
/*             phil->table[PHILO_LEFT(phil->me, phil->size)].processed == false) || */
/*                                 phil->table[PHILO_LEFT(phil->me, phil->size)].state == SLEEP || */
/*                                 phil->size == 1)) */
/*     { */
/*         printf("COUNT\n"); */
/*         lphilo_think(); */
/*         pthread_mutex_lock(&phil->stick); */
/*         lphilo_take_chopstick(&phil->stick); */
/*         pthread_mutex_unlock(&phil->stick); */
/*         phil->processed = true; */
/*         phil->state = THINK; */
/*         return (1); */
/*     } */
/*     return (0); */
/* } */

/* int justSleep(t_philo *phil) */
/* { */
/*     printf("SLEEP3\n"); */
/*     lphilo_sleep(); */
/*     phil->processed = true; */
/*     phil->state = SLEEP; */
/*     return (0); */
/* } */

/* Fcptr *initTab() */
/* { */
/*   Fcptr *tab; */

/*   if (!(tab = malloc(sizeof(Fcptr) * 7))) */
/*     return (NULL); */
/*   tab[0] = sleepReady; */
/*   tab[1] = thinkReady; */
/*   tab[2] = eat; */
/*   tab[3] = sleepAfterEat; */
/*   tab[4] = thinkAfterRest; */
/*   tab[5] = justSleep; */
/*   tab[6] = NULL; */
/*   return (tab); */
/* } */

int checkOtherBowl(t_philo *phil)
{
    int i;

    i = 0;
    while (i < phil->size)
    {
        if (phil->table[i].bowl < 1)
            return (0);
        i++;
    }
    return (1);
}

int	philoAction(t_philo *phil)
{
  Fcptr *tab;
  int	i;

  //  if (!(tab = initTab()))
  //  return (1);
  i = 0;
  while (checkOtherBowl(phil))
    {

    }
  return (0);
}
