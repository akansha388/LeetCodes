class Solution {
public:

    bool solve(vector<vector<char>>& board)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char num = '1'; num <= '9'; num++)
                    {
                        bool valid = true;
                        for(int k = 0; k < 9; k++)
                        {
                            if(board[i][k] == num)
                            {
                                valid = false;
                                break;
                            }
                        }
                        if(valid)
                        {
                            for(int k = 0; k < 9; k++)
                            {
                                if(board[k][j] == num)
                                {
                                    valid = false;
                                    break;
                                }
                            }
                        }
                        if(valid)
                        {
                            int startRow = (i / 3) * 3;
                            int startCol = (j / 3) * 3;
                            for(int r = startRow; r < startRow + 3; r++)
                            {
                                for(int c = startCol; c < startCol + 3; c++)
                                {
                                    if(board[r][c] == num)
                                    {
                                        valid = false;
                                        break;
                                    }
                                }
                                if(!valid)
                                    break;
                            }
                        }
                        if(valid)
                        {
                            board[i][j] = num;
                            if(solve(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        solve(board);
    }
};