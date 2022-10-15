# include <winsock.h>
# include <iostream>
using namespace std;

int main ()
{    
  WSADATA ws;
    int res;
    // Initializing winsock
    // Before using any of the winsock constructs, the library must be initialized by calling the WSAStartup function. 
    res = WSAStartup ( MAKEWORD(2, 2), &ws );
    if ( res != 0 )
  {
        cout << "Failed to initialize winsock : " << res;
        return 1;
    }
    
  char * hostname;  
    struct hostent * host_info;
    struct in_addr addr;
    DWORD dw;
    int i = 0;
    
    hostname = (char *)"codespeedy.com"; // hostname for which we want the IP address
    host_info = gethostbyname ( hostname ); // gethostbyname function retrieves host information.
  // gethostbyname returns a pointer of type struct hostent.
  //A null pointer is returned if an error occurs. The specific error number can be known by calling WSAGetLastError.
  
    if ( host_info == NULL ) 
  {
        dw = WSAGetLastError ();
        if ( dw != 0 )
    {
            if ( dw == WSAHOST_NOT_FOUND )
      {
                cout << "Host is not found";
                return 1;
            }
      else if ( dw == WSANO_DATA )
      {
                cout << "No data record is found";
                return 1;
            }
      else
      {
                cout << "Function failed with an error : " << dw;
                return 1;
            }
        }
    }
  else
  {
        cout << "Hostname : " << host_info->h_name << endl;
        while ( host_info->h_addr_list[i] != 0 )
    {
            addr.s_addr = *(u_long *) host_info->h_addr_list[i++];
            cout<<"\nIP Address "<< inet_ntoa(addr); // inet_ntoa function converts IPv4 address to ASCII string in Internet standard dotted-decimal format.
        }
    }
    return 0;
}
