import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Types;

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
			
			CallableStatement cstmt = conn.prepareCall("{ call countRows(?)}");
			cstmt.registerOutParameter(1, Types.INTEGER);
			cstmt.execute();
			int numRows = cstmt.getInt(1);
			System.out.println("Number of rows in Students table: " + numRows);

			// close the connection
			conn.close();
		} catch(SQLException e) {
			System.err.println("An SQLException has occured: " + e.getMessage());
			System.exit(2);
		}
	}
}

