#include<stdio.h>

void system();
void grid(char board[]){
    system("cls");
    printf("\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[1],board[2],board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[4],board[5],board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[7],board[8],board[9]);
    printf("     |     |     \n");

    return;
}
int checking_win(char board[]){
    if(board[1]==board[2] && board[2]==board[3]) return 1;
    if(board[4]==board[5] && board[5]==board[6]) return 1;
    if(board[7]==board[8] && board[8]==board[9]) return 1;
    if(board[1]==board[4] && board[4]==board[7]) return 1;
    if(board[2]==board[5] && board[5]==board[8]) return 1;
    if(board[3]==board[6] && board[6]==board[9]) return 1;
    if(board[1]==board[5] && board[5]==board[9]) return 1;
    if(board[3]==board[5] && board[5]==board[7]) return 1;
    
    return -1;
}

int main(){
    printf("\nWelcome......\n");
    printf("=== TIC TAC TOE ===\n\n");
    char board[]={'0','1','2','3','4','5','6','7','8','9'};
    grid(board);

    int player=1,move,count=0;
    char mark;
    while(1){
        printf("Player %d,Enter moves (1-9): ",player);
        scanf("%d",&move);
        mark = (player==1)?'X':'O';

        if(move<1 || move>9){
            printf("Invalid moves, re-enter move.\n");
            continue;
        }
        if(board[move]=='X' || board[move]=='O'){
            printf("Entered move is occupied,please re-enter move.\n");
            continue;
        }
        board[move]=mark;
        count++;
        grid(board);

        if(checking_win(board)==1){
            printf("Player %d is winner!\n",player);
            break;
        }
        else if(count==9){
            printf("Match is drawn!\n");
            break;
        }
        player = (player==1)?2:1;
    }

    return 0;
}