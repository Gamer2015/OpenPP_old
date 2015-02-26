#include "RingBuffer.h"

#include <vector>
#include <string>
#include <typeinfo>

namespace Openpp
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

    if(++mWriteIter == mBuffer.end())
        mWriteIter = mBuffer.begin();

    *mWriteIter = data;
}

template <typename T>
T RingBuffer<T>::Get() const
{
    --mElementCount;

    if(++mReadIter == mBuffer.end())
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
} // Openpp
