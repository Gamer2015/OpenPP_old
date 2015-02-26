#include "RingBuffer.h"

#include <vector>
#include <string>
#include <typeinfo>

namespace Librepp
{
namespace Audio
{

template <typename T>
RingBuffer<T>::RingBuffer(int Size)
    : mSize(Size)
{
    Resize(mSize);
}

template <typename T>
int RingBuffer<T>::GetSize() const
{
    return mSize;
}

template <typename T>
void RingBuffer<T>::Resize(int Size)
{
    mBuffer.resize(Size);

    mReadIter = mBuffer.begin();
    mWriteIter = mBuffer.end() - 1;

    mElementCount = 0;
}

template <typename T>
bool RingBuffer<T>::Put(const T& data)
{
    if(IsFull() || mBuffer.size() == 0)
        return false;

    ++mElementCount;

    *mWriteIter = data;
    if(++mWriteIter == mBuffer.end())
        mWriteIter = mBuffer.begin();
}

template <typename T>
T RingBuffer<T>::Get() const
{
    if(IsEmpty() || mBuffer.size() == 0)
    {
        if(typeid(T) != (typeid(std::string)))
            return T(0);
        else
            return T("");
    }

    --mElementCount;

    ++mReadIter;
    if(mReadIter == mBuffer.end())
        mReadIter = mBuffer.begin();

    return *mReadIter;
}

template <typename T>
bool RingBuffer<T>::IsEmpty() const
{
    return (mElementCount == 0);
}

template <typename T>
bool RingBuffer<T>::IsFull() const
{
    return (mElementCount == mSize);
}

template <typename T>
int RingBuffer<T>::GetElementCount() const
{
    return mElementCount;
}

} // Audio
} // Librepp
