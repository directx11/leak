# leak
Test repository to check flutter/grpc memory leaks

Repo contains two projects - server written in C++, which is compiled using cmake tool and client, written in flutter.

To build sever, You need two steps.
First one will fetch grpc repo and build it as external library for main project
Enter "server/third_party" folder and run two commands:
```
cmake .
cmake --build .
```
Then back stepa back to "server" folder and do the same
This step will use grpc built previously, generate required interface files and build console application sending continous data stream.
```
cmake .
cmake --build .
```

FLutter installation is required.
To build and run flutter application, enter "client" folder and run command:
```
flutter run
```
