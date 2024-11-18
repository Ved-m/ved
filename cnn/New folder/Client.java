import java.io.FileInputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Client {
    public static void main(String[] args) {
        DatagramSocket socket = null;
        try {
            socket = new DatagramSocket();
            InetAddress serverAddress = InetAddress.getByName("localhost"); // or the server's IP address
            byte[] sendData = new byte[1024];
            FileInputStream fis = new FileInputStream("file_to_send.txt"); // Ensure this file exists

            int bytesRead;
            while ((bytesRead = fis.read(sendData)) != -1) {
                DatagramPacket sendPacket = new DatagramPacket(sendData, bytesRead, serverAddress, 9876);
                socket.send(sendPacket);
            }

            // Signal the end of the transmission
            String endMessage = "END";
            DatagramPacket endPacket = new DatagramPacket(endMessage.getBytes(), endMessage.length(), serverAddress, 9876);
            socket.send(endPacket);

            fis.close();
            System.out.println("File sent successfully.");
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (socket != null && !socket.isClosed()) {
                socket.close();
            }
        }
    }
}
