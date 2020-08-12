#include <locale>


string ipAddress = "46.12.83.170";			// IP Address of the server
int port = 27015;						// Listening port # on the server
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
    }
        

    while(1)
    {

        if (LastButtonPushed == Buttons.SignIn)	
        {
            setlocale(LC_CTYPE, "");

            EmailSend = string(Strings.EmailStr.begin(), Strings.EmailStr.end());
            PasswordSend = string(Strings.PasswordStr.begin(), Strings.PasswordStr.end());


            int sendResult = send(sock, EmailSend.c_str(), EmailSend.size() , 0);
            int sendResult2 = send(sock, PasswordSend.c_str(), PasswordSend.size(), 0);

            Strings.EmailStr.clear();
            Strings.PasswordStr.clear();

            if (sendResult != SOCKET_ERROR)
            {
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



	


 

