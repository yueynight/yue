#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

int partition(int array[], size_t arrStart, size_t pivot, size_t arrEnd) {
   int arrayLen = arrEnd - arrStart;

   if ( arrayLen < 1 || pivot < arrStart || pivot >= arrEnd) {
       cout << "Please check your implementation." << endl;
       return -1;
   }
   int pivotValue = array[pivot];
   array[pivot] = array[arrEnd - 1];
   int pivotPos = arrStart;
   int temp;

   for (int i = arrStart; i < arrEnd - 1; ++i)
   {
       if (array[i] < pivotValue) {
          temp = array[pivotPos];
          array[pivotPos] = array[i];
          array[i] = temp;
          ++pivotPos;
       }
   }
   array[arrEnd - 1] = array[pivotPos];
   array[pivotPos] = pivotValue;

   return pivotPos;
}
int findTheK(int array[], size_t arrStart, size_t arrEnd, size_t k) {
    int arrLen = arrEnd - arrStart;
    if (arrLen <= 0 || k <= arrStart || k > arrEnd) {
        cout << "Please check your input." << endl;
        return -1;
    }

    if (arrLen == 1) {
        return array[k - 1];
    } 

    srand(array[array[arrStart] + arrLen + array[arrEnd - 1]]);

    int pivot = arrStart + floor(((arrLen - 1) + (size_t)rand()) % (arrLen - 1));

    int pivotPos = partition(array, arrStart, pivot, arrEnd);

    if (pivotPos + 1 == k) {
        return array[pivotPos];
    }
    else if (pivotPos + 1 < k) {
        return findTheK(array, pivotPos + 1, arrEnd, k);
    }
    else {
        return findTheK(array, arrStart, pivotPos, k);
    }

}

void printArray(int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
    int array0[] = {};
    int arrayLen = sizeof(array0)/sizeof(int);

    printArray(array0, arrayLen);
    cout << "0: "<< findTheK(array0, 0, arrayLen, 0) << endl;

    cout << "=========================================" << endl;

    int array1[] = {1};
    arrayLen = sizeof(array1)/sizeof(int);

    printArray(array1, arrayLen);
    cout << "1: "<< findTheK(array1, 0, arrayLen, 1) << endl;

    cout << "=========================================" << endl;

    int array2[] = {2, 1};
    arrayLen = sizeof(array2)/sizeof(int);

    printArray(array2, arrayLen);
    cout << "1: " << findTheK(array2, 0, arrayLen, 1) << endl;
    cout << "2: " << findTheK(array2, 0, arrayLen, 2) << endl;

    cout << "=========================================" << endl;

    int array3[] = {1, 5, 3};
    arrayLen = sizeof(array3)/sizeof(int);

    printArray(array3, arrayLen);
    cout << "1: "<< findTheK(array3, 0, arrayLen, 1) << endl;
    cout << "3: "<< findTheK(array3, 0, arrayLen, 3) << endl;

    cout << "=========================================" << endl;

    int array4[] = {9, 12, 8, 7};
    arrayLen = sizeof(array4)/sizeof(int);

    printArray(array4, arrayLen);
    cout << "1: "<< findTheK(array4, 0, arrayLen, 1) << endl;
    cout << "3: "<< findTheK(array4, 0, arrayLen, 3) << endl;

    cout << "=========================================" << endl;

    int array5[] = {9, 12, 8, 7, 3};
    arrayLen = sizeof(array5)/sizeof(int);

    printArray(array5, arrayLen);
    cout << "1: "<< findTheK(array5, 0, arrayLen, 1) << endl;
    cout << "4: "<< findTheK(array5, 0, arrayLen, 4) << endl;

    cout << "=========================================" << endl;


}