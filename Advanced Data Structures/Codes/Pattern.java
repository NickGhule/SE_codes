import java.util.Scanner;

public class Pattern {
public static void main(String[] args) {
    int lines;
    Scanner input = new Scanner(System.in);
    System.out.print("Enter No. Of Lines ::");
    lines = 4;
    boolean flag = false;

    for (int i = 0; i < lines; i++) {
        for (int j = i*4 +1; ; ) {
            if ( (i+1) % 2 == 0 ) {
                j += 4;
            }
            System.out.print(j + " ");
            if (j % 4 == 0) {
                flag = !flag;
                break;
            }
            
            if ( flag == false) {
                j++;
            }
            else j--;
            
        }
        System.out.println("");
    }

    input.close();
}

}