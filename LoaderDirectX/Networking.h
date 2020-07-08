



using namespace std;


    string ipAddress = "127.0.0.1";			// IP Address of the server
    int port = 54000;						// Listening port # on the server
    char buf[4096];
     char* re;
    string oof;


    void convertWStringToCharPtr(_In_ std::wstring input, _Out_ char* outputString)
    {
        size_t outputSize = input.length() + 1; // +1 for null terminator
        re = new char[outputSize];
        size_t charsConverted = 0;
        const wchar_t* inputW = input.c_str();
        wcstombs_s(&charsConverted, re, outputSize, inputW, input.length());
    }

    // Initialize WinSock
    void Networking()
    {
        WSAData data;
        WORD ver = MAKEWORD(2, 2);
        int wsResult = WSAStartup(ver, &data);

        // Create socket
        SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

        // Fill in a hint structure
        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(port);
        inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

        // Connect to server
        int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
        if (connResult == SOCKET_ERROR)
        {        
            closesocket(sock);
            WSACleanup();
            ExitProcess(EXIT_FAILURE);
        }

        // Do-while loop to send and receive data


        while(1)
        {
            // Prompt the user for some text
           

            if (pPushedSignIn)		// Make sure the user has typed in something
            {
                // Send the text
                //int ret = wcstombs_s((size_t)EmailStr.length(),(char*)&oof, EmailStr.length(),(WCHAR*)&EmailStr, (size_t)EmailStr.size());
                char* addr = (char*)EmailStr;
                int sendResult = send(sock,(CHAR*)&re, 5 , 0);
                if (sendResult != SOCKET_ERROR)
                {
                    // Wait for response
                    ZeroMemory(buf, 4096);
                    int bytesReceived = recv(sock, buf, 4096, 0);
                    if (bytesReceived > 0)
                    {
                        // Echo response to console
                        //cout << "SERVER> " << string(buf, 0, bytesReceived) << endl;
                    }
                }
            }
            Sleep(10);
        } 

        // Gracefully close down everything
        closesocket(sock);
        WSACleanup();
    }



	


 

