import java.sql.*;

public class ResultsTest {
	public static void main(String[] args) throws SQLException, ClassNotFoundException {
		Class.forName("org.mariadb.jdbc.Driver"); // load the driver
		Connection conn = DriverManager.getConnection("jdbc:mysql://localhost/people", "<username>", "<password>");
		try(Statement stmt = conn.createStatement();
			ResultSet rs = stmt.executeQuery("SELECT * FROM users");
		) {
			if(!rs.next()) {
				System.out.println("No records found!");
			} else {
				String username, password, row;
				do {
					row = rs.getString(1) + ", " + rs.getString(2);
					System.out.println(row);
				} while(rs.next());
			}
		}	
		conn.close();
	}
}

