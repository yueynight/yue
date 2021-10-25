#include <iostream>

using namespace std;

class BigTopHeap {
    private:
        int *array; //存储堆的数组，从下标1开始存储数据
        int capacity; //堆中可以存储的数据的个数
        int count; //当前堆中已经存储的数据的个数

        void heapifyFromTopPos(int pos) {
            while (true)
            {
                int maxPos = pos;
                int curPos = pos * 2;
                if (curPos < count && array[pos] < array[curPos]) {
                    maxPos = curPos;
                }
                ++curPos;
                if (curPos < count && array[maxPos] < array[curPos]) {
                    maxPos = curPos;
                }

                if (pos == maxPos) {
                    //没有发生交换，说明当前位置的数据均比其子节点大
                    break;
                }
                int temp = array[pos];
                array[pos] = array[maxPos];
                array[maxPos] = temp;
                pos = maxPos;
            }
        }

    public:
        BigTopHeap(int heapCapacity) {
            array = new int[capacity + 1]();
            capacity = heapCapacity;
            count = 0;
        }

        // array一定是从下标1开始放数据
        BigTopHeap(int *arr, int arrayCapacity) {
            array = arr;
            capacity = arrayCapacity;
            count = capacity;

            for (int i = count/2; i > 0; --i) {
                heapifyFromTopPos(i);
            }
        }

        void insert(int data) {
            if (count >= capacity) {
                return;
            }

            array[++count] = data;
            int i = count;
            while (i/2 > 0 && array[i] > array[i/2]) {
                int temp = array[i];
                array[i] = array[i/2];
                array[i] = temp;
                i = i/2;
            }
        }

        bool removeTop(int &topValue) {
            if (0 == count) {
                return false;
            }
            topValue = array[1];

            array[1] = array[count];
            --count;
            heapifyFromTopPos(1);
            return true;
        }

        int* sortHeap() {
            while(count > 0) {
                int topValue = -1;
                if (removeTop(topValue)) {
                    array[count + 1] = topValue;
                }
            }

            return array;
        }

};
void printArray(int array[], int arrLen) {
    for (int i = 1; i < arrLen; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
    int array0[] = {0};
    int arrayLen = sizeof(array0)/sizeof(int);

    printArray(array0, arrayLen);
    BigTopHeap h0(array0, arrayLen - 1);
    h0.sortHeap();
    printArray(array0, arrayLen);

    cout << "=========================================" << endl;

    int array1[] = {0,1};
    arrayLen = sizeof(array1)/sizeof(int);

    printArray(array1, arrayLen);
    BigTopHeap h1(array1, arrayLen - 1);
    h1.sortHeap();
    printArray(array1, arrayLen);

    cout << "=========================================" << endl;

    int array2[] = {0, 2, 1};
    arrayLen = sizeof(array2)/sizeof(int);

    printArray(array2, arrayLen);
    BigTopHeap h2(array2, arrayLen - 1);
    h2.sortHeap();
    printArray(array2, arrayLen);

    cout << "=========================================" << endl;

    int array3[] = {0, 1, 5, 3};
    arrayLen = sizeof(array3)/sizeof(int);

    printArray(array3, arrayLen);
    BigTopHeap h3(array3, arrayLen - 1);
    h3.sortHeap();
    printArray(array3, arrayLen);


    cout << "=========================================" << endl;

    int array4[] = {0, 9, 12, 8, 7};
    arrayLen = sizeof(array4)/sizeof(int);

    printArray(array4, arrayLen);
    BigTopHeap h4(array4, arrayLen - 1);
    h4.sortHeap();
    printArray(array4, arrayLen);

    cout << "=========================================" << endl;

    int array5[] = {0, 9, 12, 8, 7, 3};
    arrayLen = sizeof(array5)/sizeof(int);

    printArray(array5, arrayLen);
    BigTopHeap h5(array5, arrayLen - 1);
    h5.sortHeap();
    printArray(array5, arrayLen);


}

