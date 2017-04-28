#if !defined (PQAVL_H)
#define PQAVL_H

#include "AVLTree.h"

template < class T >
class PQAVL
{
   private:
      AVLTree<T>* avl;
      bool max; //see if tree is max or not
      int (*comp_item) (T* item_1, T* item_2);
      int (*comp_key) (String* key, T* item);

   public:
		//pre: constructor
		//post: initializes thing
      PQAVL(bool min_max, int (*compare_item) (T* item_1, T* item_2), int (*compare_key) (String* key, T* item));
		
      //pre: destructor
		//post: deletes avl pointer
		~PQAVL();
		
      //pre: get nothing
		//post: calls avl's isEmpty() function
		bool pqIsEmpty();
		
      //pre: get current item
		//post: calls avl's insert() funciton with T* item as parameter
		void pqInsert(T* item);
		
      //pre: get nothing
		//post: calls avl's remove() function
		T* pqRemove();
};

template < class T >
PQAVL<T>::PQAVL(bool min_max, int (*compare_item) (T* item_1, T* item_2), int (*compare_key) (String* key, T* item))
{
	avl = new AVLTree<T>(min_max, true, true, compare_item, compare_key);
   max = min_max;
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
