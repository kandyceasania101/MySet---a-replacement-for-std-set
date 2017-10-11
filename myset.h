/*myset.h*/

//
// myset data structure, i.e. a data structure modelled
// after std::set in modern C++.
//
// Kandyce Burks
// U. of Illinois, Chicago
// CS 341, Fall 2017
// Project #03
//

#pragma once
using namespace std;

template <typename T>
class myset
{
private:
  // Allows iteration through the set in element order.
  class iterator
  {
  private:
    const T *ptr;

  public:
    iterator(const T *pointer)
        : ptr(pointer)
    {
    }

    // Destructor
    ~iterator() {} //DONE

    iterator &operator++() //DONE
    {
      (ptr)++;
      return *this;
    }

    const T &operator*() { return *ptr; } //DONE

    bool operator!=(const iterator &rhs) { return !(rhs.ptr == ptr); } //DONE
    bool operator==(const iterator &rhs) { return rhs.ptr == ptr; }    //DONE
  };

private:
  T *Begin;
  int Size;
  int Capacity;

public:
  //myset constructor MAKE DYNAMIC
  myset()
      : Begin(new T[4]),
        Size(0),
        Capacity(4)
  {
  }

  int capacity() { return Capacity; }

  //copy constructor MAKE DYNAMIC
  myset(const myset &other)
      : Begin(new T(Capacity)), Size(other.Size)
  {
    for (int i = 0; i < other.Size; i++)
    {
      Begin[i] = other.Begin[i];
    }
  }

  // Destructor: destroy all elements in set.
  ~myset() { delete[] Begin; } //DONE

  int size() const { return Size; } //DONE

  // empty(): Returns true if set is empty, false if not.
  bool empty() const //DONE
  {
    if (size())
    {
      return false;
    }
    return true;
  }

  // clear(): Empties the set, destroying all the elements.  Afterwards, the size of the set is 0.
  void clear() //DONE
  {
    for (int i = 0; i < size(); i++)
    {
      Begin[i] = NULL;
    }
    Size = 0;
  }

  //
  // insert(e)
  //
  // Inserts the element e into the set.  Returns true if e
  // was inserted, false if e was already in the set (and thus
  // not inserted again).  Elements are inserted in element
  // order as defined by the < operator; this enables in order
  // iteration.
  //
  // Requirements:
  //   1. Insert time must be <= O(N).
  //   2. Set grows as needed to accommodate new elements.
  //   3. Assumes only < operator; two elements x and y are
  //      equal if (!(x<y)) && (!(y<x)).
  //

  bool insert(const T &e) //DONE
  {
    int i;

    if (size() == Capacity - 1)
    {
      Capacity *= 2;
      T *Temp = new T[Capacity];

      for (i = 0; i < size(); i++)
      {
        Temp[i] = Begin[i];
      }
      Begin = Temp;
    }

    for (i = 0; i < size(); i++)
    {
      if (Begin[i] == e)
      {
        return false;
      }
    }

    for (i = size() - 1; i >= 0 && Begin[i] > e; i--)
    {
      Begin[i + 1] = Begin[i];
    }
    Begin[i + 1] = e;

    Size++;

    return true;
  }

  // Inserts e into the set; see insert(e).
  myset &operator+=(const T &e) //DONE
  {
    this->insert(e);
    return *this;
  }

  //
  // find(e)
  //
  // Searches the set for the element e, returning an iterator
  // to e if found.  If e is not found, end() is returned, i.e.
  // an iterator denoting one past the last element.
  //
  // Requirements:
  //   1. Find time must be <= O(lgN).
  //   2. Assumes only < operator; two elements x and y are
  //      equal if (!(x<y)) && (!(y<x)).
  //
  iterator find(const T &e) //DONE
  {
    auto iterator = binarySearch(size(), 0, e);

    return iterator;
  }

  iterator binarySearch(int high, int low, const T &e)
  {
    int mid = (high + low) / 2;
    if(high < low){ return end(); }

    if ( !(e < Begin[mid]) && !(Begin[mid] < e)) { return iterator(Begin + mid);}
    else if ( Begin[mid] < e ) { return binarySearch( high, mid+1, e ); }
    else if ( e < Begin[mid] ) { return binarySearch( mid-1, low, e ); }
  }

  //
  // [e]
  //
  // Returns true if set contains e, false if not.
  //
  // Requirements:
  //   1. operation time must be <= O(lgN).
  //   2. Assumes only < operator; two elements x and y are
  //      equal if (!(x<y)) && (!(y<x)).
  //
  bool operator[](const T &e) //DONE
  {
    auto iterator = binarySearch (size(), 0, e );
    
    if (iterator == end()){ return false; }

    return true;
  }

  myset &operator=(const myset &rhs) //DONE
  {
    this->clear();
    this->Size = rhs.Size;
    for (int i = 0; i < rhs.Size; i++)
    {
      this->Begin[i] = rhs.Begin[i];
    }
    return *this;
  }

  iterator begin() { return iterator(Begin); }      //DONE
  iterator end() { return iterator(Begin + Size); } //DONE
};
