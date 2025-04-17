#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream> 
using namespace std;

double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }  
}

double combinatorial(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

void binomial(double p, int n, int k, ofstream &outputFile) { 
    long double q = 1 - p;
    long double result = combinatorial(n, k) * pow(p, k) * pow(q, n - k);
    outputFile << "P(X = " << k << ") = " << fixed << setprecision(10) << result << endl; 
}

int main() {
    double totalStudent = 10678;
    double SNBPStudent = 2821;
    double p = SNBPStudent/totalStudent;

    ofstream outputFile("output.txt"); 
    if (!outputFile) {
        cerr << "Error opening file!" << endl;
        return 1; 
    }

    for (int i = 0; i <= 50; i++) {        
        binomial(p, 50, i, outputFile);   
    }

    outputFile.close(); 
}
