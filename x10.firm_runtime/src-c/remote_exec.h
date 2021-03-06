#ifndef REMOTE_EXEC_H
#define REMOTE_EXEC_H

#include "types.h"

enum x10_message_types {
	MSG_RUN_AT = 1,
	MSG_EVAL_AT,
	MSG_RUN_AT_ASYNC,
};

x10_object* x10_execute_at(x10_int place_id, x10_int msg_type, x10_object *closure, x10_boolean uncounted);
void x10_idle(void);

#endif
