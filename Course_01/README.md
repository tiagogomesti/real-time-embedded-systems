# Linux Semaphores Functions
## sem_open
```shell
NAME
       sem_open - initialize and open a named semaphore

SYNOPSIS
       #include <fcntl.h>           /* For O_* constants */
       #include <sys/stat.h>        /* For mode constants */
       #include <semaphore.h>

       sem_t *sem_open(const char *name, int oflag);
       sem_t *sem_open(const char *name, int oflag,
                       mode_t mode, unsigned int value);

       Link with -pthread.
DESCRIPTION
       sem_open() creates a new POSIX semaphore or opens an existing semaphore.  The semaphore is identified by name.  For details of the construction of name, see sem_overview(7).

       The oflag argument specifies flags that control the operation of the call.  (Definitions of the flags values can be obtained by including <fcntl.h>.)  If O_CREAT is specified in oflag, then the
       semaphore is created if it does not already exist.  The owner (user ID) of the semaphore is set to the effective user ID of the calling process.  The group ownership (group ID) is  set  to  the
       effective group ID of the calling process.  If both O_CREAT and O_EXCL are specified in oflag, then an error is returned if a semaphore with the given name already exists.

       If O_CREAT is specified in oflag, then two additional arguments must be supplied.  The mode argument specifies the permissions to be placed on the new semaphore, as for open(2).  (Symbolic def‐
       initions for the permissions bits can be obtained by including <sys/stat.h>.)  The permissions settings are masked against the process umask.  Both read and write permission should  be  granted
       to  each  class  of user that will access the semaphore.  The value argument specifies the initial value for the new semaphore.  If O_CREAT is specified, and a semaphore with the given name al‐
       ready exists, then mode and value are ignored.

RETURN VALUE
       On success, sem_open() returns the address of the new semaphore; this address is used when calling other semaphore-related functions.  On error, sem_open() returns SEM_FAILED, with errno set to
       indicate the error.

``` 

## sem_wait
```Shell
NAME
       sem_wait, sem_timedwait, sem_trywait - lock a semaphore

SYNOPSIS
       #include <semaphore.h>

       int sem_wait(sem_t *sem);

       int sem_trywait(sem_t *sem);

       int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout);

       Link with -pthread.

   Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

       sem_timedwait(): _POSIX_C_SOURCE >= 200112L
DESCRIPTION
       sem_wait()  decrements (locks) the semaphore pointed to by sem.  If the semaphore's value is greater than zero, then the decrement proceeds, and the function returns, immediately.  If the sema‐
       phore currently has the value zero, then the call blocks until either it becomes possible to perform the decrement (i.e., the semaphore value rises above zero), or a signal  handler  interrupts
       the call.

       sem_trywait() is the same as sem_wait(), except that if the decrement cannot be immediately performed, then call returns an error (errno set to EAGAIN) instead of blocking.

       sem_timedwait()  is  the  same  as  sem_wait(), except that abs_timeout specifies a limit on the amount of time that the call should block if the decrement cannot be immediately performed.  The
       abs_timeout argument points to a structure that specifies an absolute timeout in seconds and nanoseconds since the Epoch, 1970-01-01 00:00:00 +0000 (UTC).  This structure is defined as follows:

           struct timespec {
               time_t tv_sec;      /* Seconds */
               long   tv_nsec;     /* Nanoseconds [0 .. 999999999] */
           };

       If the timeout has already expired by the time of the call, and the semaphore could not be locked immediately, then sem_timedwait() fails with a timeout error (errno set to ETIMEDOUT).

       If the operation can be performed immediately, then sem_timedwait() never fails with a timeout error, regardless of the value of abs_timeout.  Furthermore, the validity of  abs_timeout  is  not
       checked in this case.
```

## sem_post
```
NAME
       sem_post - unlock a semaphore

SYNOPSIS
       #include <semaphore.h>

       int sem_post(sem_t *sem);

       Link with -pthread.

DESCRIPTION
       sem_post()  increments  (unlocks) the semaphore pointed to by sem.  If the semaphore's value consequently becomes greater than zero, then another process or thread blocked in a sem_wait(3) call
       will be woken up and proceed to lock the semaphore.

```

## sem_close
```
NAME
       sem_close - close a named semaphore

SYNOPSIS
       #include <semaphore.h>

       int sem_close(sem_t *sem);

       Link with -pthread.

DESCRIPTION
       sem_close() closes the named semaphore referred to by sem, allowing any resources that the system has allocated to the calling process for this semaphore to be freed.

```

## sem_unlink
```
NAME
       sem_unlink - remove a named semaphore

SYNOPSIS
       #include <semaphore.h>

       int sem_unlink(const char *name);

       Link with -pthread.

DESCRIPTION
       sem_unlink() removes the named semaphore referred to by name.  The semaphore name is removed immediately.  The semaphore is destroyed once all other processes that have the semaphore open close
       it.

```