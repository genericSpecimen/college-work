import java.sql.*;

public class DBDemo {
	public static void main(String[] args) throws SQLException, ClassNotFoundException {
		Class.forName("org.mariadb.jdbc.Driver"); // load the driver
		System.out.println("Driver loaded!");

		Connection connection = DriverManager.getConnection("jdbc:mysql://localhost/test", "<username>", "<password>");
		System.out.println("It works!");
		
		connection.close();
	}
}

