#ifndef OPENPP_AUDIO_RING_BUFFER_H_
#define OPENPP_AUDIO_RING_BUFFER_H_

/******************************************************\
 * Usage: Platform independent RingBuffer Class
 * Date: 12th February 2015
 * Author: Stefan Kreiner
 *
 * -------------------------
 * Notes:
 *  - Not Thread-Save
 *
\******************************************************/


#include <vector>

namespace Openpp
{
namespace Audio
{

template <typename T>
class RingBuffer
{
public:
    //// Create the Ring Buffer with Size Elements
    RingBuffer(int Size);

    //// Return the Size of the RingBuffer
    int GetSize() const;

    //// Resize the RingBuffer
    /// mWriteIter and mReadIter are modified
    /// mReadIter points to first, mWriteIter to last element
    void Resize(int Size);

    //// Add an Element to the RingBuffer
    /// return FALSE if Buffer is full or the Size is 0
    bool Put(const T& data);

    //// Return the Last Element in the RingBuffer (once per element)
    /// If The Buffer is Empty returns T(0) or T("")
    T Get() const;

    //// Returns true if the Buffer is empty
    /// Allways check before accessing the Buffer
    bool IsEmpty() const;

    //// Returns true if the Buffer is full
    /// Put returns false if the Buffer is full
    bool IsFull() const;

    //// Get the amount of Elements in the Buffer
    int GetElementCount() const;

private:
    std::vector<T> mBuffer;
    int mElementCount;
    int mSize;

    std::vector<T>::iterator mReadIter;
    std::vector<T>::iterator mWriteIter;
};

} // Audio
} // Openpp

#include "RingBuffer.inl"

#endif // ___OPENPP_AUDIO_RING_BUFFER__H___
