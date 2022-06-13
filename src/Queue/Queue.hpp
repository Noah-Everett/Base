//
// Created by Noah Everett on 6/9/22.
//

#ifndef BASE_QUEUE_HPP
#define BASE_QUEUE_HPP

namespace Base::Queue::Queue {

// Uses variables passed in. (doesn't allocate any new memory)
// (hence the reason to reinvent the wheel, per se)
template< class t_class >
class queue
{
    public:
        queue( void                 );
        queue( const t_class& t_obj );
       ~queue( void                 );

        void     enqueue( const t_class& t_obj );
        void     enqueue(       t_class& t_obj );
        t_class& dequeue( void                 );
        void     clear  ( void                 );
        bool&&   isEmpty( void                 );

    private:
        struct node {
            const t_class& m_obj;
            node*  m_next{ nullptr };
        };
        node   * m_first;
        node   * m_end{ m_first };
        mutable node   * m_temp_node{ m_first };
        mutable t_class  m_temp_obj{ nullptr };
};

template< class t_class >
class queue< t_class* >
{
    public:
        queue( void                  );
        queue( const t_class*& t_obj );
       ~queue( void                  );

        void      enqueue( const t_class*& t_obj );
        void      enqueue(       t_class*& t_obj );
        t_class*& dequeue( void                  );
        void      clear  ( void                  );
        bool&&    isEmpty( void                  );

    private:
        struct node {
            const t_class*& m_obj;
            node*  m_next{ nullptr };
        };
        node   * m_first;
        node   * m_end{ m_first };
        mutable node   * m_temp_node;
        mutable t_class* m_temp_obj;
};

}

#include "Queue.cpp"

#endif //BASE_QUEUE_HPP
