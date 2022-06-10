//
// Created by Noah Everett on 6/9/22.
//

#ifndef BASE_QUEUE_NOSHRINK_HPP
#define BASE_QUEUE_NOSHRINK_HPP

namespace Base::Queue::Queue_NoShrink {

template< class t_class >
class queue_noShrink // Uses variables passed in (doesn't allocate any new memory),
                     // and queue can only grow. (hence the reason to reinvent the wheel, per se)
                     // Used in the `messenger` class as a fast `string` implementation.
                     // This is queue is circularly linked.
{
    public:
        queue_noShrink( void                  );
        queue_noShrink( const t_class*& t_obj );
       ~queue_noShrink( void                  );

        void      enqueue( const t_class*& t_obj );
        t_class*& dequeue( void                  );
        void      clear  ( void                  );
        bool&&    isEmpty( void                  );

    private:
        struct node {
            t_class*& m_obj;
            t_class*  m_next{ nullptr };
        };
        node   *  m_first;
        node   *  m_end{ m_first };
        node   *& m_temp_node;
        t_class*& m_temp_obj;
};

}

#endif //BASE_QUEUE_NOSHRINK_HPP
