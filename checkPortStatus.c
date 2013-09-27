/*
 * Copyright (C) 2013   Valentin Bajrami
 *
 * This Program is free to modify and distribute under whatever terms.
 *
 * The author is not responsible for any data loss this application might cause.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h> 


int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		printf("Usage: %s [host/ip] [port]\n", argv[0]);
		return 1;
	}
    char *hostname = argv[1];
    int prt_number = atoi(argv[2]);

    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(hostname);

    if (server == 0) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);

    serv_addr.sin_port = htons(prt_number);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        printf("Port %i is closed on host %s\n",prt_number, hostname);
    } 
	 else {
        printf("Port %i is open on host %s\n",prt_number, hostname);
    }
    close(sockfd);
    return 0;
}
