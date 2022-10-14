// Github username: RashmiNirasha
// Aim: Printing local computer ipaddress and host name using java
// Date: 2022/10/14

import java.net.InetAddress;
public class IPAdress {
    public static void main(String[] args)
            throws Exception {
        InetAddress addr = InetAddress.getLocalHost();
        System.out.println("Local HostAddress:  "+addr.getHostAddress());
        String hostname = addr.getHostName();
        System.out.println("Local host name: "+hostname);
    }
}