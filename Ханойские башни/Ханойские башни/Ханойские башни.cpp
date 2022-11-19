#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

double fi(double x) {
    const double factor = 0.39894228040143267793994605993438;   // == 1 / sqrt(2 * pi)
    return factor * exp(-(x * x) / 2);
}

double Laplace(double p, int n, int k) {
    double q = 1 - p;
    double sqrt_npq = sqrt(n * p * q);
    double x = (k - n * p) / sqrt_npq;
    return fi(x) / sqrt_npq;
}

double binom(int n, int k) {
    double c = 1.0;
    for (int i = n - k + 1; i <= n; ++i)
        c *= i;
    for (int i = 2; i <= k; ++i)
        c /= i;
    return c;
}

double Bernoulli(double p, int n, int k) {
    return binom(n, k) * pow(p, k) * pow(1 - p, n - k);
}

int main() {
    const char sep = ',';
    int n = 100;
    double p = 0.5;
    double ber, lapl;
    ofstream csv("probability.csv");

    if (csv)
        csv << "k" << sep << "Bernoulli" << sep << "Laplace" << sep << "delta" << sep << "\"delta, %\"" << endl;
    cout
        << "+-----+------------------+------------------+------------------+-------------------+\n"
        << "|  k  |    Bernoulli     |      Laplace     |       delta      |      delta, %     |\n"
        << "+-----+------------------+------------------+------------------+-------------------+\n";

    for (int i = 1; i <= n; ++i) {
        ber = Bernoulli(p, n, i);
        lapl = Laplace(p, n, i);
        cout << "| " << setw(3) << i << " | " << scientific << setprecision(6)
            << setw(16) << ber << " | "
            << setw(16) << lapl << " | "
            << setw(16) << ber - lapl << " | "
            << setw(16) << fixed << setprecision(3) << abs(ber - lapl) / ber * 100 << "% |"
            << endl;
        if (csv)
            csv << scientific << setprecision(6)
            << i << sep
            << ber << sep
            << lapl << sep
            << ber - lapl << sep
            << abs(ber - lapl) / ber * 100
            << endl;
    }
    cout
        << "+-----+------------------+------------------+------------------+-------------------+\n"
        << endl;
}