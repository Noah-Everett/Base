//
// Created by Noah Everett on 6/9/22.
//

#include "Queue.hpp"

namespace Base::Queue::Queue {

template< class t_class >
queue< t_class >::queue( void ): m_first{ nullptr }
{
}

template< class t_class >
queue< t_class >::queue( const t_class*& t_obj ): m_first{ new node{ t_obj } }
{
}

template< class t_class >
queue< t_class >::~queue< t_class >( void )
{
    clear();
}

template< class t_class >
void queue< t_class >::enqueue( const t_class*& t_obj )
{
    if( m_first == nullptr ) { // If queue is empty
        m_first = new node{ t_obj };
        m_end = m_first;
    } else { // If queue is not empty
        m_end->m_next = new node{ t_obj };
        m_end = m_end->m_next;
    }
}

template< class t_class >
void queue< t_class >::enqueue( const t_class& t_obj )
{
    if( m_first == nullptr ) { // If queue is empty
        m_first = new node{ &t_obj };
        m_end = m_first;
    } else { // If queue is not empty
        m_end->m_next = new node{ t_obj };
        m_end = m_end->m_next;
    }
}

template< class t_class >
t_class*& queue< t_class >::dequeue( void )
{
    m_temp_obj = m_first->m_obj;
    m_temp_node = m_first;
    m_first = m_first->m_next;
    delete m_temp_node;

    return m_temp_obj;
}

template< class t_class >
void queue< t_class >::clear( void )
{
    while( m_first->m_next != nullptr ) { // While queue is not empty
        delete m_first->m_obj;
        m_temp_node = m_first;
        m_first = m_first->m_next;
        delete m_temp_node;
    }
    if( m_first != nullptr ) { // If queue was not already empty
        delete m_first->m_obj;
        delete m_first;
    }
    m_first = nullptr;
}

template< class t_class >
bool&& queue< t_class >::isEmpty( void )
{
    if( m_first == nullptr )
        return true;
    else
        return false;
}

}