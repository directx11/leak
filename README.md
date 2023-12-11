# leak
Test repository to check flutter/grpc memory leaks

Repo contains two projects - server written in C++, which is compiled using cmake tool and client, written in flutter.

To build sever, enter "server" folder and run two commands:
cmake .
cmake --build .

To build and run flutter application, enter "client" folder and run command:
flutter run
