
// tic-tac-toe
#include<bits/stdc++.h>
using namespace std;

// game layout

char game[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,col;
char turn ='X';
bool draw = false;
int choice;

//func for showing status of game after each turn 
void game_display()
{
    //game layout
    cout<<"PLAYER-1 -> X \n";
    cout<<"PLAYER-2 -> O \n";

    cout<<"     |       |       \n";
    cout<<"  "<<game[0][0]<<"  |   "<<game[0][1]<<"   |   "<<game[0][2]<<"  \n";
    cout<<"-----|-------|-------\n";
    cout<<"     |       |       \n";
    cout<<"  "<<game[1][0]<<"  |   "<<game[1][1]<<"   |   "<<game[1][2]<<"  \n";
    cout<<"-----|-------|-------\n";
    cout<<"     |       |       \n";
    cout<<"  "<<game[2][0]<<"  |   "<<game[2][1]<<"   |   "<<game[2][2]<<"  \n";
    cout<<"     |       |      \n";

}

//func to user mark user input
void play_game(){
    if(turn=='X')
    {
        cout<<"Player-1 turn : \n";
    }
    else if(turn=='O')
    {
        cout<<"Player-2 turn : \n";
    }
    cin>>choice;

  //switch case to find row ,col to update
    switch(choice)
    {
        case 1: row=0;col=0;break;
        case 2: row=0;col=1;break;
        case 3: row=0;col=2;break;
        case 4: row=1;col=0;break;
        case 5: row=1;col=1;break;
        case 6: row=1;col=2;break;
        case 7: row=2;col=0;break;
        case 8: row=2;col=1;break;
        case 9: row=2;col=2;break;
        default: cout<<"please enter a valid number";
    }
    //updating respective postion with X or o after checking availability
    if(turn=='X' and game[row][col]!='X' and game[row][col]!='O')
    {
        game[row][col]='X';
        turn = 'O';

    }
    else if(turn=='O' and game[row][col]!='X' and game[row][col]!='O')
    {
        game[row][col]='O';
        turn = 'X';
    }
    else{
        cout<<"This Move already taken!! Please choose another Move \n";
        play_game();
    }
    game_display();

}

//func to check whether game is over or not
bool game_status()
{
    //checking whether the values matches along all 3 row or cols
    for(int i=0;i<3;i++)
    {
        if(game[i][0]==game[i][1] and game[i][0]==game[i][2] or game[0][i]==game[1][i] and game[0][i]==game[2][i])
        {
            return false;
        }
        //win check for diagonals
        if(game[0][0]==game[1][1] and game[0][0]==game[2][2] or game[0][2]==game[1][1] and game[0][2]==game[2][0])
        {
            return false;
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(game[i][j]!='X' and game[i][j]!='O') return true;
            }
        }

        draw = true;
        return false;

    }
}

int main()
{
    cout<<"<---WELCOME--->\n";
    cout<<"Tic -- Tac -- Toe\n";
    while(game_status())
    {
        game_display();
        play_game();
        game_status();
    }
    if(turn == 'X' and draw==false)
    {
        cout<<"player-1 won the match\n";
    }
    else if(turn =='O' and draw==false)
    {
        cout<<"player-2 won the match\n";
    }
    else{
        cout<<"Game Draw\n";
    }
}