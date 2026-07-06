# TCP Server using POSIX Sockets (C++)

A simple TCP server implementation in C++ using POSIX socket APIs on Linux. This project is based on **Beej's Guide to Network Programming** and demonstrates the fundamentals of socket programming.

 📌 Features
- Create a TCP socket
- Bind the socket to a port
- Listen for incoming client connections
- Accept a client connection
- Send a welcome message to the client
- Close the connection gracefully

 🛠️ Technologies Used

- C++
- Linux (Ubuntu/WSL)
- POSIX Socket API
- g++

📂 Project Structure

project1_server/
│── server1.cpp
│── README.md

🚀 Build

Compile the server:
g++ server.cpp -o server1

▶️ Run

Start the server:
./server

The server will wait for incoming connections on port **3490**.

🧪 Test the Server

Open another terminal and connect using Netcat:
nc localhost 3490


Output:
Hello from Beej Server!

 📚 Socket Functions Used

| Function | Purpose |
|----------|---------|
| `socket()` | Creates a TCP socket |
| `getaddrinfo()` | Retrieves address information |
| `bind()` | Binds the socket to a port |
| `listen()` | Listens for incoming connections |
| `accept()` | Accepts a client connection |
| `send()` | Sends data to the client |
| `close()` | Closes the socket |


📖 Learning Objectives

This project helped me understand:
- TCP client-server communication
- Socket lifecycle
- Linux networking fundamentals
- POSIX socket programming
- Basic network programming using C++

📌 References
- Beej's Guide to Network Programming

👩‍💻 Author : Sumita Turkane
 This project is part of my Linux and Networking learning journey.
