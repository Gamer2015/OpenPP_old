#ifndef OPENPPY_TYPES_CONTAINER_CIRCULAR_LIST_HPP_
#define OPENPPY_TYPES_CONTAINER_CIRCULAR_LIST_HPP_

#include <memory>

template <typename _datatype>
class CircularList
{
public:
    CircularList();

private:
    _datatype* _cursor;
    _datatype* _next;
    int _size;
};

#endif // OPENPPY_TYPES_CONTAINER_CIRCULAR_LIST_HPP_
