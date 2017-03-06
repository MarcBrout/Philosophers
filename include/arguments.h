#ifndef ARGUMENTS_H
# define ARGUMENTS_H

# include <stddef.h>
# include "philo.h"

typedef struct s_arg
{
    char *cmd;
    bool (*func)(const char *, t_loop *);
} t_arg;

#endif /* !ARGUMENTS_H */
