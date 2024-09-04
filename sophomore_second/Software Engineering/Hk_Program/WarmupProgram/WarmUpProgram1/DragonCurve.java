public class DragonCurve {

    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        String instructions = dragonCurveInstructions(N);
        System.out.println(instructions);
    }
    public static String dragonCurveInstructions(int N) {
        if (N == 0) return "F";
        

        String curveNMinus1 = dragonCurveInstructions(N - 1);
        String reverseCurveNMinus1 = reverseCurveInstructions(curveNMinus1);

        return curveNMinus1 + "L" + reverseCurveNMinus1;
    }


    public static String reverseCurveInstructions(String instructions) {
        StringBuilder reverse = new StringBuilder();
        for (int i = instructions.length() - 1; i >= 0; i--) {
            char ch = instructions.charAt(i);
            if (ch == 'L') reverse.append('R');
            else if (ch == 'R') reverse.append('L');
            else reverse.append(ch);
        }
        return reverse.toString();
    }
}