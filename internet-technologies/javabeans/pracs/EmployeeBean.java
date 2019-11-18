package pracs;

import java.io.Serializable;

public class EmployeeBean implements Serializable {
	private int id;
	private double salary;
	private String name;

	public EmployeeBean() {
		// no argument constructor
	}
	public void setId(int id) {
		this.id = id;
	}
	public int getId() {
		return this.id;
	}
	public void setSalary(double salary) {
		this.salary = salary;
	}
	public double getSalary() {
		return this.salary;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getName() {
		return this.name;
	}
}

