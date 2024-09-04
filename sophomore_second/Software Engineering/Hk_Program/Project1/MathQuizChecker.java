import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class MathQuizChecker {
    private static final String INPUT_FILE = "quiz.txt";
    private static final String ANSWER_FILE = "answer.txt";
    private static final String OUTPUT_FILE = "check.txt";

    public static void main(String[] args) {
        try (BufferedReader quizReader = new BufferedReader(new FileReader(INPUT_FILE));
             BufferedReader answerReader = new BufferedReader(new FileReader(ANSWER_FILE));
             BufferedWriter writer = new BufferedWriter(new FileWriter(OUTPUT_FILE))) {
            String quizLine;
            String answerLine;
            int lineNumber = 1;
            while ((quizLine = quizReader.readLine()) != null && (answerLine = answerReader.readLine()) != null) {
                double expectedAnswer = Double.parseDouble(answerLine);
                double actualAnswer = evaluateExpression(quizLine);
                if (expectedAnswer == actualAnswer) {
                    writer.write("Problem " + lineNumber + ": Correct\n");
                } else {
                    writer.write("Problem " + lineNumber + ": Incorrect\n");
                }
                lineNumber++;
            }
            System.out.println("Check results written to: " + OUTPUT_FILE);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static double evaluateExpression(String expression) {
        String[] parts = expression.split(" ");
        double operand1 = parseOperand(parts[0]);
        double operand2 = parseOperand(parts[2]);
        String operator = parts[1];
        switch (operator) {
            case "+":
                return operand1 + operand2;
            case "-":
                return operand1 - operand2;
            case "*":
                return operand1 * operand2;
            case "/":
                return operand1 / operand2;
            default:
                throw new IllegalArgumentException("Invalid operator: " + operator);
        }
    }

    private static double parseOperand(String operand) {
        // Check if the operand is a fraction
        if (operand.contains("_")) {
            // Operand is a mixed fraction
            String[] parts = operand.split("_");
            int whole = Integer.parseInt(parts[0]);
            String[] fractionParts = parts[1].split("/");
            int numerator = Integer.parseInt(fractionParts[0]);
            int denominator = Integer.parseInt(fractionParts[1]);
            return whole + (double) numerator / denominator;
        } else if (operand.contains("/")) {
            // Operand is a proper fraction
            String[] fractionParts = operand.split("/");
            int numerator = Integer.parseInt(fractionParts[0]);
            int denominator = Integer.parseInt(fractionParts[1]);
            return (double) numerator / denominator;
        } else {
            // Operand is an integer
            return Double.parseDouble(operand);
        }
    }
}
