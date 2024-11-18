import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) {
        int port = 65432;  // Port number
        try {
            // Create a server socket
            ServerSocket serverSocket = new ServerSocket(port);
            System.out.println("Server is listening on port " + port);

            // Wait for a client to connect
            Socket socket = serverSocket.accept();
            System.out.println("Client connected");

            // Create input and output streams for communication
            InputStream input = socket.getInputStream();
            BufferedReader reader = new BufferedReader(new InputStreamReader(input));

            OutputStream output = socket.getOutputStream();
            PrintWriter writer = new PrintWriter(output, true);

            // Receive message from the client
            String message = reader.readLine();
            System.out.println("Received from client: " + message);

            // Send a response to the client
            writer.println("Hello, Client!");

            // Close the connections
            socket.close();
            serverSocket.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}
