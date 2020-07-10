#include <locale>


    string ipAddress = "127.0.0.1";			
    int port = 54000;					
    char buf[4096];

    string EmailSend;
    string PasswordSend;
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
            //ExitProcess(EXIT_FAILURE);
        }
        


        while(1)
        {

            if (pPushedSignIn)	
            {
                setlocale(LC_CTYPE, "");

                EmailSend = string(EmailStr.begin(), EmailStr.end());
                PasswordSend = string(PasswordStr.begin(), PasswordStr.end());


                int sendResult = send(sock,EmailSend.c_str(), EmailSend.size() , 0);
                int sendResult2 = send(sock, PasswordSend.c_str(), PasswordSend.size(), 0);

                EmailStr.clear();
                PasswordStr.clear();

                if (sendResult != SOCKET_ERROR)
                {
                    // Wait for response
                    ZeroMemory(buf, 4096);
                    int bytesReceived = recv(sock, buf, 4096, 0);
                    if (bytesReceived > 0)
                    {
                        
                    }
                }
            }

            Sleep(10);
        } 

        closesocket(sock);
        WSACleanup();
    }



	


 

