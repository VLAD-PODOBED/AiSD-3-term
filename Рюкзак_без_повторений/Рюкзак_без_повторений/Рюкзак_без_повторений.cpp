#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

int o_w(int W, const vector<int>& w) {
    vector<int> c(W + 1);
    for (size_t i = 0; i < w.size(); ++i) {
        for (int j = W; j - w[i] >= 0; --j) {
            c[j] = std::max(c[j], c[j - w[i]] + w[i]);
        }
    }
    return c[W];
}

int opti_w(int W, const std::vector<int>& w, int n) {
    std::vector<std::vector<int>> value(n + 1, vector<int>(W + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            std::cout << value[i][j] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            //value[j][i]=std::max(value[j][i-1],value[j-w[i]][i-1]+w[i]);
            std::cout << "i:" << i << " j:" << j << "\n";
            std::cout << "value[i][j]:" << value[i][j] << "\n";
            std::cout << "value[i-1][j]:" << value[i - 1][j] << "\n";
            std::cout << "w[i-1]:" << w[i - 1] << "\n";
            std::cout << "value[i-1][j-w[i-1]]:" << value[i - 1][j - w[i - 1]] << "\n";
            std::cout << "value[i-1][j-w[i-1]]+w[i-1]:" << value[i - 1][j - w[i - 1]] + w[i - 1] << "\n";
            value[i][j] = std::max(value[i - 1][j], value[i - 1][j - w[i - 1]] + w[i - 1]);
        }
    }






    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            std::cout << value[i][j] << " ";
        }
        std::cout << "\n";
    }

    return value[n][W];
    // return value[W][n];
}

int main() {
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    std::cout << opti_w(W, w, n);
    //std::cout << o_w(W, w) << '\n';
}