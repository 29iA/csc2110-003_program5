#if !defined (PQAVL_H)
#define PQAVL_H

#include "AVLTree.h"

template < class T >
class PQAVL
{
   private:
      AVLTree<T>* avl;
      bool max;
      int (*comp_item) (T* item_1, T* item_2);
      int (*comp_key) (String* key, T* item);

   public:
      PQAVL(bool min_or_max, int (*compare_item) (T* item_1, T* item_2), int (*compare_key) (String* key, T* item));
      ~PQAVL();
      bool pqIsEmpty();
      void pqInsert(T* item);
      T* pqRemove();
};

template < class T >
PQAVL<T>::PQAVL(bool min_or_max, int (*compare_item) (T* item_1, T* item_2), int (*compare_key) (String* key, T* item))
{
   avl = new AVLTree<T>(min_or_max, true, true, compare_item, compare_key);
   max = min_or_max;
   comp_item = compare_item;
   comp_key = compare_key;
}

template < class T >
PQAVL<T>::~PQAVL()
{
   delete avl;
}

template < class T >
bool PQAVL<T>::pqIsEmpty()
{
   return avl->isEmpty();
}

template < class T >
void PQAVL<T>::pqInsert(T* item)
{
   avl->insert(item);
}

template < class T >
T* PQAVL<T>::pqRemove()
{
   return avl->remove();
}

#endif
