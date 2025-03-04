import java.util.Random;
import java.util.Scanner;

public class Minesweeper {
    private static final int SIZE = 10;
    private static final int MINES = 10;
    private char[][] board;
    private boolean[][] revealed;
    private boolean gameOver;

    public Minesweeper() {
        board = new char[SIZE][SIZE];
        revealed = new boolean[SIZE][SIZE];
        gameOver = false;
        placeMines();
        calculateHints();
    }

    private void placeMines() {
        Random rand = new Random();
        int count = 0;
        while (count < MINES) {
            int x = rand.nextInt(SIZE);
            int y = rand.nextInt(SIZE);
            if (board[x][y] != 'M') {
                board[x][y] = 'M';
                count++;
            }
        }
    }

    private void calculateHints() {
        for (int x = 0; x < SIZE; x++) {
            for (int y = 0; y < SIZE; y++) {
                if (board[x][y] != 'M') {
                    board[x][y] = (char) ('0' + countAdjacentMines(x, y));
                }
            }
        }
    }

    private int countAdjacentMines(int x, int y) {
        int count = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (isInBounds(x + i, y + j) && board[x + i][y + j] == 'M') {
                    count++;
                }
            }
        }
        return count;
    }

    private boolean isInBounds(int x, int y) {
        return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
    }

    public void reveal(int x, int y) {
        if (gameOver || revealed[x][y]) return;
        revealed[x][y] = true;
        if (board[x][y] == 'M') {
            gameOver = true;
            System.out.println("Game Over! You hit a mine.");
        } else if (board[x][y] == '0') {
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (isInBounds(x + i, y + j)) {
                        reveal(x + i, y + j);
                    }
                }
            }
        }
    }

    public void printBoard() {
        for (int x = 0; x < SIZE; x++) {
            for (int y = 0; y < SIZE; y++) {
                if (revealed[x][y]) {
                    System.out.print(board[x][y] + " ");
                } else {
                    System.out.print(". ");
                }
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Minesweeper game = new Minesweeper();
        Scanner scanner = new Scanner(System.in);
        while (!game.gameOver) {
            game.printBoard();
            System.out.print("Enter coordinates (x y): ");
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            game.reveal(x, y);
        }
        scanner.close();
    }
}
