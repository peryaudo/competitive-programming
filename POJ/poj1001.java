import java.util.*;
import java.math.*;
public class Main { 
	public static void main(String[] args){
		for(Scanner s = new Scanner(System.in);s.hasNext();){
			System.out.println(s.nextBigDecimal().pow(s.nextInt()).toPlainString().replaceAll("^0|\\.?0*$",""));
		}
	}
}
