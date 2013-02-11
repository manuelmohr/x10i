#ifndef POSIX_INIT_H
#define POSIX_INIT_H

void init_locks(void);
void destroy_locks(void);

void init_mutex(void);

void init_finish_state(void);
void exit_finish_state(void);

void init_ipc(void);
void shutdown_ipc(void);

extern int exit_code;

extern unsigned place_id;

#endif
