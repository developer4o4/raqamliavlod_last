import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ikkita butun sonni o'qib olish
        int A = scanner.nextInt();
        int B = scanner.nextInt();

        // Shart operatorlari orqali solishtirish
        if (A > B) {
            System.out.println(">");
        } else if (A < B) {
            System.out.println("<");
        } else {
            System.out.println("=");
        }
    }
}

