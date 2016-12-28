# mesgq
A message queue could pass the motor info. by process  
$ make  
$ ./ipcmq_send_exe "{ \"motor\": \"1\", \"action\": \"run\", \"mode\": \"0\", \"position\": \"1000\", \"speed\": \"100\", \"acc\": \"100\" }  
$ ./ipcmq_recv_exe  
 
