#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <sys/utsname.h>
#include <syslog.h>

#define SYSLOG_PREFACE "[COURSE:1][ASSIGNMENT:1]"
#define UNUSED(X) (void)(X)
#define UNAME_STR_SIZE (65 * 5)

static void *thread_func(void *arg)
{
    UNUSED(arg);

    syslog(LOG_USER, "%s Hello World from Thread!", SYSLOG_PREFACE);
    return NULL;
}

int main(int argc, char *argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    char uname_str[UNAME_STR_SIZE];
    struct utsname uname_buf;

    if (uname(&uname_buf) != -1)
    {
        sprintf(uname_str, "%s %s %s %s %s", uname_buf.sysname, uname_buf.nodename, uname_buf.release,
                uname_buf.version, uname_buf.machine);
    }

    syslog(LOG_USER, "%s %s", SYSLOG_PREFACE, uname_str);
    syslog(LOG_USER, "%s Hello World from Main!", SYSLOG_PREFACE);

    pthread_t threads;
    pthread_create(&threads, NULL, thread_func, NULL);
    pthread_join(threads, NULL);
}
