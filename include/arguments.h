/*
** arguments.h for philo in /home/brout_m/rendu/system/PSU_2016_philo
**
** Made by brout_m
** Login   <marc.brout@epitech.eu>
**
** Started on  Thu Mar  9 16:40:52 2017 brout_m
** Last update Thu Mar  9 16:41:32 2017 brout_m
*/

#ifndef ARGUMENTS_H
# define ARGUMENTS_H

# include <stddef.h>
# include "philo.h"

typedef struct	s_arg
{
    char	*cmd;
    bool	(*func)(const char *, t_loop *);
}		t_arg;

#endif /* !ARGUMENTS_H */
