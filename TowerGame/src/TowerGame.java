import java.util.Scanner;
import java.util.Stack;

public class TowerGame {


    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int input;
        System.out.println("enter number of Disks");
        input = in.nextInt();
        TG(input, 'A', 'B', 'C');
    }

    public static void TG(int nDisks, char first, char second, char third){
        if(nDisks == 1){
            System.out.println("Disk " + nDisks + " moved from " + " stack " + first + " to stack " + third);
            return;
        }
        TG(nDisks - 1, first, third, second);
        System.out.println("Disk " + nDisks + " moved from " + " stack " + first + " to stack " + third);
        TG(nDisks - 1, second, first, third);
    }
}
