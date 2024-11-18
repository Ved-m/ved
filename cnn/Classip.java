import java.util.Scanner;

public class Classip{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Prompt the user to enter an IP address
        System.out.print("Enter an IP address: ");
        String ip = scanner.nextLine();

        // Split the IP address into parts
        String[] parts = ip.split("\\.");
        if (parts.length != 4) {
            System.out.println("Invalid IP address format.");
            return;
        }

        try {
            // Convert the first part to an integer
            int firstOctet = Integer.parseInt(parts[0]);

            // Determine the class based on the first octet
            if (firstOctet >= 1 && firstOctet <= 126) {
                System.out.println("Class A");
            } else if (firstOctet >= 128 && firstOctet <= 191) {
                System.out.println("Class B");
            } else if (firstOctet >= 192 && firstOctet <= 223) {
                System.out.println("Class C");
            } else if (firstOctet >= 224 && firstOctet <= 239) {
                System.out.println("Class D (Multicast)");
            } else if (firstOctet >= 240 && firstOctet <= 255) {
                System.out.println("Class E (Experimental)");
            } else {
                System.out.println("Invalid IP address class.");
            }
        } catch (NumberFormatException e) {
            System.out.println("Invalid IP address format.");
        }

        scanner.close();
    }
}
