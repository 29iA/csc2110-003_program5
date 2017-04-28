#if !defined (PQSORT_H)
#define PQSORT_H

#include "PQAVL.h"

template < class T >
class PQSort
{
   private:
		//pre: includes item, item amount, min or max argument, comparison statement, and its key
		//post: creates a PQ tree and use pqInsert & pqRemove as necessary
      static void _pqSort(T** items, int itemAmount, bool min_max, int (*compare_item)(T* one, T* two), int (*compare_key) (String* key, T* item));

   public:
		//pre: includes item, item amount, min or max argument, comparison statement, and its key
		//post: creates a dynamically allocated array of itemAmount, get all items to its new array, and calls _pqSort with the new array
      static T** pqSort(T** items, int itemAmount, bool min_max, int (*compare_item)(T* one, T* two), int (*compare_key) (String* key, T* item));
};

template < class T >
void PQSort<T>::_pqSort(T** items, int itemAmount, bool min_max, int (*compare_item)(T* one, T* two), int (*compare_key) (String* key, T* item))
{
   PQAVL<T>* pqTree = new PQAVL<T>(min_max, compare_item, compare_key);

   for(int i = 0; i < itemAmount; i++)
      pqTree->pqInsert(items[i]);

   for(int i = 0; i < itemAmount; i++)
      items[i] = pqTree->pqRemove();
}

template < class T >
T** PQSort<T>::pqSort(T** items, int itemAmount, bool min_max, int (*compare_item)(T* item_1, T* item_2), int (*compare_key) (String* key, T* item))
{
   T** sort = new T*[itemAmount];

   for(int i = 0; i < itemAmount; i++)
      sort[i] = items[i];

   _pqSort(sort, itemAmount, min_max, compare_item, compare_key);

   return sort;
}

#endif
