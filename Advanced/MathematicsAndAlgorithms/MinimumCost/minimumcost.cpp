#include <iostream>
#include <vector>
#include <fstream>

int minCostPath(const std::vector<std::vector<int>>& cost, std::vector<std::vector<int>>& dp) {
    int rows = cost.size();
    int cols = cost[0].size();
    
    dp.resize(rows, std::vector<int>(cols, 0));
    
    dp[0][0] = cost[0][0];
    
    for (int i = 1; i < rows; ++i) {
        dp[i][0] = dp[i-1][0] + cost[i][0];
    }
    
    for (int j = 1; j < cols; ++j) {
        dp[0][j] = dp[0][j-1] + cost[0][j];
    }
    
    // Fill the dp table (or grid)
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            //Minimum cost to reach cell (i, j) is the minimum of the costs of the cells above and to the left of it.
            //For each cell (i, j), the minimum cost to reach this cell (dp[i][j]) is computed using the following relation:
            dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + cost[i][j];
        }
        //the code efficiently computes the minimum cost path in a grid using dynamic programming, 
        //leveraging previously computed results to build up solutions for larger subproblems until reaching the desired endpoint (rows-1, cols-1).
    }
    
    return dp[rows-1][cols-1];
}

void writeDPTableToFile(const std::vector<std::vector<int>>& dp, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& row : dp) {
        for (const auto& cell : row) {
            file << cell << " ";
        }
        file << "\n";
    }
    file.close();
}

int main() {
    std::vector<std::vector<int>> cost = {
        {1, 3, 5, 8},
        {4, 2, 1, 7},
        {4, 3, 2, 3}
    };
    
    std::vector<std::vector<int>> dp;
    int minCost = minCostPath(cost, dp);
    
    std::cout << "Minimum cost to reach bottom-right corner: " << minCost << std::endl;
    
    //Write the DP table to a file and use the dp_table_visualizer.py script to visualize it
    writeDPTableToFile(dp, "dp_table.txt");
    
    return 0;
}
