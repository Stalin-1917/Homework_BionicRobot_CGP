
#include "Client.h"
//

Client::Client(void)
{
    
}
Client::~Client(void)
{

}
void Client::Bind(void)
{
    
    clientfd = socket(AF_INET, SOCK_STREAM, 0);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
    serveraddr.sin_port = htons(SERVER_PORT);
    while (connect(clientfd, (struct sockaddr *)& serveraddr, sizeof(serveraddr) ) == -1) 
    {
        std::cout << "connect socket error" << std::endl;
    }
}
int Client::send_buffer(void)
{
    return send(clientfd, SendBuf.data(),strlen(SendBuf.data()),0);
}
void Client::recv_block(void)
{
    recv(clientfd, recvBuf,1024, 0);
    std::cout<<recvBuf <<std::endl;
}
void Client::command_process(double * command)
{
    char* pEnd;
    for (int i = 0;i < SEGMENTN;i++ )
    {
        command[i] = strtof64(recvBuf,&pEnd);
    }
}
void Client::SendBuf_process(double * ddata)
{
    SendBuf  = std::to_string(ddata[0]);
    for (int i = 1;i < SECTIONN;i++ )
    {
        SendBuf += " " + std::to_string(ddata[i]);
    }
}