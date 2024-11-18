import java.util.Scanner;

public class Subnet {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input: IP address, original subnet mask, and the number of subnets
        System.out.print("Enter an IP address (e.g., 192.168.1.10): ");
        String ipAddress = scanner.nextLine();

        System.out.print("Enter the original subnet mask (e.g., 255.255.255.0): ");
        String originalSubnetMask = scanner.nextLine();

        System.out.print("Enter the number of subnets: ");
        int numberOfSubnets = scanner.nextInt();

        // Calculate the new subnet prefix and subnet mask
        int originalPrefix = subnetMaskToPrefix(originalSubnetMask);
        int additionalBits = (int) Math.ceil(Math.log(numberOfSubnets) / Math.log(2));
        int newPrefix = originalPrefix + additionalBits;

        if (newPrefix > 32) {
            System.out.println("Error: Too many subnets requested. The prefix cannot exceed 32.");
        } else {
            String newSubnetMask = prefixToSubnetMask(newPrefix);

            System.out.println("IP Address: " + ipAddress);
            System.out.println("Original Subnet Mask: " + originalSubnetMask);
            System.out.println("Number of Subnets: " + numberOfSubnets);
            System.out.println("New Subnet Prefix: /" + newPrefix);
            System.out.println("New Subnet Mask: " + newSubnetMask);
        }

        scanner.close();
    }

    // Convert subnet mask to prefix (e.g., 255.255.255.0 -> 24)
    public static int subnetMaskToPrefix(String subnetMask) {
        String[] parts = subnetMask.split("\\.");
        int prefix = 0;
        for (String part : parts) {
            int value = Integer.parseInt(part);
            prefix += Integer.bitCount(value);
        }
        return prefix;
    }

    // Convert prefix to subnet mask (e.g., 24 -> 255.255.255.0)
    public static String prefixToSubnetMask(int prefix) {
        int mask = 0xFFFFFFFF << (32 - prefix);
        int part1 = (mask >> 24) & 0xFF;
        int part2 = (mask >> 16) & 0xFF;
        int part3 = (mask >> 8) & 0xFF;
        int part4 = mask & 0xFF;
        return part1 + "." + part2 + "." + part3 + "." + part4;
    }
}
