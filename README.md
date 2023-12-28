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
If built was successful, it is enough to run server using command from server folder:
```
./grpc_test
```
Server should be started with message waiting for RPC call from flutter:
![image](https://github.com/directx11/leak/assets/2478093/3f720a31-010e-47c4-8961-b92598a2d301)

To run client application Flutter installation is required.
To build and run flutter application, enter "client" folder and run command:
```
flutter run
```
If server is running, there should be visible log on both sides showing communication between server and client:
![image](https://github.com/directx11/leak/assets/2478093/5820a5a4-a5c7-4873-97c3-6539156efe19)

Regarding classes showing memory leaking, "all classes" should be choosen in DevTools configuration:
![image](https://github.com/directx11/leak/assets/2478093/1e5a800a-cc91-476d-92d5-0516b7958131)

