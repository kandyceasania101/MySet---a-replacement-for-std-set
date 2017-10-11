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
  T *Arr;
  int Size;
  int Capacity;

public:
  //myset constructor MAKE DYNAMIC
  myset()
      : Arr(new T[4]),
        Size(0),
        Capacity(4)
  {
  }

  int capacity() { return Capacity; }

  //copy constructor MAKE DYNAMIC
  myset(const myset &other)
      : Arr(new T(Capacity)), Size(other.Size)
  {
    for (int i = 0; i < other.Size; i++)
    {
      Arr[i] = other.Arr[i];
    }
  }

  // Destructor: destroy all elements in set.
  ~myset() { delete[] Arr; } //DONE

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
      Arr[i] = NULL;
    }
    Size = 0;
  }

  //
  // insert(e)
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
        Temp[i] = Arr[i];
      }
      Arr = Temp;
    }

    for (i = 0; i < size(); i++)
    {
      if (Arr[i] == e)
      {
        return false;
      }
    }

    for (i = size() - 1; i >= 0 && Arr[i] > e; i--)
    {
      Arr[i + 1] = Arr[i];
    }
    Arr[i + 1] = e;

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

    if ( !(e < Arr[mid]) && !(Arr[mid] < e)) { return iterator(Arr + mid);}
    else if ( Arr[mid] < e ) { return binarySearch( high, mid+1, e ); }
    else if ( e < Arr[mid] ) { return binarySearch( mid-1, low, e ); }
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
      this->Arr[i] = rhs.Arr[i];
    }
    return *this;
  }

  iterator begin() { return iterator(Arr); }      //DONE
  iterator end() { return iterator(Arr + Size); } //DONE
};
