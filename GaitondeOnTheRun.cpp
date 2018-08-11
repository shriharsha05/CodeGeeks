#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Cell {
    int x, y;          
    int cost;          
    int t_cost;        
    Cell(int x, int y, int c, int t_c):x(x), y(y), cost(c), t_cost(t_c){}; 
};

class Grid {
    vector<vector<Cell*>> grid;
    int rows,cols;
    
    public:
    
        Grid(int rows, int cols) {
            this->rows = rows;
            this->cols = cols;
        }

        void readInputGrid() {
            for(int i=0; i<rows; i++) {
                int cost; 
                int t_cost = -1; 
                vector<Cell*> row_vec; 
                for(int j=0; j<cols; j++) {
                    cin >> cost;
                    if (i==0) t_cost = cost; 
                    row_vec.push_back(new Cell(i, j, cost, t_cost));
                }
                grid.push_back(row_vec);   
            }
        }
        
        bool isInsideGrid(int i, int j) {
        return (i >= 0 && i < rows && j >= 0 && j < cols);
        }
        
        int minCost() {
            int min_cost=INT_MAX;
            bool converge = false;
        
            int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
            int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
            
            while(!converge) {
                converge = true;
                
                if(rows==1) {
                    for(int j=0; j<cols; j++) {
                        min_cost = min(min_cost, grid[0][j]->t_cost);
                    }
                    continue;
                }
                
                for(int i=1; i<rows; i++) {
                    for(int j=0; j<cols; j++) {
                        for(int k=0; k<8; k++) {
                            Cell* curr = grid[i][j];
                            
                            int x = curr->x + dx[k];
                            int y = curr->y + dy[k];

                            if(!isInsideGrid(x,y)) continue;
                            Cell* adj = grid[x][y];

                            if(adj->t_cost == -1) continue;
                            
                            if(curr->t_cost == -1 || 
                               curr->t_cost > curr->cost + adj->t_cost) {
                                curr->t_cost = curr->cost + adj->t_cost;
                                if(i==rows-1) min_cost = min(min_cost, curr->t_cost);
                                converge = false; 
                            }
                        }
                    }
                }
            }
            return min_cost;
        }
        
        void printTotalCostGrid() {
            for(int i=0; i<rows; i++) {
                for(int j=0; j<cols; j++) {
                    cout << grid[i][j]->t_cost << " ";
                }
            cout << endl;
            }
        }
};

int main() {
    int Testcases, rows, cols;
    cin >> Testcases;
    while (Testcases-- > 0) {
        cin >> rows >> cols;
        Grid g(rows,cols);
        g.readInputGrid();
        cout << g.minCost() << endl;
    }
	return 0;
}