# NamedPipeExample
Simple example of named pipe, which used for transferring data between <b>diffrent</b> processes

A [named pipe](https://learn.microsoft.com/en-us/windows/win32/ipc/named-pipes) is a named, one-way or duplex pipe for communication between the pipe server and one or more pipe clients. All instances of a named pipe share the same pipe name, but each instance has its own buffers and handles, and provides a separate conduit for client/server communication.

## Usage
- Create 2 C++ projects, one for the server and another for the client

- In each project source code add the matching .cpp file

- Debug both files

- First, run the server and then the client and follow the instructions

## Code Example
In the right you'll see the client's window and in the left the server's one

![code_example](https://i2.paste.pics/493859180d6b00fa5b3724186ce0923b.png)