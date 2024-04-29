/*******************************************************************************
Copyright (c) 2012, Jonathan Hiller (Cornell University)
If used in publication cite "J. Hiller and H. Lipson "Dynamic Simulation of Soft Heterogeneous Objects" In press. (2011)"


This file is part of Voxelyze.
Voxelyze is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
Voxelyze is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
See <http://www.opensource.org/licenses/lgpl-3.0.html> for license details.

Changed at 2024, Hongye Zhang(ZJU)
*******************************************************************************/

#ifndef CLIENT_H

#define CLIENT_H
#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<sys/fcntl.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<errno.h>
#include<sys/types.h>
#include <arpa/inet.h>

#define SERVER_ADDRESS "192.168.129.1"
#define SERVER_PORT 20000
#define LENGTH 1024
#define SEGMENTN 5
#define SECTIONN 3
class Client
{
public:
    Client(void);
    ~Client();
    int send_buffer(void);
    void recv_block(void);
    void command_process(double * command);
    void SendBuf_process(double * ddata);
    void Bind(void);
    char* tempbuf;
    int clientfd;
    char recvBuf[LENGTH];
    std::string SendBuf;
    struct sockaddr_in serveraddr;
};







#endif