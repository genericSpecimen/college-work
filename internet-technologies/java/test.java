import java.util.ArrayList;

class test {
	public static void main(String[] args) {
		ArrayList<String> names = new ArrayList<String>();
		names.add("A");
		System.out.println(names);
		names.add(0, "B");
		System.out.println(names);
		names.add("C");
		System.out.println(names);
		names.remove(1);
		System.out.println(names);

	}
}
