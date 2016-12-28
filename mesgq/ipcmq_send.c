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
    if (argc!=2)
    {
        printf("usage: ./ipcmq_send <message>\n");
        exit(0);
    }
    
    //mqID = mq_open(MY_MQ_NAME, O_WRONLY);
    mqID = mq_open(MY_MQ_NAME, O_RDWR|O_CREAT|O_EXCL, 0666, NULL);
    if (mqID < 0)
    {
        printf("open message queue %s error[%s]\n", MY_MQ_NAME, strerror(errno));
        //return -1;
    
        mqID = mq_open(MY_MQ_NAME, O_WRONLY);
        if (mqID < 0){
          printf("open message queue %s error[%s]\n", MY_MQ_NAME, strerror(errno));
          return -1;
        }
        printf("open message queue succ, mqID = %d\n", mqID);
        
    }else{
        printf("open message queue succ, mqID = %d\n", mqID);
    
        if (mq_getattr(mqID, &mqAttr) < 0){
          printf("get the message queue attribute error\n");
          return -1;
        }
    }

    iprio = 1;
    
    mq_send(mqID, argv[1], strlen(argv[1]), iprio);
    return 0;
}
