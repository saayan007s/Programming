import java.util.*;
public class board {

    int[][] a = new int[9][9]; // board
    int player; // current player
    boolean playable; // valid move available
    int score; // score of the game

    public board() {
        a[4][4] = a[5][5] = 1;
        a[5][4] = a[4][5] = -1;

        player = 1;
        score = 0;
    }

    // prints the board
    public void printBoard() {
        System.out.printf("\n    ");
        for (int i = 1; i < 9; i++)
            System.out.printf("%d  ", (i));
        System.out.printf("\n\n");
        for (int i = 1; i < 9; i++) {
            System.out.printf("%d   ", (i + 1));
            for (int j = 1; j < 9; j++) {
                if (this.a[i][j] == 0)
                    System.out.printf("O  ");
                else if (this.a[i][j] == 1)
                    System.out.printf("+  ");
                else
                    System.out.printf("-  ");
            }
            System.out.printf("\n");
        }
        System.out.printf("\n");
    }
}
