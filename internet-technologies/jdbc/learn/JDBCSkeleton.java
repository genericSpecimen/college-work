import java.sql.*;

public class NumberOfRows {
	public static void main(String[] args) {
		try {
			Class.forName("org.mariadb.jdbc.Driver");
			// load the driver	
		} catch(ClassNotFoundException e) {
			System.err.println("Failed to load JDBC Driver: " + e.getMessage());
			System.exit(1);
		}

		try {
			// request Connection to database
			Connection conn = DriverManager.getConnection("jdbc:mysql://localhost/StudentResults", "<username>", "<password>");
			Statement stmt;
			ResultSet rs;

			// close the connection
			conn.close();
		} catch(SQLException e) {
			System.err.println("An SQLException has occured: " + e.getMessage());
			System.exit(2);
		}
	}
}

