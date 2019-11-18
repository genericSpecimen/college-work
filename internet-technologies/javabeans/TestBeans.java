import pracs.StudentBean;
import pracs.EmployeeBean;
import java.util.Arrays;

public class TestBeans {
	public static void main(String[] args) {

		// -------- Student Bean -----------
		StudentBean student = new StudentBean();
		student.setName("Bob Miller");
		student.setRollno(10);
		int marks[] = {20, 40, 89, 67, 89, 98};
		student.setMarks(marks);
		System.out.println("----- StudentBean -----");
		System.out.println("Roll no: " + student.getRollno());
		System.out.println("Name   : " + student.getName());
		System.out.println("Marks  : " + Arrays.toString(student.getMarks()));
		System.out.println("-----------------------");
		// -----------------------------------

		// -------- Employee Bean -----------
		EmployeeBean employee = new EmployeeBean();
		employee.setName("Stacy Miller");
		employee.setId(100);
		employee.setSalary(2500000);
		System.out.println("----- Employee Bean -----");
		System.out.println("Id     : " + employee.getId()); 
		System.out.println("Name   : " + employee.getName());
		System.out.println("Salary : " + employee.getSalary());
		System.out.println("-------------------------");
		// -----------------------------------

	}
}

