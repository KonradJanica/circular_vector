##CIRCULAR_VECTOR##
An STL-Compliant Circular Vector (Container) Data Structure written in C++

Shares similaries to a Circular Buffer Data Structure, except allows access to all elements in the container.

Contains all the same member functions as C++98 std::vector from the STL, except for vector::insert and vector::erase. Newly introduced member functions include: push_front and pop_front which unlike the counterpart operations in std::vector are O(1) time (Constant).

##CONSTRUCTORS:##
**<dt>circular_vector::_circular_vector_</dt>**
`explicit circular_vector(size_type capacity = kDefaultCapacity);`
<dd><em>@brief</em>  <ul>Empty container constructor (default constructor). Constructs an empty container, with no elements. With a specified amount of reserved space.</ul></dd>
<dd><em>@param  capacity</em>  <ul>The starting allocated storage reserve</ul></dd>
<dd><em>@throws  std::invalid_argument</em>  <ul>With negative capacity values</ul></dd>

**<dt>circular_vector::_circular_vector_</dt>**
`explicit circular_vector(size_type n, const value_type &val, const allocator_type &alloc = allocator_type());`
<dd><em>@brief</em>  <ul>Fill constructor. Constructs a container with @a n elements. Each element is a copy of @a val.</ul></dd>
<dd><em>@param  n    The size and</em> <ul>capacity of the %circular_vector</ul></dd>
<dd><em>@param  val  The data</em> <ul>value to fill the %circular_vector</ul></dd>
<dd><em>@throws  std::invalid_argument</em>  <ul>With negative size values</ul></dd>

**<dt>circular_vector::_circular_vector_</dt>**
`template <class InputIterator>;`
`circular_vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());`
<dd><em>@brief</em>  <ul>Range constructor. Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.</ul></dd>
<dd><em>@param  first  The initial</em> <ul>position to start the copy from</ul></dd>
<dd><em>@param  last   The final</em> <ul>exclusive position of the copy range</ul></dd>

**<dt>circular_vector::_circular_vector_</dt>**
`circular_vector(const circular_vector &x);`
<dd><em>@brief</em>  <ul>Copy constructor. Constructs a container with a copy of each of the elements in x, in the same order.</ul></dd>
<dd><em>@param  x  Another vector object</em> <ul>of the same type (with the same class template arguments T and Alloc), whose contents are copied.</ul></dd>
<dd><em>@throws  std::length_error</em>  <ul>Upon catching any exception while assigning memory</ul></dd>

**<dt>circular_vector::_operator=_</dt>**
`circular_vector &operator = (const self_type &x);;`
<dd><em>@brief</em>  <ul>Move constructor. Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.</ul></dd>
<dd><em>@param  x  A vector object</em> <ul>of the same type (i.e., with the same template parameters, T and Alloc).</ul></dd>

##DESTRUCTORS:##
**<dt>circular_vector::_~circular_vector_</dt>**
<dd><em>@brief</em>  <ul>Destroys all container elements, and deallocates all the storage capacity allocated by the vector using its allocator.</ul>

##ITERATORS:##
**<dt>circular_vector::_begin_</dt>**
<dd>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<code>iterator begin();</code></dd>
`const_iterator begin() const;`
<dd><em>@brief</em>  <ul>An iterator pointing to array\_[0], i.e. the first element</ul></dd>
<dd><em>@warn</em>  <ul>Iterator should be repositioned upon capacity reallocation or after push_front call</ul></dd>


**<dt>circular_vector::_end_</dt>**
<dd>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<code>iterator end();</code></dd>
`const_iterator end() const;`
<dd><em>@brief</em>  <ul>An iterator pointing to array\_[size()], i.e. past-the-end element</ul>
<dd><em>@warn</em>  <ul>Iterator should be repositioned upon capacity reallocation or after push_back call</ul>

**<dt>circular_vector::_rbegin_</dt>**
<dd>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<code>reverse_iterator rbegin();</code></dd>
`const_reverse_iterator rbegin() const;`
<dd><em>@brief</em>  <ul>Returns a reverse iterator pointing to the last element in the vector (i.e., its reverse beginning). Reverse iterators iterate backwards: increasing them moves them towards the beginning of the container. rbegin points to the element right before the one that would be pointed to by member end. Notice that unlike member vector::back, which returns a reference to this same element, this function returns a reverse random access iterator.</ul>
<dd><em>@warn</em>  <ul>Iterator should be repositioned upon capacity reallocation or after push_back call</ul>

**<dt>circular_vector::_rend_</dt>**
<dd>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<code>reverse_iterator rend();</code></dd>
`const_reverse_iterator rend() const;`
<dd><em>@brief</em>  <ul>Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (which is considered its reverse end). The range between vector::rbegin and vector::rend contains all the elements of the vector (in reverse order).</ul>
<dd><em>@warn</em>  <ul>Iterator should be repositioned upon capacity reallocation or after push_front call</ul>

##ALLOCATORS:##
**<dt>circular_vector::_get_allocator_</dt>**
`allocator_type get_allocator() const;`
<dd><em>@brief</em> <ul>Returns a copy of the allocator object associated with the @circular_vector</ul></dd>
<dd><em>@return</em> <ul>  Read-only (constant) allocator</ul></dd>

##CAPACITIES:##
**<dt>circular_vector::_size_</dt>**
`size_type size() const;`
<dd><em>@brief</em> <ul>Returns the amount of elements in the %circular_vector</ul></dd>
<dd><em>@return</em> <ul>Read-only (constant) circular size</ul></dd>

**<dt>circular_vector::_max_size_</dt>**
`size_type max_size() const;`
<dd><em>@brief</em> <ul>Returns the maximum number of elements that the %circular_vector can hold during dynamic allocation mode</ul></dd>
<dd><em>@return</em> <ul>Read-only (constant) maximum size</ul></dd>

**<dt>circular_vector::_resize_</dt>**
`void resize(size_type n, const value_type &val = value_type());`
<dd><em>@brief</em>  <ul>Resizes the %circular_vector to specified size</ul>
<dd><em>@param  n</em>  <ul>Number of elements the %circular_vector should contain.</ul>
<dd><em>@param  val</em>  <ul>The value of the element to fill the extra size</ul>
<dd><em>@warn</em>  <ul>This function changes the actual content of the container by inserting or erasing elements from it (unless @a n = size()). If the number is smaller than the %circular_vector's current size the %circular_vector is truncated, otherwise default (or specified) elements are appended until size reaches @a n size. If capacity needs to increase => capacity becomes @a n. Capacity never shrinks.</ul>

**<dt>circular_vector::_capacity_</dt>**
`size_type capacity() const;`
<dd><em>@brief</em>  <ul>Returns size of allocated storage capacity</ul>

**<dt>circular_vector::_empty_</dt>**
`bool empty() const;`
<dd><em>@brief</em> <ul>Returns true if there are elements in the %circular_vector</ul></dd>
<dd><em>@return</em> <ul>  Read-only (constant) True iff end index is in default state </ul></dd>

**<dt>circular_vector::_reserve_</dt>**
`void reserve(size_type n);`
<dd><em>@brief</em>  <ul>Request that the %circular_vector capacity be at least enough to contain @a n elements. This function has no effect on the %circular_vector size and cannot alter its elements.</ul>
<dd><em>@warn</em>  <ul>If @a n is greater than the current %circular_vector capacity, the function causes the container to reallocate its storage increasing its capacity to @a n (or greater). O(n) time and space required when this occurs</ul>

##MODIFIERS:##
**<dt>circular_vector::_assign_</dt>**
`template <typename iter>
  void assign(iter start, iter last);`
<dd><em>@brief</em>  <ul>Fills a %circular_vector with copies of the elements in the range \[start, last)</ul>
<dd><em>@param  start</em>  <ul>An input iterator</ul>
<dd><em>@param  last</em>  <ul> An input iterator</ul>
<dd><em>@warn</em>  <ul>The assignment completely changes the %circular_vector and the resulting %circular_vector's size is the same as the number of elements assigned. Old data will be lost.</ul>

**<dt>circular_vector::_assign_</dt>**
<dd><em>@brief</em>  <ul>Fills a %circular_vector with the specified value in the range \[0, n)</ul>
<dd><em>@param  n</em>    <ul>Number of elements to be assigned</ul>
<dd><em>@param  val</em>  <ul>Value to be assigned</ul>
<dd><em>@warn</em>  <ul>The assignment completely changes the %circular_vector and the resulting %circular_vector's size is the same as the number of elements assigned. Old data will be lost.</ul>
`void assign(size_type n, const value_type &val);`

**<dt>circular_vector::_pop_front_</dt>**
`void pop_front();`
<dd><em>@brief</em> <ul>Removes the first indexed element</ul></dd>
<dd><em>@warn</em> <ul>Undefined behaviour when calling on an empty %circular_vector</ul></dd>

**<dt>circular_vector::_pop_back_</dt>**
`void pop_back();`
<dd><em>@brief</em> <ul>Removes the last indexed element</ul></dd>
<dd><em>@warn</em> <ul>Undefined behaviour when calling on an empty %circular_vector</ul></dd>

**<dt>circular_vector::_push_front_</dt>**
`void push_front(const value_type &val);`
<dd><em>@brief</em>  <ul>Adds an element to the head of the %circular_vector and decrements the start index</ul>
<dd><em>@param  val</em>  <ul>Element to be added</ul>
<dd><em>@warn</em>  <ul>If capacity has been reached, the function causes the container to reallocate its storage increasing its capacity to 1.5 * capacity. O(n) time and space required when this occurs.</ul>

**<dt>circular_vector::_push_back_</dt>**
`void push_back(const value_type &val);`
<dd><em>@brief</em>  <ul>Adds an element to the tail of the %circular_vector</ul>
<dd><em>@param  val</em>  <ul>Element to be added</ul>
<dd><em>@warn</em>  <ul>If capacity has been reached, the function causes the container to reallocate its storage increasing its capacity to 1.5 * capacity. O(n) time and space required when this occurs.</ul>

**<dt>circular_vector::_swap_</dt>**
`void swap(circular_vector &x);`
<dd><em>@brief</em>  <ul>Exchanges the content of the container by the content of x, which is another %circular_vector object of the same type. Sizes may differ.</ul>
<dd><em>@param  x</em>  <ul>The %circular_vector of the same type to swap with.</ul>

**<dt>circular_vector::_clear_</dt>**
`void clear();`
<dd><em>@brief</em> <ul>Removes all elements from the @circular_vector (which are destroyed), leaving the container with a size of 0.</ul></dd>
<dd><em>@warn</em> <ul>If the elements themselves are pointers, the pointed-to memory is not touched in any way. Managing the pointer is the user's responsibility.</ul></dd>

##ELEMENT ACCESS:##
**<dt>circular_vector::_operator[]_</dt>**
`reference operator [] (size_type n);`
<dd><em>@brief</em>  <ul>Provides access to the data contained in %circular_vector</ul>
<dd><em>@param n</em> <ul>The index of the element for which data should be accessed</ul>
<dd><em>@return</em>  <ul>Read/write reference to data</ul>
<dd><em>@warn</em>  <ul>Calling this function with an argument @a n that is out of range causes undefined behaviour.</ul>

**<dt>circular_vector::_operator[]_</dt>**
`const_reference operator [] (size_type n) const;`
<dd><em>@brief</em>  <ul>Provides access to the data contained in %circular_vector</ul>
<dd><em>@param n</em> <ul>The index of the element for which data should be accessed</ul>
<dd><em>@return</em>  <ul>Read/write reference to data</ul>
<dd><em>@warn</em>  <ul>Calling this function with an argument @a n that is out of range causes undefined behaviour</ul>

**<dt>circular_vector::_at_</dt>**
`reference at(size_type n);`
<dd><em>@brief</em>  <ul>Provides access to the data contained in %circular_vector</ul>
<dd><em>@param n</em> <ul>The index of the element for which data should be accessed</ul>
<dd><em>@return</em>  <ul>Read/write reference to data</ul>
<dd><em>@throw  std::out_of_range</em><ul>If @a n is an invalid index</ul>

**<dt>circular_vector::_at_</dt>**
`const_reference at(size_type n) const;`
<dd><em>@brief</em>  <ul>Provides access to the data contained in %circular_vector</ul>
<dd><em>@param n</em> <ul>The index of the element for which data should be accessed</ul>
<dd><em>@return</em>  <ul>Read-only (constant) reference to data</ul>
<dd><em>@throw  std::out_of_range</em> <ul>If @a n is an invalid index</ul>

**<dt>circular_vector::_front_</dt>**
`reference front();`
<dd><em>@return</em>  <ul>Read/Write reference to the first indexed element in %circular_vector</ul>
<dd><em>@warn</em>  <ul>Calling this function on an empty container causes undefined behaviour</ul>

**<dt>circular_vector::_front_</dt>**
`const_reference front() const;`
<dd><em>@return</em>  <ul>Read-only (constant) reference to the first indexed element  in %circular_vector</ul>
<dd><em>@warn</em>  <ul>Calling this function on an empty container causes undefined behaviour</ul>

**<dt>circular_vector::_back_</dt>**
`reference back();`
<dd><em>@return</em>  <ul>Read/Write reference to the last indexed element  in %circular_vector</ul>
<dd><em>@warn</em>  <ul>Calling this function on an empty container causes undefined behaviour</ul>

**<dt>circular_vector::_back_</dt>**
`const_reference back() const;`
<dd><em>@return</em>  <ul>Read-only (constant) reference to the last indexed element  in %circular_vector</ul>
<dd><em>@warn</em>  <ul>Calling this function on an empty container causes undefined behaviour</ul>
