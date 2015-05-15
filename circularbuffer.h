#ifndef CIRCULAR_BUFFER_HPP_
#define CIRCULAR_BUFFER_HPP_

#include <algorithm> // std::swap, std::max, std::lexicographical_compare, std::equal
#include <stdexcept> // std::invalid_argument

#include <iostream> // debug TODO remove

// Forward declaration of iterator
template <typename T_noconst, typename T, typename element_type = typename T::value_type>
class circular_buffer_iterator;

// An STL Compliant Circular Buffer Container
//   This Data Structure is basically a centered wrapping vector with space at both sides
//   to allow O(1) (constant time) insert/erase(front) as well as O(1) push_back and pop_back.
//   Internal structure is an array with an index starting from the center of capacity
//   and wrapping around to the start of the array.
//   As elements are added to the front and end, the start and end indices move
//   accordingly.
//   When capacity is reached, the storage container will reallocate its storage
//   increasing its capacity to 1.5 * capacity.
//     Like vectors, this makes push_back and push_front amortized time O(1)
//     per insertion.
//   The Default Capacity should be larger than 1 otherwise a Circular Buffer is
//   pointless.
template <typename T, typename Alloc = std::allocator<T> >
class circular_buffer {
  public:
    // TYPEDEFS:
    typedef circular_buffer<T, Alloc>            self_type;
    typedef Alloc                                allocator_type;
    typedef typename Alloc::value_type           value_type;
    typedef typename Alloc::pointer              pointer;
    typedef typename Alloc::const_pointer        const_pointer;
    typedef typename Alloc::reference            reference;
    typedef typename Alloc::const_reference      const_reference;
    typedef typename Alloc::size_type            size_type;
    typedef typename Alloc::difference_type      difference_type;
    // Iterator
    typedef circular_buffer_iterator <self_type, self_type> 
      iterator;
    // Const Iterator
    typedef circular_buffer_iterator <self_type,const self_type, const value_type> 
      const_iterator;
    // Reverse Iterator
    typedef std::reverse_iterator<iterator>       reverse_iterator;
    // Reverse Const Iterator
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    // CONSTANTS:
    static const size_type kDefaultCapacity = 5;

    // CONSTRUCTORS:
    explicit circular_buffer(size_type capacity = kDefaultCapacity)
      : size_(0), capacity_(capacity), start_idx_(capacity/2), end_idx_(capacity/2),
      buffer_(alloc_.allocate(capacity)) {
        if (capacity <= 0) {
          throw std::invalid_argument("invalid capacity");
        }
      };

    // DECONSTRUCTORS:
    ~circular_buffer() {}; // TODO

    // ITERATORS
    // begin(), the 0 represents buffer_[0]
    iterator         begin()       { return iterator(this, 0); }
    const_iterator   begin() const { return const_iterator(this, 0); }
    // end(), the size() represents buffer_[size()]
    iterator         end()         { return iterator(this, size()); }
    const_iterator   end() const   { return const_iterator(this, size()); }
    // rbegin()
    reverse_iterator rbegin()      { return reverse_iterator(end()); }
    const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
    // rend()
    reverse_iterator rend()        { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

    // CAPACITIES:
    // @brief  Returns the amount of elements in the %circular_buffer
    // @return  Read-only (constant) circular size
    size_type size() const { return size_; };
    // @brief  Returns the maximum number of elements that the %circular_buffer can hold
    //         during dynamic allocation mode
    // @return  Read-only (constant) maximum size
    size_type max_size() const { return alloc_.max_size(); };
    // @brief  Resizes the %circular_buffer to specified size
    // @warn  Recreates entire %circular_buffer. O(N) time and space required
    void resize() { }; // TODO
    // @brief  Returns size of allocated storage capacity
    size_type capacity() const   { return capacity_; };
    // @brief  Returns true if there are elements in the %circular_buffer
    // @return  Read-only (constant) True iff end index is in default state 
    bool empty() const  { return !size_; };
    // @brief  Request that the %circular_buffer capacity be at least enough to contain
    //         n elements. This function has no effect on the %circular_buffer size and
    //         cannot alter its elements.
    // @warn  If @a n is greater than the current %circular_buffer capacity, the function
    //        causes the container to reallocate its storage increasing its
    //        capacity to @a n (or greater). O(n) time and space required when this occurs
    void reserve(size_type n) {
      if (capacity() < n) {
        circular_buffer temp( std::max<size_type>(n, capacity() * 1.5) );
        temp.assign(begin(), end());
        swap(temp);
      }
    }

    // MODIFIERS:
    // @brief  Fills a %circular_buffer with copies of the elements in the
    //         range [start, last)
    // @param  start  An input iterator
    // @param  last   An input iterator
    // @warn  The assignment completely changes the %circular_buffer and the
    //        resulting %circular_buffer's size is the same as the number of 
    //        elements assigned. Old data will be lost
    // TODO check website for another prototype
    template <typename iter>
      void assign(iter start, iter last) {
        if (size() != 0) 
          clear();
        while (start != last) {
          push_back(*start);
          ++start;
        } 
      }
    // @brief  Removes the first indexed element
    void pop_front() {
      alloc_.destroy(buffer_ + start_idx_);
      ++start_idx_;
      --size_;
    }
    // @brief  Removes the last indexed element
    void pop_back();
    // @brief  Adds an element to the head of the %circular_buffer
    //         and decrements the start index
    // @param  val  Element to be added
    // @warn  If capacity has been reached, the function causes the container to
    //        reallocate its storage increasing its capacity to 1.5 * capacity.
    //        O(n) time and space required when this occurs
    void push_front(const value_type &val) {
      if (end_idx_ == start_idx_ && !empty()) {
        reserve(capacity() * 1.5);
      } else if (end_idx_ == start_idx_) {
        // Do a push_back only on empty case
        push_back(val);
        return;
      }

      if (start_idx_ == 0)
        start_idx_ = capacity() - 1;
      else
        --start_idx_;

      buffer_[start_idx_] = val;
      ++size_;
    }
    // @brief  Adds an element to the tail of the %circular_buffer
    // @param  val  Element to be added
    // @warn  If capacity has been reached, the function causes the container to
    //        reallocate its storage increasing its capacity to 1.5 * capacity.
    //        O(n) time and space required when this occurs
    void push_back(const value_type &val) {
      if (end_idx_ == start_idx_ && !empty())
        reserve(capacity() * 1.5);

      buffer_[end_idx_] = val;
      ++size_;
      end_idx_ = (end_idx_ + 1) % capacity_;
    }
    // @brief  Removes all elements from the @circular_buffer (which are destroyed),
    //         leaving the container with a size of 0.
    // @warn  If the elements themselves are pointers, the pointed-to memory is not
    //        touched in any way. Managing the pointer is the user's responsibility.
    void clear() {
      for (size_type x = 0; x < capacity(); ++x) {
        alloc_.destroy(buffer_ + x);
      }
      start_idx_ = capacity() / 2;
      end_idx_ = capacity() /2;
      size_ = 0;
    }

    // ELEMENT ACCESS:
    // @brief  Provides access to the data contained in %circular_buffer
    // @param n The index of the element for which data should be accessed
    // @return  Read/write reference to data
    // @warn  Calling this function with an argument @a n that is out of range
    //        causes undefined behaviour
    reference operator [] (size_type n) { return buffer_[(start_idx_ + n) % capacity_]; };
    // @brief  Provides access to the data contained in %circular_buffer
    // @param n The index of the element for which data should be accessed
    // @return  Read/write reference to data
    // @warn  Calling this function with an argument @a n that is out of range
    //        causes undefined behaviour
    const_reference operator [] (size_type n) const;
    // @brief  Provides access to the data contained in %circular_buffer
    // @param n The index of the element for which data should be accessed
    // @return  Read/write reference to data
    // @throw  std::out_of_range  If @a n is an invalid index
    reference at(size_type n);
    // @brief  Provides access to the data contained in %circular_buffer
    // @param n The index of the element for which data should be accessed
    // @return  Read-only (constant) reference to data
    // @throw  std::out_of_range  If @a n is an invalid index
    const_reference at(size_type n) const;
    // @return  Read/Write reference to the first indexed element 
    //          in %circular_buffer
    // @warn  Calling this function on an empty container causes undefined
    //        behaviour
    reference front()        { return buffer_[start_idx_]; };
    // @return  Read-only (constant) reference to the first indexed element 
    //          in %circular_buffer
    // @warn  Calling this function on an empty container causes undefined
    //        behaviour
    const_reference front() const  { return buffer_[start_idx_]; };
    // @return  Read/Write reference to the last indexed element 
    //          in %circular_buffer
    // @warn  Calling this function on an empty container causes undefined
    //        behaviour
    reference back()         { return buffer_[end_idx_]; };
    // @return  Read-only (constant) reference to the last indexed element 
    //          in %circular_buffer
    // @warn  Calling this function on an empty container causes undefined
    //        behaviour
    const_reference back()  const  { return buffer_[end_idx_]; };


  private:
    size_type size_;
    size_type capacity_;
    size_type start_idx_;
    size_type end_idx_;
    allocator_type alloc_;
    value_type * buffer_;

    // HELPER FUNCTIONS:
    // @brief  Swaps the current %circular_buffer container with this one
    // @param  other  The %circular_buffer to swap with
    void swap(circular_buffer &other) {
      std::swap(size_,   other.size_);
      std::swap(capacity_,   other.capacity_);
      std::swap(start_idx_,   other.start_idx_);
      std::swap(end_idx_,   other.end_idx_);
      std::swap(buffer_,   other.buffer_);
    }
};

template <typename T, typename Alloc>
bool operator == (const circular_buffer<T, Alloc> &a, const circular_buffer<T, Alloc> &b) {
  return a.size() == b.size() && std::equal(a.begin(), a.end(), b.begin());
}

template <typename T, typename Alloc>
bool operator != (const circular_buffer<T, Alloc> &a, const circular_buffer<T, Alloc> &b) {
  return a.size() != b.size() || !std::equal(a.begin(), a.end(), b.begin());
}

template <typename T, typename Alloc>
bool operator < (const circular_buffer<T, Alloc> &a, const circular_buffer<T, Alloc> &b) {
  return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}

template <typename T_noconst, typename T,
         typename element_type>
         class circular_buffer_iterator {
           public:
             typedef circular_buffer_iterator<T_noconst,T,element_type> self_type;

             typedef std::random_access_iterator_tag     iterator_category;
             typedef typename T::value_type              value_type;
             typedef typename T::size_type               size_type;
             typedef typename T::pointer                 pointer;
             typedef typename T::const_pointer           const_pointer;
             typedef typename T::reference               reference;
             typedef typename T::const_reference         const_reference;
             typedef typename T::difference_type         difference_type;

             circular_buffer_iterator(T * cbuffer, size_type index)
               : cbuffer_(cbuffer), index_(index) {};

             // Converting a non-const iterator to a const iterator
             circular_buffer_iterator(const circular_buffer_iterator<T_noconst,
                 T_noconst, typename T_noconst::value_type> &other) 
               : cbuffer_(other.cbuffer_), index_(other.index_) {};

             friend class circular_buffer_iterator<T, const T, const element_type>;

             element_type &operator * ()  { return (*cbuffer_)[index_]; };
             element_type *operator -> () { return &(operator * ()); };

             self_type &operator ++ () {
               index_++;
               return *this;
             }
             self_type operator ++ (int) {
               self_type tmp(*this);
               ++(*this);
               return tmp;
             }

             self_type &operator -- () {
               index_--;
               return *this;
             }
             self_type operator -- (int) {
               self_type tmp(*this);
               --(*this);
               return tmp;
             }

             self_type operator + (difference_type n) const {
               self_type tmp(*this);
               tmp.index_ += n;
               return tmp;
             }
             self_type &operator += (difference_type n) {
               index_ += n;
               return *this;
             }

             self_type operator - (difference_type n) const {
               self_type tmp(*this);
               tmp.index_ -= n;
               return tmp;
             }
             self_type &operator -= (difference_type n) {
               index_ -= n;
               return *this;
             }

             difference_type operator - (const self_type &c) const {
               return index_ - c.index_;
             }

             bool operator == (const self_type &other) const {
               return index_ == other.index_ && cbuffer_ == other.cbuffer_;
             }
             bool operator != (const self_type &other) const {
               return index_ != other.index_ && cbuffer_ == other.cbuffer_;
             }
             bool operator >( const self_type &other) const {
               return index_ > other.index_;
             }
             bool operator >= (const self_type &other) const {
               return index_ >= other.index_;
             }
             bool operator <( const self_type &other) const {
               return index_ < other.index_;
             }
             bool operator <= (const self_type &other) const {
               return index_ <= other.index_;
             }

           private:
             T * cbuffer_;
             size_type  index_;
         };

template <typename circular_buffer_iterator_t>
circular_buffer_iterator_t operator + (const typename circular_buffer_iterator_t::difference_type &a,
    const circular_buffer_iterator_t &b) {
  return circular_buffer_iterator_t(a) + b;
}

template <typename circular_buffer_iterator_t>
circular_buffer_iterator_t operator - (const typename circular_buffer_iterator_t::difference_type &a,
    const circular_buffer_iterator_t &b) {
  return circular_buffer_iterator_t(a) - b;
}

#endif
