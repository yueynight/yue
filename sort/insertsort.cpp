#include <iostream>
#include <math.h>

using namespace std;

bool insertSort(int array[], size_t arrLen) {
    if (arrLen < 0) {
        cout << "Please check your input." << endl;
        return false;
    }

    for (int orderedNum = 1; orderedNum < arrLen; ++orderedNum) {
        int insertValue = array[orderedNum];
        int orderedIndex = orderedNum - 1;
        for (; orderedIndex >= 0; --orderedIndex) {
            if (insertValue < array[orderedIndex]) {
                array[orderedIndex + 1] = array[orderedIndex];
            }
            else {
                break;
            }
        }
        array[orderedIndex+1] = insertValue;
    }

    return true;
}

bool insertSort_Sen(int array[], size_t arrLen) {
     if (arrLen < 0) {
        cout << "Please check your input." << endl;
        return false;
    }

    for (int orderedNum = 1; orderedNum < arrLen; ++orderedNum) {
        int insertValue = array[orderedNum];
        int orderedIndex = orderedNum - 1;
        while(orderedIndex >=0 && array[orderedIndex] > insertValue) {
           array[orderedIndex + 1] = array[orderedIndex];
           --orderedIndex;
        }
        array[orderedIndex+1] = insertValue;
    }

    return true;
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
    insertSort(array0, arrayLen);
    printArray(array0, arrayLen);

    cout << "=========================================" << endl;

    int array1[] = {1};
    arrayLen = sizeof(array1)/sizeof(int);

    printArray(array1, arrayLen);
    insertSort_Sen(array1, arrayLen);
    printArray(array1, arrayLen);

    cout << "=========================================" << endl;

    int array2[] = {2, 1};
    arrayLen = sizeof(array2)/sizeof(int);

    printArray(array2, arrayLen);
    insertSort(array2, arrayLen);
    printArray(array2, arrayLen);

    cout << "=========================================" << endl;

    int array3[] = {1, 5, 3};
    arrayLen = sizeof(array3)/sizeof(int);

    printArray(array3, arrayLen);
    insertSort_Sen(array3, arrayLen);
    printArray(array3, arrayLen);


    cout << "=========================================" << endl;

    int array4[] = {9, 12, 8, 7};
    arrayLen = sizeof(array4)/sizeof(int);

    printArray(array4, arrayLen);
    insertSort(array4, arrayLen);
    printArray(array4, arrayLen);

    cout << "=========================================" << endl;

    int array5[] = {9, 12, 8, 7, 3};
    arrayLen = sizeof(array5)/sizeof(int);

    printArray(array5, arrayLen);
    insertSort_Sen(array5, arrayLen);
    printArray(array5, arrayLen);


}