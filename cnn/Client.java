import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        String hostname = "127.0.0.1";  // Localhost
        int port = 65432;               // Port number

        try {
            // Create a socket to connect to the server
            Socket socket = new Socket(hostname, port);

            // Create input and output streams for communication
            OutputStream output = socket.getOutputStream();
            PrintWriter writer = new PrintWriter(output, true);

            InputStream input = socket.getInputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(input));

            // Send a message to the server
            writer.println("Hello, Server!");

            // Receive a response from the server
            String message = reader.readLine();
            System.out.println("Received from server: " + message);

            // Close the connection
            socket.close();
        } catch (UnknownHostException ex) {
            System.out.println("Server not found: " + ex.getMessage());
        } catch (IOException ex) {
            System.out.println("I/O error: " + ex.getMessage());
        }
    }
}
