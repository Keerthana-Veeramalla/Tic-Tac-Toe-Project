#include<iostream>
#include<vector>
using namespace std;

class game {
public:
    // for printing the the diagram...
    void showBoard(vector<vector<char>> &grid) 
    {
        cout << "-------------\n";
        for (int i = 0; i < 3; i++) 
        {
            cout << "| ";
            for (int j = 0; j < 3; j++) 
            {
                cout << grid[i][j] << " | ";
            }
            cout << "\n-------------\n";
        }
    }

    // to check whether it's a valid move or not
    bool validmove(pair<int, int> move, vector<vector<char>> &grid) 
    {
        int row = move.first;
        int col = move.second;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && grid[row][col] == ' ') 
        {
            return true;
        } 
        else 
        {
            cout << "Try again!!\n";
            return false;
        }
    }

    // switch player from X to O or O to X
    char switchplayer(char current) 
    {
        if (current == 'X')
            return 'O';
        else
            return 'X';
    }


    // to take user input for position of move
    pair<int, int> askformove(char current) 
    {
        int row, column;
        cout << "Player " << current << ", enter your move (row and column number 1-3 respectively): ";
        cin >> row >> column;
        return {row - 1, column - 1};  // convert to 0-based index
    }

    // to place player's move
    void markmove(vector<vector<char>> &grid, pair<int, int> move, char current) 
    {
        grid[move.first][move.second] = current;
    }

    // to check if the current player win or not
    bool haswin(vector<vector<char>> &grid, char current) 
    {
        // to check rows and coloumns
        for (int i = 0; i < 3; i++) 
        {
            if (grid[i][0] == current && grid[i][1] == current && grid[i][2] == current) return true;
            if (grid[0][i] == current && grid[1][i] == current && grid[2][i] == current) return true;
        }

        //to check for diagonals
        if (grid[0][0] == current && grid[1][1] == current && grid[2][2] == current) return true;
        if (grid[0][2] == current && grid[1][1] == current && grid[2][0] == current) return true;

        return false;
    }

    //to check if the game is a draw or not
    bool hasdraw(vector<vector<char>> &grid) 
    {
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                if (grid[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> grid(3, vector<char>(3, ' '));
    game g;

    char current = 'X';

    cout << "Welcome to Tic Tac Toe game!\n";

    while (true) 
    {
        g.showBoard(grid);
        pair<int, int> move = g.askformove(current);

        if (!g.validmove(move, grid)) 
        {
            continue; // invalid move, ask again
        }

        g.markmove(grid, move, current);

        if (g.haswin(grid, current)) 
        {
            g.showBoard(grid);
            cout << "Player " << current << " is the winner!\n";
            break;
        }

        if (g.hasdraw(grid)) 
        {
            g.showBoard(grid);
            cout << "It's a draw!!!\n";
            break;
        }

        current = g.switchplayer(current); // to switch to the other player
    }

    return 0;
}
