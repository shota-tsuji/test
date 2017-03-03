template <typename T>
class Stack {
public:
  explicit Stack( std::size_t capacity );
  ~Stack();

  void Push( const T& data );
  void Pop();
  inline const T Top() const
  {
    return mData[ mSP - 1 ];
  }

  inline std::size_t GetSize() const
  {
    return mSP;
  }
  inline std::size_t GetCapacity() const
  {
    return mCapacity;
  }

private:
  const std::size_t mCapacity;
  T* mData;
  int mSP;
};

// 分からないこと
// explicit
// inline
// あとにつくconst
// std::size_t

template <typename T>
Stack<T>::Stack( std::size_t capacity ) :
  mCapacity( capacity ),
  mData( new T[ capacity ] ),
  mSP( 0 );
{
}

template <typename T>
Stack<T>::~Stack()
{
  delete [] mData;
}

template <typename T>
void Stack<T>::Push( const T& data )
{
  assert( static_cast<std::size_t>( mSP ) < mCapacity );
  mData[ mSP ] = data;
  mSP++;
}

template <typename T>
void Stack<T>::Pop()
{
  assert( mSP > 0 );
  mSP--;
}
