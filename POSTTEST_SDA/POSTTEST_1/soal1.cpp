#include <iostream>
using namespace std;

int FindMin(int A[], int n){
    int min = A[0];
    for (int i = 1; i <= n - 1 ; i++){
        if (A[i] < min){
            min = A[i];
            // Hasil analisis kompleksitas waktu:
            // Best Case: Tmin(n) = 2n-1 membentuk fungsi linear, maka Big-O => O(n)
            // Worst Case: Tmax(n) = 3n juga membentuk fungsi linear, maka Big-O => O(n)
        }
    }
    return min;
}

int FindMinIndex(int A[], int n){
    int min = A[0];
    int index = 0;
    for (int i = 1; i <= n - 1 ; i++){
        if (A[i] < min){
            min = A[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int A[] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;
    cout << "=== Soal 1 ===" << endl;
    cout << "FIbonacci Array : [ ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << "]" << endl;
    
    cout << "Nilai Minimum : " << FindMin(A, n)<< endl;
    cout << "Dengan indeks ke- " << FindMinIndex(A, n) << endl;
    
    return 0;
}