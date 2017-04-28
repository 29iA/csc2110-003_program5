#if !defined (PQSORT_H)
#define PQSORT_H

#include "PQAVL.h"

template < class T >
class PQSort
{
   private:
      static void _pqSort(T** items, int num_items, bool min_or_max, int (*compare_item)(T* one, T* two), int (*compare_key) (String* key, T* item));

   public:
      static T** pqSort(T** items, int num_items, bool min_or_max, int (*compare_item)(T* one, T* two), int (*compare_key) (String* key, T* item));
};

template < class T >
T** PQSort<T>::pqSort(T** items, int num_items, bool min_or_max, int (*compare_item)(T* item_1, T* item_2), int (*compare_key) (String* key, T* item))
{
   T** sort = new T*[num_items];

   for(int i = 0; i < num_items; i++)
   {
      sort[i] = items[i];
   }

   _pqSort(sort, num_items, min_or_max, compare_item, compare_key);

   return sort;
}

template < class T >
void PQSort<T>::_pqSort(T** items, int num_items, bool min_or_max, int (*compare_item)(T* one, T* two), int (*compare_key) (String* key, T* item))
{
   PQAVL<T>* pqTree = new PQAVL<T>(min_or_max, compare_item, compare_key);

   for(int i = 0; i < num_items; i++)
   {
      pqTree->pqInsert(items[i]);
   }

   for(int i = 0; i < num_items; i++)
   {
      items[i] = pqTree->pqRemove();
   }
}

#endif
