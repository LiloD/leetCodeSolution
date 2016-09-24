#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solve(vector<vector<char>>& board);
bool inEdge(int x, int y, int w, int h);
void dfs(vector<vector<char>>& board, int x, int y, int w, int h, vector<vector<int>> &marked, bool &isSurrounded);

void solve(vector<vector<char>>& board) {
    //check edge case
    if(board.size() == 0 || board[0].size() == 0)
        return;
    
    int w = board.size();
    int h = board[0].size();

    vector<vector<int>> marked(w, vector<int>(h, 0));

    for(int i = 0; i < w; ++i){
        for(int j = 0; j < h; ++j){
            if(board[i][j] == 'O' && marked[i][j] == 0){
                bool isSurrounded = true;
                dfs(board, i, j, w, h, marked, isSurrounded);
                for(int x = 0; x < w; ++x){
                    for(int y = 0; y < h; ++y){
                        if(marked[x][y] == 2){
                            marked[x][y] = 1;
                            if(isSurrounded){
                                board[x][y] = 'X';
                            }
                        }
                    }
                }   
            }
        }
    }
}

bool inEdge(int x, int y, int w, int h){
    return x == 0 || x == (w-1) || y == 0 || y == (h-1);
}


void dfs(vector<vector<char>>& board, int x, int y, int w, int h, vector<vector<int>> &marked, bool &isSurrounded){
    stack<pair<int, int>> s;
    s.push({x, y});
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!s.empty()){
        auto current = s.top();
        s.pop();
        
        int cx = current.first;
        int cy = current.second;
        marked[cx][cy] = 2;
        if(inEdge(cx, cy, w, h)){
            isSurrounded = false;
        }

        for(auto d : directions){
            int nx = cx + d[0];
            int ny = cy + d[1];

            //check if it's valid
            if(nx >= 0 && nx < w && ny >= 0 && ny < h && board[nx][ny] == 'O' && marked[nx][ny] == 0){
                s.push({nx, ny});
            }
        }
    }
}

int main(){
    return 0;
}