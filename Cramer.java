
public class Cramer {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		double a = 21.8;
		int b = 2;
		int e = 28;
		int c = 7;
		int d = 8;
		int f = 62;
		double x = (e*d-b*f)/(a*d-b*c);
		double y = (a*f-e*c)/(a*d-b*c);
		System.out.println(x);
		System.out.println(y);
	}

}
