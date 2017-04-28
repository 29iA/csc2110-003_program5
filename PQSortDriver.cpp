#include "PQSort.h"
#include "CD.h"
#include "ListArray.h"
#include <iostream>
using namespace std;

using CSC2110::String;
using CSC2110::ListArrayIterator;
using CSC2110::CD;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();
   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }
   delete iter;
}

int main()
{
	//read CDs
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int itemAmount = cds->size();

	//initializing...
   CD** minSort = new CD* [itemAmount];
   int counter;
   ListArrayIterator<CD>* iter;
   iter = cds->iterator();
   counter = 0;

	//sift through unsorted
   while(iter->hasNext())
   {
      CD* cd = iter->next();
       minSort[counter] = cd;
       counter++;
   }

	delete iter;

	//calls PQsort function now
   minSort = PQSort<CD>::pqSort(minSort, itemAmount, true, &CD::compare_items, &CD::compare_keys);

   iter = cds->iterator();
   counter = 0;

	//display new cd sorted list
   while(iter->hasNext())
   {
		CD* next = iter->next();
		CD* send = minSort[counter];
		send->displayCD();
		counter++;
	}

   cout << endl;
   delete iter;

	//maxSorting initialiation
   CD** maxSort = new CD* [itemAmount];
   counter = 0;
   iter = cds->iterator();

	//sift through unsorted
   while(iter->hasNext())
   {
      CD* cd = iter->next();
      maxSort[counter] = cd;
      counter++;
   }

   delete iter;

	//calls PQsort function now
   maxSort = PQSort<CD>::pqSort(maxSort, itemAmount, false, &CD::compare_items, &CD::compare_keys);

   iter = cds->iterator();
   counter = 0;

	//display new cd sorted list
   while(iter->hasNext())
   {
      CD* next = iter->next();
      CD* send = maxSort[counter];
      send->displayCD();
      counter++;
   }

	//clear everything
   delete iter;
   delete [] minSort;
   deleteCDs(cds);
   delete cds;
}
