import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class MathQuizGenerator {
    private static final String OUTPUT_FILE = "quiz.txt";

    public static void main(String[] args) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(OUTPUT_FILE))) {
            Random random = new Random();
            int numProblems = 10; // Number of problems to generate

            for (int i = 0; i < numProblems; i++) {
                int operation = random.nextInt(4); // 0: +, 1: -, 2: *, 3: /
                String[] numbers = generateNumbers(operation, random);
                String problem = generateProblemString(operation, numbers);
                writer.write(problem);
                writer.newLine();
            }
            System.out.println("Quiz generated successfully! Check the file: " + OUTPUT_FILE);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String[] generateNumbers(int operation, Random random) {
        // Generate two random numbers based on the operation type
        // This generates integers or fractions with denominator 1
        String[] numbers = new String[2];
        int num1 = random.nextInt(100) + 1; // First operand (random integer between 1 and 100)
        int num2 = random.nextInt(100) + 1; // Second operand (random integer between 1 and 100)

        // Generate fraction components for num1 and num2 randomly for some problems
        boolean isFraction1 = random.nextBoolean(); // Randomly decide if num1 will be a fraction
        boolean isFraction2 = random.nextBoolean(); // Randomly decide if num2 will be a fraction

        // If either number is a fraction, generate fraction components
        int numerator1 = isFraction1 ? random.nextInt(20) + 1 : 0; // Random numerator between 1 and 20 if it's a fraction
        int numerator2 = isFraction2 ? random.nextInt(20) + 1 : 0; // Random numerator between 1 and 20 if it's a fraction
        int denominator = isFraction1 || isFraction2 ? random.nextInt(20) + 1 : 1; // Random denominator between 1 and 20 if either number is a fraction

        // Convert the numbers to string format
        numbers[0] = isFraction1 ? num1 + "_" + numerator1 + "/" + denominator : String.valueOf(num1);
        numbers[1] = isFraction2 ? num2 + "_" + numerator2 + "/" + denominator : String.valueOf(num2);

        return numbers;
    }

    private static String generateProblemString(int operation, String[] numbers) {
        // Convert the numbers and operation to a string format
        // For example: "5 + 3 = ?"
        String operand1 = numbers[0];
        String operand2 = numbers[1];
        String operator;

        switch (operation) {
            case 0:
                operator = " + ";
                break;
            case 1:
                operator = " - ";
                break;
            case 2:
                operator = " * ";
                break;
            case 3:
                operator = " / ";
                break;
            default:
                operator = "";
                break;
        }

        return operand1 + operator + operand2 + " = ?";
    }
}
