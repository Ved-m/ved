import java.util.Scanner;

public class Crc {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the data bits
        System.out.print("Enter the data bits: ");
        String dataBits = scanner.next();

        // Input the generator polynomial
        System.out.print("Enter the generator polynomial: ");
        String generator = scanner.next();

        // Append zeros to the data bits
        String appendedDataBits = dataBits + "0".repeat(generator.length() - 1);

        // Compute CRC
        String crc = computeCRC(appendedDataBits, generator);
        System.out.println("CRC: " + crc);

        // Transmitted data
        String transmittedData = dataBits + crc;
        System.out.println("Transmitted Data: " + transmittedData);

        // Check for errors in received data
        System.out.print("Enter the received data: ");
        String receivedData = scanner.next();

        if (checkForErrors(receivedData, generator)) {
            System.out.println("No error detected.");
        } else {
            System.out.println("Error detected!");
        }
    }

    // Function to compute CRC
    public static String computeCRC(String data, String generator) {
        int dataBitsLength = data.length();
        int generatorLength = generator.length();

        // Convert data and generator to binary arrays
        int[] dataBits = new int[dataBitsLength];
        int[] generatorBits = new int[generatorLength];
        for (int i = 0; i < dataBitsLength; i++) {
            dataBits[i] = data.charAt(i) - '0';
        }
        for (int i = 0; i < generatorLength; i++) {
            generatorBits[i] = generator.charAt(i) - '0';
        }

        // Apply CRC algorithm (binary division)
        for (int i = 0; i <= dataBitsLength - generatorLength; i++) {
            if (dataBits[i] == 1) {
                for (int j = 0; j < generatorLength; j++) {
                    dataBits[i + j] ^= generatorBits[j];
                }
            }
        }

        // Extract CRC from the remainder
        StringBuilder crc = new StringBuilder();
        for (int i = dataBitsLength - generatorLength + 1; i < dataBitsLength; i++) {
            crc.append(dataBits[i]);
        }

        return crc.toString();
    }

    // Function to check for errors in received data
    public static boolean checkForErrors(String data, String generator) {
        return computeCRC(data, generator).equals("0".repeat(generator.length() - 1));
    }
}
