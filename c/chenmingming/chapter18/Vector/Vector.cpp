//#include "Vector.h"
using std::ptrdiff_t;

#include <scoped_allocator>
template <class T> allocator<T> Vector<T>::alloc;
template <class T> void Vector<T>::push_back(const T &t)
{
    if(first_free == end)
        reallocate();
    alloc.construct(first_free, t);
    ++first_free;
}
template <class T> void Vector<T>::reallocate()
{
    ptrdiff_t size = first_free - elements;
    ptrdiff_t newcapacity = 2 * (size>1?size:1);
    T* newelements = alloc.allocate(newcapacity);
    uninitialized_copy(elements, first_free,newelements);
    for(T *p = first_free; p != elements;)
        alloc.destroy(--p);
    if(elements)
        alloc.deallocate(elements, end-elements);
    elements = newelements;
    first_free = elements + size;
    end  = elements + newcapacity;
}
template <class T> void Vector<T>::reserve(const size_t capa)
{
    size_t size = first_free - elements;
    T* newelements = alloc.allocate(capa);
    if(size <= capa)
        uninitialized_copy(elements,first_free,newelements);
    else
        uninitialized_copy(elements, elements+capa, newelements);
    for(T *p = first_free; p != elements;)
        alloc.destroy(--p);
    if(elements)
        alloc.deallocate(elements, end-elements);
    elements = newelements;
    first_free = elements + min(size,capa);
    end = elements + capa;
}
template <class T> void Vector<T>::resize(const size_t n)
{
    size_t size = first_free - elements;
    size_t capacity = end - elements;
    if(n > capacity)
    {
        reallocate();
        uninitialized_fill(elements+size, elements+n, T());
    }
    else if(n > size)
    {
        uninitialized_fill(elements+size, elements+n, T());
    }
    else
    {
        for(T *p = first_free; p != elements+n;)
            alloc.destroy(--p);
    }
    first_free = elements + n;
}
template <class T> void Vector<T>::resize(const size_t n, const T &t)
{
    size_t size = first_free - elements;
    size_t capacity = end - elements;
    if(n > capacity)
    {
        reallocate();
        uninitialized_fill(elements+size, elements+n, t);
    }
    else if(n > size)
        uninitialized_fill(elements+size, elements+n, t);
    else
        for(T *p = first_free; p != elements+n;)
            alloc.destroy(--p);
    first_free = elements + n;
}
template <class T> T& Vector<T>::operator[](const size_t index)
{
    return elements[index];
}
template <class T> const T& Vector<T>::operator[](const size_t index) const
{
    return elements[index];
}
