// Github username: Samriddhii-Siingh
// Aim: Print IP Address and Hostname
// Date: 25-10-2022


import java.net.InetAddress;
import java.net.UnknownHostException;

public class Address {

	public static void main(String[] args) {
		
		try {
			InetAddress add = InetAddress.getLocalHost();
			System.out.println("IP address is : "+ add.getHostAddress());
			System.out.println("Host name is : "+ add.getHostName());
		} catch (UnknownHostException e) {
			System.out.println("Cannot find the local address");
		}

	}

}
