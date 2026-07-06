#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>//----Networking function : htons() ,inet_pton()
#include <sys/socket.h>//---Contains: socket() bind() listen() accept()
using namespace std;
int main()
{
    // Create a TCP socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);//---creating a socket

    if (serverSocket == -1)
    {
        cout << "Socket creation failed!\n";
        return 1;
    }

    cout << "Socket created successfully!\n";
 sockaddr_in serverAddress{}; // ----- Structure to hold server address information

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9090);

   if (inet_pton(AF_INET,
              "127.0.0.1",
              &serverAddress.sin_addr) <= 0)
{
    cout << "Invalid IP Address!\n";
    return 1;
}
    if (bind(serverSocket,
             (sockaddr*)&serverAddress,
             sizeof(serverAddress)) == -1)
    {
        cout << "Bind failed!\n";
        return 1;
    }

    cout << "Server bound to 127.0.0.1:9090\n";

    close(serverSocket);
int yes = 1;
setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
    return 0;
}
