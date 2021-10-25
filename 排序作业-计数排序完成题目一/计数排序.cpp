#include <iostream>
#include <math.h>

using namespace std;

bool coutingSort(int array[], size_t arrLen) {
   //������鳤�ȣ����С��2��ֱ����� 
    if (arrLen < 2) {
        return true;
    }

   //���������Сֵ���趨��Χ 
    int max = array[0];
    int min = array[0];
  //�ҳ���Сֵ 
    for (size_t i = 1; i < arrLen; ++i)
    {
        if (min > array[i]) {
            min = array[i];
        }
        //�ҳ����ֵ 
        else if (max < array[i]) {
            max = array[i];
        }
    }
 
   //Ϊ���α����ռ�countingBuckets�����ڴ� 
    int *countingBuckets = new int[max - min + 1]();

 //��¼Ԫ�س��ִ��� 
    for (size_t j = 0; j < arrLen; ++j)
    {
        ++countingBuckets[array[j] - min];
    }

//��������Ԫ�س��ִ�������Եõ��������ݵ�����λ�� 
    for (size_t k = 1; k < (max - min + 1); ++k)
    {
        countingBuckets[k] += countingBuckets[k-1];
    }
 //Ϊ���α����ռ�tempArray�����ڴ� 
    int *tempArray = new int[arrLen]();
    //��ԭ����Ԫ�ذ�����countingBuckets���������Ӧλ�ô��� 
    for (int l = arrLen - 1; l >= 0; --l)
    {
        tempArray[--countingBuckets[array[l] - min]] = array[l];
    }
//��temp���鸴�Ƶ�array�� 
    for (size_t m = 0; m < arrLen; ++m)
    {
        array[m] = tempArray[m];
    }
//�ͷ��ڴ� 
    delete [] countingBuckets;
    delete [] tempArray;

    
    return true;
}
//�������array 
void printArray(int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}
int main(){
int a[10]={3,4,52,8,1,3,34,65,85,37};
cout<<"����ǰ:";
printArray(a,10);
cout<<endl<<"�����"; 
coutingSort(a,10);
printArray(a,10);
int k;
cout<<"������������ҵ�����λ�ã�"<<endl;
cin>>k;
cout<<"�������ҵ�����Ϊ��"<<a[k];
return 0;
}
