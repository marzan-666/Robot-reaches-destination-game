#include<stdio.h>

void clearScreen(int CS[10][10]);

int main(){
    int game[10][10];
    int i,j;
    int r=0,c=0;

    char move;

    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            game[i][j]=0;
        }
    }
    game[0][1]=5;
    game[0][4]=5;
    game[2][5]=5;
    game[3][0]=5;
    game[4][4]=5;
    game[4][5]=5;
    game[4][9]=5;
    game[5][1]=5;
    game[5][4]=5;
    game[5][5]=5;
    game[6][8]=5;
    game[9][0]=5;
    game[9][4]=5;

    game[0][7]=-1;
    game[2][1]=-1;
    game[2][9]=-1;
    game[3][3]=-1;
    game[4][7]=-1;
    game[6][3]=-1;
    game[7][0]=-1;
    game[7][6]=-1;
    game[9][7]=-1;

    game[0][0]=1;
    game[9][9]=9;
    printf("To start the Game press any key. . . . \n");
    getch();
    clearScreen(game);

    for(i=1;i<=20;i++){
        printf("\n\nThe Rules of the Game:\n--UP = U/u --- DOWN = D/d --- LEFT = L/l --- RIGHT = R/r--\n\n");
        fflush(stdin);

        printf("Your Move: ");
        scanf("%c",&move);

        if(move=='U' || move=='u'){
            if(r==0){
                clearScreen(game);
                printf("\n\nYou cant go up\n");
            }
            else{
                r--;
                if(game[r][c]==5){
                    i--;
                    r++;
                    clearScreen(game);
                    printf("\nYou have to go side by the walls\n");
                    continue;
                }
                else if(game[r][c]==-1){
                    printf("\nBOOOOOOOOOOOOOOM\n");
                    break;
                }
                else{
                    game[r][c]=1;
                    clearScreen(game);
                }
            }
        }
        else if(move=='D'|| move=='d'){
            if(r==9){
                clearScreen(game);
                printf("\n\nYou can't go down\n");
            }
            else{
                r++;
                if(game[r][c]==5){
                    i--;
                    r--;
                    clearScreen(game);
                    printf("\nYou have to go side by the walls\n");
                    continue;
                }
                else if(game[r][c]==-1){
                    printf("\nBOOOOOOOOOOOOOOM\n");
                    break;
                }
                else{
                    game[r][c]=1;
                    clearScreen(game);
                }
            }
        }
        else if(move=='L'|| move=='l'){
            if(c==0){
                clearScreen(game);
                printf("\n\nYou can't go Left\n");
            }
            else{
                c--;
                if(game[r][c]==5){
                    i--;
                    c++;
                    clearScreen(game);
                    printf("\nYou have to go side by the walls\n");
                    continue;
                }
                else if(game[r][c]==-1){
                    printf("\nBOOOOOOOOOOOOOOM\n");
                    break;
                }
                else{
                    game[r][c]=1;
                    clearScreen(game);
                }
            }
        }
        else if(move=='R'|| move=='r'){
            if(c==9){
                clearScreen(game);
                printf("\n\nYou can't go Right\n");
            }
            else{
                c++;
                if(game[r][c]==5){
                    i--;
                    c--;
                    clearScreen(game);
                    printf("\nYou have to go side by the walls\n");
                    continue;
                }
                else if(game[r][c]==-1){
                    printf("\nBOOOOOOOOOOOOOOM\n");
                    break;
                }
                else{
                    game[r][c]=1;
                    clearScreen(game);
                }
            }
        }
        else{
            i--;
            clearScreen(game);
            printf("\nWrong Move\n");
        }
        if(game[9][9]==1){
            break;
        }

    }
    if(game[9][9]==1){
        printf("\n\n--Robot reaches Destination--\n--User Wins--\n");
    }
    else{
        printf("\n\n--All 15 steps are done before reaching destination--\n---Game Over---\n");
    }
    return 0;
}

void clearScreen(int CS[10][10]){
    system("cls");
    int i,j;
    for(i=0;i<10;i++){
        printf("\n");
        for(j=0;j<10;j++){
            if(CS[i][j] == 1){
                printf("  R");
            }
            else if(CS[i][j] == 9){
                printf("  D");
            }
            else{
                printf("%3d",CS[i][j]);
            }
            }
    }
}
