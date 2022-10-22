#include <iostream>
#include <windows.h>

#ifndef PIPE_NAME
#define PIPE_NAME TEXT("\\\\.\\pipe\\Pipe")
#endif

using namespace std;

int main(void) {
    bool connected = true;
    HANDLE pipe = CreateFile(PIPE_NAME, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    ConnectNamedPipe(pipe, NULL);
    string message;
    DWORD numWritten;
    cout << "please enter 'exit' for exiting the program\nmessages will print in the server cmd" << endl;
    while (connected) {
        cin >> message;
        if (message == "exit") return 0;
        WriteFile(pipe, &message[0], message.length(), &numWritten, NULL);
    }
}