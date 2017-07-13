
// COS30008, Problem Set 7, 2017

#include "DynamicQueue.h"

using namespace std;

template<class T, int N>
NTree<T,N>::NTree( const NTree<T,N>& aOtherNTree )
{
    fKey = aOtherNTree.fKey;												// 2
    
    for ( int i = 0; i < N; i++ )                                           // 2
    {
        if ( aOtherNTree.fNodes[i] != &NIL )
            fNodes[i] = new NTree<T,N>( *aOtherNTree.fNodes[i] );           // 4/8
        else
            fNodes[i] = &NIL;
    }
}

template<class T, int N>
NTree<T,N>::~NTree()
{
    for ( int i = 0; i < N; i++ )
        if ( fNodes[i] != &NIL )
            delete fNodes[i];
}

template<class T, int N>
NTree<T,N>& NTree<T,N>::operator=( const NTree<T,N>& aOtherNTree )
{
    if ( this != &aOtherNTree )
    {
        // delete children
        for ( int i = 0; i < N; i++ )
            if ( fNodes[i] != &NIL )
                delete fNodes[i];											// 2
        
        fKey = aOtherNTree.fKey;											// 1
        
        for ( int i = 0; i < N; i++ )
        {
            if ( aOtherNTree.fNodes[i] != &NIL )
                fNodes[i] = new NTree<T,N>( *aOtherNTree.fNodes[i] );
            else
                fNodes[i] = &NIL;
        }
    }
    
    return *this;									   						// 1/4=12
}

template<class T, int N>
void NTree<T,N>::traverseBreadthFirst( const TreeVisitor<T>& aVisitor ) const
{
    // to avoid deep copies, use pointers
    DynamicQueue<const NTree<T,N>*> lQueue;                                 // 2
    
    if ( !isEmpty() )                                                       // 1
    {
        // start with root node
        lQueue.enqueue( this );                                             // 1
    }
    
    while ( !lQueue.isEmpty() )                                             // 2
    {
        const NTree<T,N>* head = lQueue.top();                              // 2
        lQueue.dequeue();                                                   // 1
        
        if ( !head->isEmpty() )                                             // 1
        {
            aVisitor.visit( head->key() );                                  // 1
            
            for ( unsigned int i = 0; i < N; i++ )                          // 2
            {
                if ( head->fNodes[i] != &NIL )
                    lQueue.enqueue( (const NTree<T,N>*)head->fNodes[i] );   // 3/16
            }
        }
    }
}
