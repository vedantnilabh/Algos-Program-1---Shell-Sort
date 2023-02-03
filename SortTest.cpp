#include <iostream>
#include "SortClass.h"


void insertionSort(SortClass &s)
{
    for (int j = 1; j < s.count(); j++)
	{
	   int i = j;
	   while ((i >= 0) && (s.lessthan(i, i-1)))
		{
		   s.swap(i-1, i);
		   i--;
		}
	} 
}

int main()
{

    SortClass  st(20);

    cout << st << endl; 
    insertionSort(st);
    cout << "------\n";
    cout << st << endl; 
    cout << "Swap count : " << st.getSwapCount() << endl;
   
    return 0;
}
