# circular_vector
An STL-Compliant Circular Vector (Container) Data Structure written in C++

Shares similaries to a Circular Buffer Data Structure, except allows access to all elements in the container.

Contains all the same member functions as C++98 std::vector from the STL, except for vector::insert and vector::erase. Newly introduced member functions include: push_front and pop_front which unlike the counterpart operations in std::vector are O(1) time (Constant).

#CONSTRUCTORS:#
circular_vector(size_type capacity = kDefaultCapacity)

#ITERATORS:#
**<dt>circular_vector::_begin_</dt>**
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<code>iterator begin();</code></p>
`const_iterator begin() const;`
<dd><em>@brief</em>  <ul>An iterator pointing to array\_[0], i.e. the first element</ul></dd>
<dd><em>@warn</em>  <ul>Iterator should be repositioned upon capacity reallocation or after push_front call</ul></dd>


#####*circular_vector::end*#####
@brief  An iterator pointing to array\_[size()], i.e. past-the-end element
@warn  Iterator should be repositioned upon capacity reallocation or after push_back call
<p>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<code>iterator end();</code></p>
`const_iterator end() const;`

circular_vector::rbegin
@brief  Returns a reverse iterator pointing to the last element in the vector (i.e., its reverse beginning). Reverse iterators iterate backwards: increasing them moves them towards the beginning of the container. rbegin points to the element right before the one that would be pointed to by member end. Notice that unlike member vector::back, which returns a reference to this same element, this function returns a reverse random access iterator.
@warn  Iterator should be repositioned upon capacity reallocation or after push_back call
`reverse_iterator rbegin();`
`const_reverse_iterator rbegin() const;`

circular_vector::rend
@brief  Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (which is considered its reverse end). The range between vector::rbegin and vector::rend contains all the elements of the vector (in reverse order).
@warn  Iterator should be repositioned upon capacity reallocation or after push_front call
      `reverse_iterator rend();`
`const_reverse_iterator rend() const;`

#ALLOCATORS:#
circular_vector::get_allocator

@brief  Returns a copy of the allocator object associated with the @circular_vector
@return  Read-only (constant) allocator
`allocator\_type get\_allocator() const;`

#CAPACITIES:#
circular_vector::size
@brief  Returns the amount of elements in the %circular_vector
@return  Read-only (constant) circular size
`size_type size() const;`

circular_vector::max_size
@brief  Returns the maximum number of elements that the %circular_vector can hold during dynamic allocation mode
@return  Read-only (constant) maximum size
`size_type max_size() const;`

circular_vector::resize
@brief  Resizes the %circular_vector to specified size
@param  n  Number of elements the %circular_vector should contain.
@param  val  The value of the element to fill the extra size
@warn  This function changes the actual content of the container by inserting or erasing elements from it (unless @a n = size()). If the number is smaller than the %circular_vector's current size the %circular_vector is truncated, otherwise default (or specified) elements are appended until size reaches @a n size. If capacity needs to increase => capacity becomes @a n. Capacity never shrinks.
  `void resize(size_type n, const value_type &val = value_type());`

circular_vector::capacity
@brief  Returns size of allocated storage capacity
`size_type capacity() const;`

circular_vector::empty
@brief  Returns true if there are elements in the %circular_vector
@return  Read-only (constant) True iff end index is in default state 
`bool empty() const;`

circular_vector::reserve
@brief  Request that the %circular_vector capacity be at least enough to contain @a n elements. This function has no effect on the %circular_vector size and cannot alter its elements.
@warn  If @a n is greater than the current %circular_vector capacity, the function causes the container to reallocate its storage increasing its capacity to @a n (or greater). O(n) time and space required when this occurs
`void reserve(size_type n);`

#MODIFIERS:#
circular_vector::assign
@brief  Fills a %circular_vector with copies of the elements in the range \[start, last)
@param  start  An input iterator
@param  last   An input iterator
@warn  The assignment completely changes the %circular_vector and the resulting %circular_vector's size is the same as the number of elements assigned. Old data will be lost.
`template <typename iter>
  void assign(iter start, iter last);`

circular_vector::assign
@brief  Fills a %circular_vector with the specified value in the range \[0, n)
@param  n    Number of elements to be assigned
@param  val  Value to be assigned
@warn  The assignment completely changes the %circular_vector and the resulting %circular_vector's size is the same as the number of elements assigned. Old data will be lost.
`void assign(size_type n, const value_type &val);`

circular_vector::pop_front
@brief  Removes the first indexed element
@warn  Undefined behaviour when calling on an empty %circular_vector
`void pop_front();`

circular_vector::pop_back
@brief  Removes the last indexed element
@warn  Undefined behaviour when calling on an empty %circular_vector
`void pop_back();`

circular_vector::push_front
@brief  Adds an element to the head of the %circular_vector and decrements the start index
@param  val  Element to be added
@warn  If capacity has been reached, the function causes the container to reallocate its storage increasing its capacity to 1.5 * capacity. O(n) time and space required when this occurs.
`void push_front(const value_type &val);`

circular_vector::push_back
@brief  Adds an element to the tail of the %circular_vector
@param  val  Element to be added
@warn  If capacity has been reached, the function causes the container to reallocate its storage increasing its capacity to 1.5 * capacity. O(n) time and space required when this occurs.
`void push_back(const value_type &val);`

circular_vector::swap
@brief  Exchanges the content of the container by the content of x, which is another %circular_vector object of the same type. Sizes may differ.
@param  x  The %circular_vector of the same type to swap with.
`void swap(circular_vector &x);`

circular_vector::clear
@brief  Removes all elements from the @circular_vector (which are destroyed), leaving the container with a size of 0.
@warn  If the elements themselves are pointers, the pointed-to memory is not touched in any way. Managing the pointer is the user's responsibility.
`void clear();`

#ELEMENT ACCESS:#
circular_vector::operator[]
@brief  Provides access to the data contained in %circular_vector
@param n The index of the element for which data should be accessed
@return  Read/write reference to data
@warn  Calling this function with an argument @a n that is out of range causes undefined behaviour.
`reference operator [] (size_type n);`

circular_vector::operator[]
@brief  Provides access to the data contained in %circular_vector
@param n The index of the element for which data should be accessed
@return  Read/write reference to data
@warn  Calling this function with an argument @a n that is out of range causes undefined behaviour
`const_reference operator [] (size_type n) const;`

circular_vector::at
@brief  Provides access to the data contained in %circular_vector
@param n The index of the element for which data should be accessed
@return  Read/write reference to data
@throw  std::out_of_range  If @a n is an invalid index
`reference at(size_type n);`

circular_vector::at
@brief  Provides access to the data contained in %circular_vector
@param n The index of the element for which data should be accessed
@return  Read-only (constant) reference to data
@throw  std::out_of_range  If @a n is an invalid index
`const_reference at(size_type n) const;`

circular_vector::front
@return  Read/Write reference to the first indexed element in %circular_vector
@warn  Calling this function on an empty container causes undefined behaviour
`reference front();`

circular_vector::front
@return  Read-only (constant) reference to the first indexed element  in %circular_vector
@warn  Calling this function on an empty container causes undefined behaviour
`const_reference front() const;`

circular_vector::back
@return  Read/Write reference to the last indexed element  in %circular_vector
@warn  Calling this function on an empty container causes undefined behaviour
`reference back();`

circular_vector::back
@return  Read-only (constant) reference to the last indexed element  in %circular_vector
@warn  Calling this function on an empty container causes undefined behaviour
`const_reference back() const;`
