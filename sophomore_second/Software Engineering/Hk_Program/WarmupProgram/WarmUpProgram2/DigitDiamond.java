public class DigitDiamond {

    public static void main(String[] args) {
        DigitDiamond();
    }

    public static void DigitDiamond() {
        int n = 9;

        for (int i = 0; i <= n; i++) {

            for (int j = 0; j < n - i; j++) {
                System.out.print("  ");
            }
            for (int j = i; j > 0; j--) {
                System.out.print(j + " ");
            }
            System.out.print(0);
            for (int j = 1; j <= i; j++) {
                System.out.print(" " + j);
            }

            System.out.println();
        }

        for (int i = n - 1; i >= 0; i--) {

            for (int j = 0; j < n - i; j++) {
                System.out.print("  ");
            }
            for (int j = i; j > 0; j--) {
                System.out.print(j + " ");
            }
            System.out.print(0);
            for (int j = 1; j <= i; j++) {
                System.out.print(" " + j);
            }

            System.out.println();
        }
    }
}
