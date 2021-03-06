#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 
#include "std_lib_facilities.h";
#include <sys/wait.h>


int main(int argc, char *argv[])
{
    int i = 0;
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr; 
    
    int sockfd = 0, n = 0, rc;
    char recvBuff[1024];
    char opt = 1 | SO_REUSEADDR | SO_REUSEPORT;

    char sendBuff[1025];
    time_t ticks; 

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //htonl(INADDR_ANY);
    serv_addr.sin_port = htons(5000); 
    
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEPORT, (char *)&opt, sizeof opt);

    rc = bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 
		if (rc<0) {
			cout<<"The bind is failed!";
		}
		cout << "bind:"<< rc << endl;
    listen(listenfd, 10); 
		if (rc<0) {
			cout<<"The listen is failed!";
		}
		cout << "listen:"<< rc << "" << listenfd<< endl;

    while(1)
    {
        connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 
        int childpid = fork();
        if (childpid==0) {
        	break;
        	}
        wait(NULL);	
      }  	
        i=0;
    if ( fork()!=0) exit(0);
    while (i++<10) {
        cout<<connfd<<endl;
				while (true) {
					cout<<"Loading..."<<endl;
					n = recv(connfd, recvBuff, sizeof(recvBuff)-1, 0);
					recvBuff[n] = 0;
					cout<<recvBuff<<"is recvbuff"<<endl;
					if (strcmp(recvBuff, "hello world") == 0) {
						break;
					}
					break;
				}
        ticks = time(NULL);
        printf("hi\n");
        sleep(5);
        snprintf(sendBuff, sizeof(sendBuff), "william says %.24s\r\n", ctime(&ticks));
        while (1) {
        	snprintf(sendBuff, sizeof(sendBuff), "william %d says %.24s\r\n", i, ctime(&ticks));
        	send(connfd, sendBuff, strlen(sendBuff),0); 
        	cout << sendBuff << endl;
        	break;
				}
			}
        close(connfd);
 
}
