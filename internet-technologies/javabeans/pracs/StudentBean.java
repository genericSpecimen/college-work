package pracs;

import java.io.Serializable;

public class StudentBean implements Serializable {
	private int rollno;
	private int marks[];
	private String name;

	public StudentBean() {
		// no argument constructor
	}
	public void setRollno(int rollno) {
		this.rollno = rollno;
	}
	public int getRollno() {
		return this.rollno;
	}
	public void setMarks(int index, int marks) {
		this.marks[index] = marks;
	}
	public void setMarks(int marks[]) {
		this.marks = marks;
	}
	public int getMarks(int index) {
		return this.marks[index];
	}
	public int[] getMarks() {
		return this.marks;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getName() {
		return this.name;
	}
}

