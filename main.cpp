#include <QCoreApplication>
#include <QDebug>

enum{
    bubble,
    insertion,
};

static void bubbleSort(unsigned char length, int* arr)
{
    int temp = 0;
    bool swap;
    for (int i = length - 1; i > 0; i--)  // 每次需要排序的长度，每次递减1
    {
        swap = false;
        for (int j = 0; j < i; j++)  // 从第一个元素到第i个元素。判断是否交换i次
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = true;
            }
        }//loop j
        if(!swap)
            break;
    }//loop i
}// method bubbleSort 稳定 小数据量

static void insertionSort(unsigned char length, int * arr)
{
    for (int i=1; i<length; ++i)
    {
        int value = arr[i];
        int position=i;
        while (position>0 && arr[position-1]>value)
        {
            arr[position] = arr[position-1];
            position--;
        }
        arr[position] = value;
    }//loop i
}


void Print_Arr(unsigned char length, int * arr)
{
    for(unsigned char i = 0;i != length;++i)
    {
        printf("%d  ",arr[i]);
    }
}


void Sort_Proc(unsigned char length,int* arr,int control)
{
    switch (control)
    {
    case bubble:
        bubbleSort(length,arr);
        break;
    case insertion:
        insertionSort(length, arr);
    default:
        break;
    }
    Print_Arr(length,arr);
}


int main(int argc, char *argv[])
{
    int Num[] = {63,25,90,1,4,8,19,9,99,90,7,5};

    qDebug()<<"Here is lots of ways to sort!";
    QCoreApplication a(argc, argv);

    unsigned char Num_Size = sizeof (Num)/sizeof (int);
    qDebug()<<"The Num Size is"<<Num_Size;

    Sort_Proc(Num_Size,Num,insertion);


    return a.exec();
}
