#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "SortClass.h"
#include <math.h>

using namespace std;


SortClass::SortClass(int n, bool genRandom)
{
    swapCount = 0;
    if (genRandom) 
	{
            srand(time(0));
	    for (int i = 0; i < n; i++)
		array.push_back((rand() % 1000) * 1.0);
	}
    else
	{
	    for (int i = 0; i < n; i++)
		array.push_back(0.0);
	}
}

SortClass::SortClass(const SortClass& st)
{
   swapCount = st.swapCount;
   for (int i = 0 ; i < st.array.size(); i++)
	array.push_back(st.array[i]);

}

int SortClass::count()
{
   return array.size();
}

int SortClass::getSwapCount()
{
   return swapCount;
}

void SortClass::clear(bool genRandom)
{
    swapCount = 0;
    if (genRandom) 
	{
            srand(time(0));
	    for (int i = 0; i < array.size(); i++)
		array[i] = rand() * 1.0;
	}
    else
	{
	    for (int i = 0; i < array.size(); i++)
		array[i] = 0.0;
	}
}

bool SortClass::lessthan(int i, int j)
{
   return (array[i] < array[j]);
}

void SortClass::swap(int i, int j)
{
    float temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    swapCount++;
}

ostream& operator<<(ostream& os, SortClass& s)
{
    for (int i = 0; i < s.array.size(); i++)
	{
	    if (!(i % 10))
		os << endl;
	    os << s.array[i] << " ";
	}
    return os;
}

istream& operator>>(istream& is, SortClass& s)
{
    for (int i = 0; i < s.array.size(); i++)
	{
	    is >> s.array[i];
	}
    return is;
}

void SortClass::ShellSort(SortClass &s, int code) {
    vector<int> hlist;
    if(code == 0){
        hlist.push_back(1);
    }
    if(code == 1){
        int h = 1;
        while((h * h) < s.count()){
            hlist.push_back(h * h);
            h += 1;
        }
    }
    else if (code == 2){
        int h = 1;
        while((pow(2, h) - 1) < s.count()){
            hlist.push_back(pow(2, h) - 1);
            h += 1;
        }
    }
    else if (code == 3){
        int h = 1;
        while(((pow(3, h) - 1) / 2) < s.count()){
            hlist.push_back((pow(3, h) - 1) / 2);
            h += 1;
        }

    }


    reverse(hlist.begin(), hlist.end());
    for(int i = 0; i < hlist.size(); i++) {
        int h = hlist[i];
        for (int j = h; j < s.count(); j++) {
            int k = j;
            while (k > h && s.lessthan(k, k - h)){
                s.swap(k, k - h);
                k -= h;
            }
        }
    }


}


