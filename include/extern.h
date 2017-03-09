/*
** extern.h for philo in /home/brout_m/rendu/system/PSU_2016_philo
**
** Made by brout_m
** Login   <marc.brout@epitech.eu>
**
** Started on  Thu Mar  9 16:41:00 2017 brout_m
** Last update Thu Mar  9 16:41:13 2017 brout_m
*/

#ifndef __LIBRICEFEREE_EXTERN__
# define __LIBRICEFEREE_EXTERN__

#include <pthread.h>

/*
 * You MUST use this library at linking and runtime
 * -lpthread might be set after this library in LDFLAGS
 * Remember to set LD_LIBRARY_PATH.
 * None of thoses functions will do your job!
 * Thoses are entry points for the Referee.
 * mutex_id parameter of lphilo_take_chopstick/lphilo_release_chopstick functions
 * is the pointer of the (const) mutex you use to handle the current chopstick.
 */

/* MUST be the first instruction in your main to Init the library */
int	RCFStartup(int ac, char **av);

/* MUST be called after use to release library ressources */
void RCFCleanup();

/* Call it when a philo is eating */
int	lphilo_eat();

/* Call it when a philo is sleeping */
int	lphilo_sleep();

/* Call it when a philo is thinking */
int	lphilo_think();

/* Call it when a philo takes a chopstick */
int	lphilo_take_chopstick(const pthread_mutex_t *mutex_id);

/* Call it when a philo releases a chopstick */
int	lphilo_release_chopstick(const pthread_mutex_t *mutex_id);

#endif /* __LIBRICEFEREE_EXTERN__ */
