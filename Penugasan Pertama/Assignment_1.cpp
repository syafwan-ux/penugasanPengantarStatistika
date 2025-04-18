#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapify(int arr[], int length, int i) {
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < length && arr[left] > arr[max]) {
        max = left;
    }
    if (right < length && arr[right] > arr[max]) {
        max = right;
    }
    if (max != i) {
        swap(arr, i, max);
        heapify(arr, length, max);
    }
}

void heapSort(int arr[], int length) {
    for (int i = length / 2 - 1; i >= 0; i--) {
        heapify(arr, length, i);
    }

    for (int i = length - 1; i > 0; i--) {
        swap(arr, 0, i);
        heapify(arr, i, 0);
    }
}

double calculateMean(int sample[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += sample[i];
    }
    return sum / size;
}

double calculateStandardDeviation(int sample[], int size, double mean) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += pow(sample[i] - mean, 2);
    }
    return sqrt(sum / size);
}

void randomSampling(int arr[], int length, int sampleSize, int numSamples) {
    ofstream meanFile("mean_results.txt", ios::trunc); 
    ofstream stddevFile("stddev_results.txt", ios::trunc); 

   
    if (!meanFile.is_open() || !stddevFile.is_open()) {
        cerr << "Error opening output files!" << endl;
        return;
    }

    srand(time(0)); 

    for (int i = 0; i < numSamples; i++) {
        int* sample = new int[sampleSize]; 
        for (int j = 0; j < sampleSize; j++) {
            int randomIndex = rand() % length; 
            sample[j] = arr[randomIndex];
        }
        double mean = calculateMean(sample, sampleSize);
        double stddev = calculateStandardDeviation(sample, sampleSize, mean);
        meanFile << mean << ",";
        stddevFile << stddev << ",";
        delete[] sample; 
    }

    meanFile.close();
    stddevFile.close();
}

void readDataFromFile(const string& filename, vector<int>& data) {
    ifstream file(filename);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string value;
            while (getline(ss, value, ',')) {
                data.push_back(stoi(value)); 
            }
        }
        file.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }
}

void processData(const string& filename) {
    vector<int> data;
    readDataFromFile(filename, data);

    if (!data.empty()) {
        double mean = calculateMean(data.data(), data.size());
        double stddev = calculateStandardDeviation(data.data(), data.size(), mean);
        cout << "Mean: " << mean << endl;
        cout << "Standard Deviation: " << stddev << endl;
    } else {
        cout << "No data to process." << endl;
    }
}

int main() {
    int arr[] = {
        // data pertama
        153, 157, 161, 165, 173, 164,
        166, 165, 163, 166, 165, 171,        
        169, 159, 163, 166, 165, 175,
        170, 157, 163, 166, 164, 176,
        162, 169
        //data kedua
        //156, 159, 163, 164, 172, 169,       
        //156, 157, 173, 169, 165, 160,        
        //161, 160, 158, 175, 167, 169,
        //161, 162, 170, 156, 161, 172
    };

    int length = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, length);
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    randomSampling(arr, length, 15, 500000);     
                                                
    string filename = "mean_results.txt";       
    string filename2 = "stddev_results.txt";

    cout << "Mean dan Standard Deviation dari 500.000 Data Sampel Mean:" << endl;
    processData(filename);  
    cout << endl;
    cout << "Mean dan Standard Deviation dari 500.000 Data Sampel Std Dev:" << endl;
    processData(filename2);

    return 0;
}
