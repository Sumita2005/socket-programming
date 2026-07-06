#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT "3490"
using namespace std;
int main()
{
    int sockfd, new_fd;

    struct addrinfo hints, *servinfo;

    // Clear hints structure
    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_INET;        // IPv4
    hints.ai_socktype = SOCK_STREAM;  // TCP
    hints.ai_flags = AI_PASSIVE;      // Use my IP

    // Get address information
    if (getaddrinfo(nullptr, PORT, &hints, &servinfo) != 0)
    {
        cerr << "getaddrinfo failed\n";
        return 1;
    }

    // Create socket
    sockfd = socket(servinfo->ai_family,
                    servinfo->ai_socktype,
                    servinfo->ai_protocol);

    if (sockfd == -1)
    {
        cerr << "socket failed\n";
        freeaddrinfo(servinfo);
        return 1;
    }

    // Bind socket
    if (bind(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1)
    {
        cerr << "bind failed\n";
        close(sockfd);
        freeaddrinfo(servinfo);
        return 1;
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1)
    {
        cerr << "listen failed\n";
        close(sockfd);
        freeaddrinfo(servinfo);
        return 1;
    }

    cout << "Server Waiting..." << std::endl;

    // Accept a client
    new_fd = accept(sockfd, nullptr, nullptr);

    if (new_fd == -1)
    {
        cerr << "accept failed\n";
        close(sockfd);
        freeaddrinfo(servinfo);
        return 1;
    }

    string msg = "Hello from Beej Server!\n";

    send(new_fd, msg.c_str(), msg.size(), 0);

    close(new_fd);
    close(sockfd);
    freeaddrinfo(servinfo);

    return 0;
}