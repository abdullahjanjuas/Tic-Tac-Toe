#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'}};

int turn = 1;
int choice;
int row, col;

void display() 
{    
    for (int i = 0; i < 3; i++) {
    	if (i <= 2)
            cout << " -------------" << endl;
			        
        for (int j = 0; j < 3; j++) 
		{
			if (j <= 2) 
                cout << " | ";
            cout << board[i][j];           
			if (j == 2) 
                cout << " | ";             
        }
        cout << endl;
        if (i == 2)
            cout << " -------------" << endl;
    }
    cout << endl;
}

bool valid() 
{
	char ch = '1'+choice-1;
    return (choice >= 1 && choice <= 9 && board[row][col] == ch );
}

bool win() 
{
    return (board[row][0] == board[row][1] && board[row][1] == board[row][2]) ||
        (board[0][col] == board[1][col] && board[1][col] == board[2][col]) ||
        (board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]);
}

bool draw() 
{
    for (int i = 0; i < 3; i++) 
	{
        for (int j = 0; j < 3; j++) 
		{
            if (!(board[i][j] == 'X' || board[i][j] == 'O')) 
                return 0;          
        }
    }
    return 1;
}


int main() 
{
	cout << "Tic Tac Toe" << endl;
    do {
        display();
        turn = (turn % 2) ? 1 : 2;
        cout << "Player " << turn << "  Enter a number: ";
        cin >> choice;

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if (valid()) 
		{
            board[row][col] = (turn == 1) ? 'X' : 'O';

            if (win()) 
			{
                display();
                cout << "Player " << turn << " WINS!" << endl;
                break;
            }

            else if (draw()) 
			{
                display();
                cout << "It's a Draw!" << endl;
                break;
            }

            turn++;
        } 
		else 
            cout << endl << "Invalid Entry!" << endl << endl;        

    } while (1);

    return 0;
}