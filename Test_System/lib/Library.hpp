#ifndef _LIBRARY_H_
#define _LIBRARY_H_
	

#if defined _WIN32 || defined _WIN64
	#define WINDOWS
#endif

#ifdef WINDOWS
	#include <winsock2.h>
	//#pragma comment(lib, "ws2_32.lib")
	typedef int SOCKET_SIZE;
#else
	#include <unistd.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <netdb.h>
	typedef int SOCKET;
	typedef socklen_t SOCKET_SIZE;
	typedef struct sockaddr SOCKET_ADDR;
	typedef struct sockaddr_in SOCKADDR_IN;
#endif

	// C library
	#include <stdlib.h>
	#include <string.h>
	#include <stdio.h>


	// ISO C++11 standard library
	#include <iostream>
	#include <fstream>
	#include <chrono>
	
	typedef int SOCKET_TYPE;
	typedef unsigned int PORT;
	typedef int PROTOCOL;
	typedef char* IP;
	typedef char* TAG;
	typedef char* MESSAGE;
	#define TCP SOCK_STREAM
	#define UDP SOCK_DGRAM
	
	#ifdef DOMAIN
		#undef DOMAIN
		typedef int DOMAIN;
	#else
		typedef int DOMAIN;
	#endif

    
#endif