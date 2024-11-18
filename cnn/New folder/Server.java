import java.io.FileOutputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class Server {
    public static void main(String[] args) {
        DatagramSocket socket = null;
        try {
            socket = new DatagramSocket(9876);
            byte[] receiveData = new byte[1024];
            FileOutputStream fos = new FileOutputStream("file_received.txt");

            System.out.println("Server is ready to receive the file.");

            while (true) {
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                socket.receive(receivePacket);
                String fileContent = new String(receivePacket.getData(), 0, receivePacket.getLength());

                // Check for end of transmission signal
                if (fileContent.equals("END")) {
                    break; // End of file transfer
                }

                // Write the received data to the file
                fos.write(fileContent.getBytes());
            }

            fos.close();
            System.out.println("File received and saved as file_received.txt");
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (socket != null && !socket.isClosed()) {
                socket.close();
            }
        }
    }
}
