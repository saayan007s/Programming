import java.util.*;
public class Othello {

    public static void main(String [] args) {
        Othello test = new Othello();
        test.printBoard();
    }
    int[][] board = new int[9][9]; // board
    int player; // current player
    boolean playable; // valid move available
    int score; // score of the game

    public Othello() {
        board[4][4] = board[5][5] = 1;
        board[5][4] = board[4][5] = -1;

        player = 1;
        score = 0;
    }

    public boolean noMoves(int cur) {
        return false;
    }

    public boolean noMoves() {
        return noMoves(player);
    }

    public void changePlayer() {
        player = 1 - player;
    }

    public void startGame() {
        int turns = 60;
        while(turns-- > 0) {
            if(noMoves()) {
                if(!noMoves(1 - player)) {
                    System.out.printf("Player '%c' does not have any legal moves\nIt is again '%c's move\n",(player==1?'+':'-'),(player!=1?'+':'-'));
                    changePlayer();
                }  else {
                    endGame();
                }
            } else {
                int in = scan.nextInt();
                if(X == -1) {
                    showGameData();
                    turns++
                } else {
                    int Y = in / 10;
                    int X = in % 10;
                    if(X > 8 || X < 1 || Y > 8 || Y < 1)
                    {
                        System.out.printf("That move is illegal\nIt is not on the board\n");
                        turns++;
                    }
                    else if(board[X][Y] != 0)
                    {
                        System.out.printf("That move is illegal\nThat place is occupied\n");
                        turns++;
                    }
                    else {
                        boolean legal = makeMove(X, Y);
                        if(!legal) {
                            undoMove(X, Y);
                            System.out.printf("That move is illegal\nIt does not flip any other coins\n");
                            turns++;
                        }
                        else {
                            printBoard();
                        }
                    }
                }
            }
        }

        endGame();
    }

    // prints the board
    public void printBoard() {
        System.out.printf("\n    ");

        for (int i = 1; i < 9; i++)
            System.out.printf("%d  ", (i));
        System.out.printf("\n\n");

        String[] temp = {"-  ","O  ","+  "};

        for (int i = 1; i < 9; i++) {
            System.out.printf("%d   ", (i + 1));
            for (int j = 1; j < 9; j++) {
                System.out.printf(temp[board[i][j] + 1]);
            }
            System.out.printf("\n");
        }
        System.out.printf("\n");
    }
}
