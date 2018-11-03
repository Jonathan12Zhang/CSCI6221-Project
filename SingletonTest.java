package singleton;

class Singleton {
	private static Singleton instance;
	
	private Singleton() {}
	
	public static Singleton getInstence() {
		if (instance == null) {
			instance = new Singleton();
		}
		return instance;
	}
	
	
}

public class SingletonTest {
	public static void main(String[] args) {
		Singleton s1 = Singleton.getInstence();
		Singleton s2 = Singleton.getInstence();
		Singleton s3 = Singleton.getInstence();
		
		if (s1 == s2 && s1 == s3 && s2 == s3) {
			System.out.println("They are same.");
		} else {
			System.out.println("They are differnet.");
		}
	}
}