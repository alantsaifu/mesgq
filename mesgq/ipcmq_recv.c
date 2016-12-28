#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <string.h>

#define MY_MQ_NAME "/mqldcl"

int main(int argc, char** argv)
{
    mqd_t mqID;
    struct mq_attr mqAttr;
    unsigned int iprio;
    unsigned int n;
    char buff[8192];
    
    if (argc>1)
    {
        printf("usage: ./ipc_posix_mq_recv\n");
        exit(0);
    }
    
    mqID = mq_open(MY_MQ_NAME, O_RDONLY);
    if (mqID < 0)
    {
        printf("open message queue %s error[%s]\n", MY_MQ_NAME, strerror(errno));
        return -1;
    }
    mq_getattr(mqID, &mqAttr);
    n = mq_receive(mqID, buff, mqAttr.mq_msgsize, &iprio);
    printf("read from mq`s msg = %s\n", buff);
    return 0;
}
