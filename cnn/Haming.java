import java.util.Scanner;

public class Haming {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a 7-bit binary string: ");
        String input = scanner.next();

        if (input.length() != 7) {
            System.out.println("Invalid input. Please enter a 7-bit binary string.");
            return;
        }

        int[] dataBits = new int[7];
        for (int i = 0; i < 7; i++) {
            dataBits[i] = Character.getNumericValue(input.charAt(i));
        }

        int[] encodedBits = encodeHamming(dataBits);
        System.out.print("Encoded bits: ");
        for (int bit : encodedBits) {
            System.out.print(bit);
        }
        System.out.println();

        System.out.print("Enter the received 11-bit binary string: ");
        String received = scanner.next();

        if (received.length() != 11) {
            System.out.println("Invalid input. Please enter an 11-bit binary string.");
            return;
        }

        int[] receivedBits = new int[11];
        for (int i = 0; i < 11; i++) {
            receivedBits[i] = Character.getNumericValue(received.charAt(i));
        }

        int[] decodedBits = decodeHamming(receivedBits);
        System.out.print("Decoded bits: ");
        for (int i = 0; i < 7; i++) {
            System.out.print(decodedBits[i]);
        }
        System.out.println();
    }

    // Function to encode data bits using Hamming code
    public static int[] encodeHamming(int[] dataBits) {
        int[] encodedBits = new int[11];
        encodedBits[2] = dataBits[0];
        encodedBits[4] = dataBits[1];
        encodedBits[5] = dataBits[2];
        encodedBits[6] = dataBits[3];
        encodedBits[8] = dataBits[4];
        encodedBits[9] = dataBits[5];
        encodedBits[10] = dataBits[6];

        encodedBits[0] = encodedBits[2] ^ encodedBits[4] ^ encodedBits[6] ^ encodedBits[8] ^ encodedBits[10];
        encodedBits[1] = encodedBits[2] ^ encodedBits[5] ^ encodedBits[6] ^ encodedBits[9] ^ encodedBits[10];
        encodedBits[3] = encodedBits[4] ^ encodedBits[5] ^ encodedBits[6];
        encodedBits[7] = encodedBits[8] ^ encodedBits[9] ^ encodedBits[10];

        return encodedBits;
    }

    // Function to decode received bits and correct single-bit errors
    public static int[] decodeHamming(int[] receivedBits) {
        int[] decodedBits = new int[7];
        int p1 = receivedBits[0] ^ receivedBits[2] ^ receivedBits[4] ^ receivedBits[6] ^ receivedBits[8] ^ receivedBits[10];
        int p2 = receivedBits[1] ^ receivedBits[2] ^ receivedBits[5] ^ receivedBits[6] ^ receivedBits[9] ^ receivedBits[10];
        int p4 = receivedBits[3] ^ receivedBits[4] ^ receivedBits[5] ^ receivedBits[6];
        int p8 = receivedBits[7] ^ receivedBits[8] ^ receivedBits[9] ^ receivedBits[10];

        int errorPos = p1 * 1 + p2 * 2 + p4 * 4 + p8 * 8;

        if (errorPos != 0) {
            System.out.println("Error detected at position: " + errorPos);
            receivedBits[errorPos - 1] ^= 1; // Correct the error
        } else {
            System.out.println("No error detected.");
        }

        decodedBits[0] = receivedBits[2];
        decodedBits[1] = receivedBits[4];
        decodedBits[2] = receivedBits[5];
        decodedBits[3] = receivedBits[6];
        decodedBits[4] = receivedBits[8];
        decodedBits[5] = receivedBits[9];
        decodedBits[6] = receivedBits[10];

        return decodedBits;
    }
}
