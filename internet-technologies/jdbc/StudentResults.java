import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Scanner;


public class StudentResults {
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

			//-----------------------------query a----------------------------------------
			// find total number of Students
			stmt = conn.createStatement();
			String querya = "SELECT COUNT(*) AS num_students FROM Students;";

			rs = stmt.executeQuery(querya);
			if(rs.next()) {
				System.out.println("a) Total number of students: " + rs.getString(1));
			} else System.out.println("a) No records found!");
			stmt.close();
			//----------------------------------------------------------------------------
			
			//-----------------------------query b----------------------------------------
			// Print average marks for each subject input by user.
			String subjects[] = {"maths", "physics", "chemistry", "computer_science"};
			System.out.println("b) Enter a subject code to calculate the average marks for that subject: ");
			System.out.println("    Maths:               0");
			System.out.println("    Physics:             1");
			System.out.println("    Chemistry:           2");
			System.out.println("    Computer Science:    3");
			System.out.println("    Exit this loop:     -1");	
			String queryb = null;
			
			Scanner obj = new Scanner(System.in);
			int subject_code = 0;
			while (true) {
				System.out.print("   Enter subject code: ");
				subject_code = obj.nextInt();
				if(subject_code == -1) break;

				try {
					queryb = "SELECT AVG(" + subjects[subject_code] + ") FROM Results;";
					stmt = conn.createStatement();
					rs = stmt.executeQuery(queryb);
					if(rs.next()) {
						System.out.println("   Average marks for subject '" + subjects[subject_code] + "': "+ rs.getString(1));
					} else System.out.println("   b)No records found!");
				} catch (ArrayIndexOutOfBoundsException e) {
					System.err.println("Invalid subject code!");
				}
			}
			stmt.close();

			//----------------------------------------------------------------------------

			//-----------------------------query c----------------------------------------
			
			// name of student getting highest marks
			stmt = conn.createStatement();
			String queryc = "SELECT name FROM Students INNER JOIN Results ON Students.rollno = Results.rollno" + 
					" WHERE total_marks = (SELECT MAX(total_marks) FROM Results);";
			rs = stmt.executeQuery(queryc);
			System.out.println("c) Student(s) scoring highest marks: ");
			if(rs.next()) {
				do {
					System.out.println("   " + rs.getString(1));
				} while (rs.next());
			} else System.out.println("f) No records found!");
				
			stmt.close();
			//----------------------------------------------------------------------------
			
			//-----------------------------query d----------------------------------------
			// Find no of students getting first, second and third division.
			stmt = conn.createStatement();
			String queryd = "SELECT (Results.total_marks/400 * 100) FROM Results;";
			rs = stmt.executeQuery(queryd);

			if(rs.next()) {
				int num_students_div[] = {0, 0, 0}; // number of students getting 1st, 2nd and 3rd division
				float percentage;
				do {
					percentage = rs.getFloat(1);
					if(percentage >= 60 && percentage <= 100) num_students_div[0]++;
					else if(percentage >= 50 && percentage <= 59) num_students_div[1]++;
					else if(percentage >= 40 && percentage <= 49) num_students_div[2]++;
				} while (rs.next());

				System.out.println("d) Number of students getting: ");
				System.out.println("   First  division (60%-100%): " + num_students_div[0]);
				System.out.println("   Second division (50%-59%) : " + num_students_div[1]);
				System.out.println("   Third  division (40%-49%) : " + num_students_div[2]);

			} else System.out.println("d) No records found!");
			stmt.close();
			//----------------------------------------------------------------------------

			//-----------------------------query e----------------------------------------
			// subject wise toppers
			stmt = conn.createStatement();
			String querye = null;

			System.out.println("e) Subject wise toppers: ");
			for(String sub : subjects) {
				querye = "SELECT Students.name " +
					 "FROM Results INNER JOIN Students ON Results.rollno = Students.rollno " +
					 "WHERE " + sub + " = (SELECT MAX(" + sub + ") FROM Results);";
				rs = stmt.executeQuery(querye);
				if(rs.next()) {
					System.out.println( "   " + sub + ": " + rs.getString(1));
				} else System.out.println("e) No records found!");
			}
			stmt.close();
			//----------------------------------------------------------------------------

			//-----------------------------query f----------------------------------------
			// Find the average marks	
			stmt = conn.createStatement();
			String queryf = "SELECT AVG(Results.total_marks) AS AvgMarks FROM Results;";

			rs = stmt.executeQuery(queryf);
			if(rs.next()) {
				System.out.println("f) Average marks: " +  rs.getString(1));
			} else System.out.println("f) No records found!");
				
			stmt.close();
			
			//----------------------------------------------------------------------------

			//-----------------------------query g----------------------------------------
			//Find the student getting second highest marks.
			stmt = conn.createStatement();
			String queryg = "SELECT Students.name " +
					"FROM Results INNER JOIN Students ON Results.rollno = Students.rollno " +
					"WHERE Results.total_marks = ( " +
							"SELECT MAX(total_marks) " +
							"FROM Results " +
							"WHERE total_marks <> (SELECT MAX(total_marks) FROM Results));";

			rs = stmt.executeQuery(queryg);
			System.out.println("g) Student(s) scoring second highest marks: ");
			if(rs.next()) {
				do {
					System.out.println("   " + rs.getString(1));
				} while (rs.next());
			} else System.out.println("g) No records found!");
				
			stmt.close();
			

			//----------------------------------------------------------------------------


			// close the connection
			conn.close();
		} catch(SQLException e) {
			System.err.println("An SQLException has occured: " + e.getMessage());
			System.exit(2);
		}
	}
}

