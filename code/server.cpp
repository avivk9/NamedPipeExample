#include <iostream>
#include <windows.h>

#ifndef PIPE_NAME
#define PIPE_NAME TEXT("\\\\.\\pipe\\Pipe")
#endif

using namespace std;

int main(void)
{
    HANDLE hPipe;
    char buffer[1024];
    DWORD dwRead;


    hPipe = CreateNamedPipe(PIPE_NAME,
        PIPE_ACCESS_DUPLEX,
        PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,   // FILE_FLAG_FIRST_PIPE_INSTANCE is not needed but forces CreateNamedPipe(..) to fail if the pipe already exists...
        1,
        1024 * 16,
        1024 * 16,
        NMPWAIT_USE_DEFAULT_WAIT,
        NULL);
    cout << "named pipe: " << PIPE_NAME << " is up! waiting for client to join\n";
    while (hPipe != INVALID_HANDLE_VALUE)
    {
        if (ConnectNamedPipe(hPipe, NULL) != FALSE)   // wait for someone to connect to the pipe
        {
            cout << "client connected to the pipe, now start printing...\n";
            while (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL) != FALSE)
            {
                /* add terminating zero */
                buffer[dwRead] = '\0';

                /* do something with data in buffer */
                printf("%s\n", buffer);
            }
        }
        cout << "client disconnected :( \nclosing server";
        DisconnectNamedPipe(hPipe);
    }

    return 0;
}