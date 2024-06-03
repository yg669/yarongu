//
// TCPIP_Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <algorithm>
#include <memory>
#include <string>
#include <stdexcept>
#include <vector>
#include<stdio.h> 

#pragma comment(lib, "Ws2_32.lib")

//int OpenConnection(const char* hostname, int port)
//{
//    int sd=0, err=0;
//    struct addrinfo hints = {}, * addrs;
//    char port_str[16] = {};
//
//    hints.ai_family = AF_INET;
//    hints.ai_socktype = SOCK_STREAM;
//    hints.ai_protocol = IPPROTO_TCP;
//
//    sprintf(port_str, "%d", port);
//
//    err = getaddrinfo(hostname, port_str, &hints, &addrs);
//    if (err != 0)
//    {
//        fprintf(stderr, "%s: %s\n", hostname, (char*)gai_strerror(err));
//        abort();
//    }
//
//    for (struct addrinfo* addr = addrs; addr != NULL; addr = addr->ai_next)
//    {
//        sd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
//        if (sd == -1)
//        {
//            err = errno;
//            break; // if using AF_UNSPEC above instead of AF_INET/6 specifically,
//                   // replace this 'break' with 'continue' instead, as the 'ai_family'
//                   // may be different on the next iteration...
//        }
//
//        if (connect(sd, addr->ai_addr, addr->ai_addrlen) == 0)
//            break;
//
//        err = errno;
//
//        closesocket(sd);
//        sd = -1;
//    }
//
//    freeaddrinfo(addrs);
//
//    if (sd == -1)
//    {
//        fprintf(stderr, "%s: %s\n", hostname, strerror(err));
//        abort();
//    }
//
//    return sd;
//}


std::string HostnameToIPAddress(std::string& hostname)
{
    std::string s;
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult == NO_ERROR)
    {
        HOSTENT* pHostEnt = gethostbyname(hostname.c_str());
        if (pHostEnt)
        {
            if (pHostEnt->h_addr_list[0])
            {
                s.append(std::to_string((int)(BYTE) pHostEnt->h_addr_list[0][0]));
                s.append(".");
                s.append(std::to_string((int)(BYTE)pHostEnt->h_addr_list[0][1]));
                s.append(".");
                s.append(std::to_string((int)(BYTE)pHostEnt->h_addr_list[0][2]));
                s.append(".");
                s.append(std::to_string((int)(BYTE)pHostEnt->h_addr_list[0][3]));
            }
        }
        WSACleanup();
    }
    return s;
}

template <typename T>
int print_vec(T t)
{
    if (t.empty())
    {
        std::cerr << "Vector is empty error!" << std::endl;
        return -1;
    }
    for (unsigned i = 0; i < t.size(); ++i)
    {
        std::cout << t[i] << std::endl;
    }
    std::cout << std::endl;
    return 0;

    //for_each(vec.begin(), vec.end(), [](const int& n) { std::cout << n << std::endl; });
}

//void print_vec(std::vector<int>& vec)
//{
//    if (vec.empty())
//    {
//        std::cerr << "Empty vector error!" << std::endl;
//    }
//    for_each(vec.begin(), vec.end(), [](const int& n) { std::cout << n << std::endl; });
//}



int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Input parameter expected error. Quiting!" << std::endl;
        return -1;
    }
    
    std::string hostname = "";
    hostname.assign(argv[1]);
    std::string hostname_ip = HostnameToIPAddress(hostname);

    if( hostname_ip.empty() )
    {
        std::cerr << "Host IP is empty error" << std::endl;
    }
    else
    {
        std::cout << "Host is: " << hostname << std::endl;
        std::cout << "Host IP is: " << hostname_ip << std::endl;
    }

    std::vector<int> ia{ 20, 11, 1, -3, 0, 400, 8, 13, 21, 43, 453, 232323, 5345, 633, 636 ,4353 };
    std::sort(ia.begin(), ia.end());
    if( print_vec(ia) != 0 )
    {
        std::cerr << "error printing vector" << std::endl;
        return -1;
    }
    std::vector<double> da{ 13.14, -6.28, 112.56, 25.12, -.01232, 322.12, 0,01 };
    std::sort(da.begin(), da.end());
    if( print_vec(da) != 0 )
    {
        std::cerr << "error printing vector" << std::endl;
        return -1;
    }

    std::vector<std::string> sa{ "piglet", "bird", "bear", "whale", "querty", "yaron", "char", "string", "url", "try", "catch" };
    std::sort(sa.begin(), sa.end());
    if( print_vec(da) != 0 )
    {
        std::cerr << "error printing vector" << std::endl;
        return -1;
    }
    return 0; 
}


