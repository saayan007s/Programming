#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ANSI_COLOR_BLACK    "\x1b[30m"
#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_BLUE  "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define f(i,a,b) for(int i = a; i < b; i++)
#define fd(i,a,b) for (int i = a; i>=b; i--)
#define F first 
#define S second 
#define PB push_back
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define pll pair<long,long>
#define nl '\n'
#define vi vector<int>
typedef long long ll;

/*  checks if any more legal moves left */
bool check_game(int curr, int board[8][8])
{
    pii dir[8] ={{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1}};
    f(i,0,8)
    {
        f(j,0,8)
        {
            if(board[i][j] != 0)
                continue;
            int X = i;
            int Y = j;
            bool legal = 0;
            for(pii u : dir)
            {
                /*  in each direction */
                int x,y;
                int a = u.F;
                int b = u.S;
                if(a == 0 && b == 0)
                    continue;
                x = X + a;
                y = Y + b;
                bool found = 0;

                while(x<8 && x>-1 && y<8 && y>-1)
                {
                    if(board[x][y] != -curr)
                    {
                        found = 1;
                        break; 
                    }
                    x += a;
                    y += b;
                }

                if(found)
                if(board[x][y] == curr)
                {
                    if(x-a != X || y-b != Y)
                        return true;
                }
            }
        }
    }
    return false;
}

/*  prints board */
void pr(int board[8][8])
{
    printf("\n    ");
    f(i,1,9)
        printf("%d  ",(i));
    printf("\n\n");
    f(i,0,8)
    {
        printf("%d   ",(i+1));
        f(j,0,8)
        {
            if (board[i][j] == 0)
                printf(ANSI_COLOR_BLACK "O  " ANSI_COLOR_RESET);
            else if (board[i][j] == 1)
                printf(ANSI_COLOR_RED "+  " ANSI_COLOR_RESET);
            else 
                printf(ANSI_COLOR_BLUE "-  " ANSI_COLOR_RESET);

            // comment out the above lines and uncomment the ones below and uncomment the ones below if the output is weird
            // if (board[i][j] == 0)
            //     printf("O  ");
            // else if (board[i][j] == 1)
            //     printf("+  ");
            // else 
            //     printf("-  ");
        }
        printf("\n");
    }
    printf("\n");
}

void play()
{
    /*  setting up the board */
    int board[8][8];
    f(i,0,8)
        f(j,0,8)
            board[i][j] = 0;
    board[3][3] = board[4][4] = 1;
    board[3][4] = board[4][3] = -1;
    pr(board);
    int turns = 60;
    pii dir[8] ={{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1}};
    int score = 0;
    bool over = 0;

    /*playing each turn */
    while((turns--))
    {
        int curr = (turns&1?1:-1);
        if(!check_game(curr,board))
        {
            if(over)
            {
                printf("No more moves possible\n");
                break;
            }
            else
            {
                over = 1;
                printf("Player '%c' does not have any legal moves\nIt is again '%c's move\n",(curr==1?'+':'-'),(curr!=1?'+':'-'));
                continue;
            }
        }
        else
            over = 0;
        int X,Y;
        scanf("%d",&X);
        
        /*  info about the game */
        if(X == -1)
        {
            char cmd;
            scanf("%c",&cmd);
            printf("Score is %c%d\n",(score>0?'+':(score<0?'-':'=')),abs(score));
            printf("%d turns left\n",(turns+1));
            printf("It is '%c's turn\n",(curr==1?'+':'-'));
            pr(board);
            turns++;
            continue;
            
        }
        /*  coordinates of play */
        else if(X != -1)
        {
            Y = X%10;
            X /= 10;
            X--; Y--;
        }

        /*  checking if coordinates are okay*/
        if(X>7 || X<0 || Y>7 || Y<0)
        {
            printf("That move is illegal\nIt is not on the board\n");
            turns++;
            continue;
        }
        else if(board[X][Y] != 0)
        {
            printf("That move is illegal\nThat place is occupied\n");
            turns++;
            continue;
        }


        /*  checking which coins to flip */
        board[X][Y] = curr;
        score += curr;
        bool legal = 0;
        for(pii u : dir)
        {
            /*  in each direction */
            int x,y;
            int a = u.F;
            int b = u.S;
            if(a == 0 && b == 0)
                continue;
            x = X + a;
            y = Y + b;
            bool found = 0;

            while(x<8 && x>-1 && y<8 && y>-1)
            {
                if(board[x][y] != -curr)
                {
                    found = 1;
                    break; 
                }
                x += a;
                y += b;
            }

            if(found)
            if(board[x][y] == curr)
            {
                a = (-a);
                b = (-b);
                x += a;
                y += b;
                if(x != X || y != Y)
                    legal = 1;
                
                while(x!=X || y!=Y)
                {
                    board[x][y] = curr;
                    score += (2*curr);
                    x += a;
                    y += b;
                }
            }
        }
        
        /*  move is legal we go on to next turn */
        if(legal)
            pr(board);
        else
        {
            score -= curr;
            board[X][Y] = 0;
            printf("That move is illegal\nIt does not flip any other place\n");
            turns++;
        }
    }

    /*  Finally print the score */
    if(score > 0)
        printf("Player '+' won the game by a difference of %d",abs(score));
    else if(score < 0)
        printf("Player '-' won the game by a difference of %d",abs(score));
    else
        printf("Game was drawn");
}

int main()
{
    play();
}
