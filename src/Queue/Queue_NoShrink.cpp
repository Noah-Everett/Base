//
// Created by Noah Everett on 6/9/22.
//

#include "Queue_NoShrink.hpp"

namespace Base::Queue::Queue_NoShrink {

template< class t_class >
queue_noShrink< t_class >::queue_noShrink( void ): m_first{ nullptr }
{
}

template< class t_class >
queue_noShrink< t_class >::queue_noShrink( const t_class& t_obj ): m_first{ new node{ &t_obj } }
{
}

template< class t_class >
queue_noShrink< t_class >::queue_noShrink( const t_class t_obj ): m_first{ new node{ &t_obj } }
{
}

template< class t_class >
queue_noShrink< t_class >::~queue_noShrink( void )
{
    m_end = m_first;
    m_first = m_first->m_next;
    while( m_first != m_end ) {
        m_temp_node = m_first;
        m_first = m_first->m_next;
        delete m_temp_node->m_obj;
        delete m_temp_node;
    }
    if( m_first != nullptr ) {
        delete m_first->m_obj;
        delete m_first;
    }
}

template< class t_class >
void queue_noShrink< t_class >::enqueue( const t_class& t_obj )
{
    if( m_first == nullptr ) { // If queue is empty
        m_first = new node{ &t_obj };
        m_end = m_first;
    } else { // If queue is not empty
        if( m_end == m_first ) { // If queue is full
            m_end->m_next = new node{ &t_obj };
            m_end = m_end->m_next;
            m_end->m_next = m_first;
        } else { // If queue is not full
            m_end = m_end->m_next;
            m_end->m_obj = t_obj;
        }
    }
}

template< class t_class >
void queue_noShrink< t_class >::enqueue( const t_class t_obj )
{
    if( m_first == nullptr ) { // If queue is empty
        m_first = new node{ &t_obj };
        m_end = m_first;
    } else { // If queue is not empty
        if( m_end == m_first ) { // If queue is full
            m_end->m_next = new node{ &t_obj };
            m_end = m_end->m_next;
            m_end->m_next = m_first;
        } else { // If queue is not full
            m_end = m_end->m_next;
            m_end->m_obj = t_obj;
        }
    }
}

template< class t_class >
t_class& queue_noShrink< t_class >::dequeue( void )
{
    m_temp_obj = m_first->m_obj;
    m_first = m_first->m_next;

    return m_temp_obj;
}

template< class t_class >
void queue_noShrink< t_class >::clear( void )
{
    m_end = m_first;
}

template< class t_class >
bool&& queue_noShrink< t_class >::isEmpty( void )
{
    if( m_first == m_end || m_first == nullptr )
        return true;
    else
        return false;
}

template< class t_class >
queue_noShrink< t_class* >::queue_noShrink( void ): m_first{ nullptr }
{
}

template< class t_class >
queue_noShrink< t_class* >::queue_noShrink( const t_class*& t_obj ): m_first{ new node{ t_obj } }
{
}

template< class t_class >
queue_noShrink< t_class* >::queue_noShrink( t_class*& t_obj ): m_first{ new node{ t_obj } }
{
}

template< class t_class >
queue_noShrink< t_class* >::queue_noShrink( const t_class* const& t_obj ): m_first{ new node{ t_obj } }
{
}

template< class t_class >
queue_noShrink< t_class* >::~queue_noShrink( void )
{
    m_end = m_first;
    m_first = m_first->m_next;
    while( m_first != m_end ) {
        m_temp_node = m_first;
        m_first = m_first->m_next;
        delete m_temp_node->m_obj;
        delete m_temp_node;
    }
    if( m_first != nullptr ) {
        delete m_first->m_obj;
        delete m_first;
    }
}

template< class t_class >
void queue_noShrink< t_class* >::enqueue( const t_class*& t_obj )
{
    if( m_first == nullptr ) { // If queue is empty
        m_first = new node{ t_obj };
        m_end = m_first;
    } else { // If queue is not empty
        if( m_end == m_first ) { // If queue is full
            m_end->m_next = new node{ t_obj };
            m_end = m_end->m_next;
            m_end->m_next = m_first;
        } else { // If queue is not full
            m_end = m_end->m_next;
            m_end->m_obj = t_obj;
        }
    }
}

template< class t_class >
void queue_noShrink< t_class* >::enqueue( const t_class* const& t_obj )
{
    if( m_first == nullptr ) { // If queue is empty
        m_first = new node{ t_obj };
        m_end = m_first;
    } else { // If queue is not empty
        if( m_end == m_first ) { // If queue is full
            m_end->m_next = new node{ t_obj };
            m_end = m_end->m_next;
            m_end->m_next = m_first;
        } else { // If queue is not full
            m_end = m_end->m_next;
            m_end->m_obj = t_obj;
        }
    }
}

template< class t_class >
void queue_noShrink< t_class* >::enqueue( t_class* const& t_obj )
{
    if( m_first == nullptr ) { // If queue is empty
        m_first = new node{ t_obj };
        m_end = m_first;
    } else { // If queue is not empty
        if( m_end == m_first ) { // If queue is full
            m_end->m_next = new node{ t_obj };
            m_end = m_end->m_next;
            m_end->m_next = m_first;
        } else { // If queue is not full
            m_end = m_end->m_next;
            m_end->m_obj = t_obj;
        }
    }
}

template< class t_class >
t_class*& queue_noShrink< t_class* >::dequeue( void )
{
    m_temp_obj = m_first->m_obj;
    m_first = m_first->m_next;

    return m_temp_obj;
}

template< class t_class >
void queue_noShrink< t_class* >::clear( void )
{
    m_end = m_first;
}

template< class t_class >
bool&& queue_noShrink< t_class* >::isEmpty( void )
{
    if( m_first == m_end || m_first == nullptr )
        return true;
    else
        return false;
}

}