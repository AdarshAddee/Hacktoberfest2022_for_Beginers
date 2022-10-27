// Github username: https://github.com/vishwjeet-ujgare
/* Aim: It identifies the host, or more specifically its network interface.
It provides the location of the host in the network, and thus the capability of establishing a path to that host.
*/
// Date:27/10/2022



// Java program to determine the IP address
// and host name of local computer
  
import java.io.*;
import java.net.InetAddress;
public class GFG {
    public static void main(String[] args) throws Exception
    {
        // a variable of type InetAddress to store
        // the address of the local host
        InetAddress addr = InetAddress.getLocalHost();
        // Returns the IP address string in
        // textual presentation.
        System.out.println("Local HostAddress:  "
                           + addr.getHostAddress());
        // Gets the host name for this IP address.
        System.out.println("Local host name: "
                           + addr.getHostName());
    }
}
