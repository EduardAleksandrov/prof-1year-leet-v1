/*
    1275. Find Winner on a Tic Tac Toe Game
    
    Tic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:

    Players take turns placing characters into empty squares ' '.
    The first player A always places 'X' characters, while the second player B always places 'O' characters.
    'X' and 'O' characters are always placed into empty squares, never on filled ones.
    The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
    The game also ends if all squares are non-empty.
    No more moves can be played if the game is over.
    Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the ith move will be played on grid[rowi][coli]. return the winner of the game if it exists (A or B). In case the game ends in a draw return "Draw". If there are still movements to play return "Pending".

    You can assume that moves is valid (i.e., it follows the rules of Tic-Tac-Toe), the grid is initially empty, and A will play first.

    Done
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;


class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        std::vector<std::vector<string>> table(3, std::vector<string>(3, "0"));
        for(int i = 0; i < moves.size(); i++)
        {
            int x = moves[i][0];
            int y = moves[i][1];
            if(i % 2 == 0) table[x][y] = "A";
            else table[x][y] = "B";
        }
        for(int i = 0; i < moves.size(); i++)
        {
            int x = moves[i][0];
            int y = moves[i][1];
            
            if(i % 2 == 0)
            {
                int count1{0}, count2{0}, count3{0}, count4{0};
                for(int n = 0; n < 3; n++)
                {
                    if(table[x][n] == "A") count1++;
                    if(table[n][y] == "A") count2++;
                    if(table[n][n] == "A") count3++;
                    if(table[n][2-n] == "A") count4++;
                }
                if(count1 == 3 || count2 == 3 || count3 == 3 || count4 == 3) return "A";
            } else {
                int count1{0}, count2{0}, count3{0}, count4{0};
                for(int n = 0; n < 3; n++)
                {
                    if(table[x][n] == "B") count1++;
                    if(table[n][y] == "B") count2++;
                    if(table[n][n] == "B") count3++;
                    if(table[n][2-n] == "B") count4++;
                }
                if(count1 == 3 || count2 == 3 || count3 == 3 || count4 == 3) return "B";
            } 
        }
        if(moves.size() == 9) return "Draw";
        else return "Pending";
    }
};



int main()
{
    Solution Sol;
    vector<vector<int>> moves = {{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}};
    string result = Sol.tictactoe(moves);
    cout << result << endl;
    return 0;
}