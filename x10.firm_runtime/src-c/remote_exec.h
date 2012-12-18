#ifndef REMOTE_EXEC_H
#define REMOTE_EXEC_H

#include "x10.h"

enum x10_rt_message_types {
	MSG_RUN_AT = 1,
	MSG_EVAL_AT,
};

typedef void (*place_execute_func)(void *);

x10_int     x10_rt_get_here_id();
void        x10_rt_set_here_id(x10_int id);

x10_object* x10_rt_execute_at(x10_int place_id, x10_int msg_type, x10_object *closure);

void        x10_rt_place_execute(void *arg);
void        x10_rt_dma(void *dest, const void *src, size_t len);
void        x10_rt_spawn(x10_int place_id, void *arg, size_t arg_len);

#endif
