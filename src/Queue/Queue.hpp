//
// Created by Noah Everett on 6/9/22.
//

#ifndef BASE_QUEUE_HPP
#define BASE_QUEUE_HPP

namespace Base::Queue::Queue {

template< class t_class >
class queue // Uses variables passed in. (doesn't allocate any new memory)
            //                           (hence the reason to reinvent the wheel, per se)
{
    public:
        queue( void                  );
        queue( const t_class*& t_obj );
       ~queue( void                  );

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

#endif //BASE_QUEUE_HPP
