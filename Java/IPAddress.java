// github username DishaKhanapurkar
// Repo Aim: program to find IP Address of local host machine
// date : 20.10.22
import java.net.*;
class IPAddress {
  public static void main(String args[]) throws UnknownHostException {
    InetAddress local_add =InetAddress.getLocalHost();
    System.out.println("Local Host is : " +local_add);
  }
}
