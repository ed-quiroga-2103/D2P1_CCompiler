//
// Created by eduardo on 02/04/18.
//

#include <iostream>
#include "mserver_client.h"
#include "string"

mserver_client::mserver_client(int port) {

    this->port = port;

}

short mserver_client::SocketCreate()  {

    short hSocket;
    printf("Create the socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

int mserver_client::SocketConnect(int hSocket) {

    int iRetval=-1;
    int ServerPort = port;
    struct sockaddr_in remote={0};

    remote.sin_addr.s_addr = inet_addr("127.0.0.1"); //Local Host
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);

    iRetval = connect(hSocket , (struct sockaddr *)&remote , sizeof(struct sockaddr_in));


    return iRetval;
}

int mserver_client::SocketSend(int hSocket, char *Rqst, short lenRqst) {

    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;  /* 20 Secs Timeout */
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv,sizeof(tv)) < 0)
    {
        printf("Time Out\n");
        return -1;
    }
    shortRetval = send(hSocket , Rqst , lenRqst , 0);

    return shortRetval;
}

int mserver_client::SocketReceive(int hSocket, char *Rsp, short RvcSize) {

    int shortRetval = -1;
    struct timeval tv;
    tv.tv_sec = 20;  /* 20 Secs Timeout */
    tv.tv_usec = 0;

    if(setsockopt(hSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,sizeof(tv)) < 0)
    {
        printf("Time Out\n");
        return -1;

    }
    shortRetval = recv(hSocket, Rsp , RvcSize , 0);


    return shortRetval;
}

int mserver_client::sendJson(string msg) {

    int hSocket, read_size;
    struct sockaddr_in server;
    int n = msg.length();
    char SendToServer[n+1] = {0};
    char server_reply[200] = {0};

    //Create socket
    hSocket = SocketCreate();
    if(hSocket == -1)
    {
        printf("Could not create socket\n");
        return 1;
    }

    printf("Socket is created\n");

    //Connect to remote server
    if (SocketConnect(hSocket) < 0)
    {
        perror("connect failed.\n");
        return 1;
    }

    printf("Sucessfully conected with server\n");


    strcpy(SendToServer, msg.c_str());

    //Send data to the server
    SocketSend(hSocket, SendToServer, strlen(SendToServer));


    //Received the data from the server
    read_size = SocketReceive(hSocket, server_reply, 200);

    data = server_reply;

    close(hSocket);
    shutdown(hSocket,0);
    shutdown(hSocket,1);
    shutdown(hSocket,2);

}
