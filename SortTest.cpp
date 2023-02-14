#include <iostream>
#include "SortClass.h"
#include <cstdlib>
#include <ctime>

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
    //SortClass  st(1000);

    //cout << st << endl;
    //insertionSort(st);
    //st.ShellSort(st, 1);
    //cout << "------\n";
    //cout << st << endl;
    //cout << "Swap count : " << st.getSwapCount() << endl;
    //st.clear();
    srand(time(0));
    for (int i = 500; i <= 5000; i += 500) {
        for (int j = 0; j <= 3; j++) {
            for (int k = 0; k < 100; k++) {
                //cout << endl;
                //cout << st << endl;
                SortClass st(i);
                st.ShellSort(st, j);
                //insertionSort(st);
                cout << st.getSwapCount() << endl;
            }
        }
    }
   
    return 0;
}
