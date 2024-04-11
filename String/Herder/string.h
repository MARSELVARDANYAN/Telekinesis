#ifndef __STRING__
#define __STRING__
#include <iostream>

class STRING
{
private:
    char* arr;
    size_t sz;
    size_t cap;
    static const size_t npos = -1;

public:
    //Member types
    using value_type = char;
    using traits_type = char_traits<char>;
    using allocator_type = allocator<char>;
    using reference = char&;
    using const_reference = const char&;
    using pointer = char*;
    using const_pointer = const char*;
    //using iterator = a random access iterator to char (convertible to const_iterator);
    //using const_iterator = a random access iterator to const char;
    using reverse_iterator = reverse_iterator<iterator>;
    using const_reverse_iterator = reverse_iterator<const_iterator>;
    using difference_type = ptrdiff_t;
    using size_type = std::size_t;

public:
    //Member functions
    STRING();
    STRING( Allocator() );
    explicit STRING( const Allocator& alloc ) noexcept;
    STRING( Allocator() ) {}
    constexpr explicit STRING( const Allocator& alloc ) noexcept;
    //STRING( size_type count, CharT ch, const Allocator& alloc = Allocator() );
    constexpr STRING( size_type count, CharT ch, const Allocator& alloc = Allocator() );
    //STRING( const STRING& other, size_type pos, const Allocator& alloc = Allocator() );
    constexpr STRING(const STRING& other, size_type pos, const Allocator& alloc = Allocator() );
    constexpr STRING(STRING&& other, size_type pos, const Allocator& alloc = Allocator() );
    //STRING( const STRING& other, size_type pos, size_type count, const Allocator& alloc = Allocator() );
    constexpr STRING( const STRING& other, size_type pos, size_type count, const Allocator& alloc = Allocator() );
    constexpr STRING( STRING&& other, size_type pos, size_type count, const Allocator& alloc = Allocator() );
    //STRING( const CharT* s, size_type count, const Allocator& alloc = Allocator() );
    constexpr STRING( const CharT* s, size_type count, const Allocator& alloc = Allocator() );
    //STRING( const CharT* s, const Allocator& alloc = Allocator() );
    constexpr STRING( const CharT* s, const Allocator& alloc = Allocator() );
    template< class InputIt >
    STRING( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
    template< class InputIt >
    constexpr STRING( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
    //STRING( const STRING& other );
    constexpr STRING( const STRING& other );	
    //STRING( const STRING& other, const Allocator& alloc );
    constexpr STRING( const STRING& other, const Allocator& alloc );        
    //STRING( STRING&& other ) noexcept;
    constexpr STRING( STRING&& other ) noexcept;
    //STRING( STRING&& other, const Allocator& alloc );
    constexpr STRING( STRING&& other, const Allocator& alloc );	
    //STRING( std::initializer_list<CharT> ilist, const Allocator& alloc = Allocator() );
    constexpr STRING( std::initializer_list<CharT> ilist, const Allocator& alloc = Allocator() );
    ~STRING();
    STRING& operator= (const STRING& str);
    STRING& operator= (const char* s);	
    STRING& operator= (char c);	
    STRING& operator= (std::initializer_list<char> il);	
    STRING& operator= (STRING&& str) noexcept;
    STRING& assign (const STRING& str);	
    STRING& assign (const STRING& str, size_type subpos, size_type sublen = npos);	
    STRING& assign (const char* s);	
    STRING& assign (const char* s, size_type n);	
    STRING& assign (size_type n, char c);	
    template <class InputIterator>   
    STRING& assign (InputIterator first, InputIterator last);
    STRING& assign (std::initializer_list<char> il);	
    STRING& assign (STRING&& str) noexcept;
    //assign_range();
    allocator_type get_allocator() const noexcept;


public:
    //Element access
    //char& at (size_type pos);
    const char& at (size_type pos) const;
    //char& operator[] (size_type pos);
    const char& operator[] (size_type pos) const;
    //char& front();
    const char& front() const;
    //char& back();
    const char& back() const;
    const char* data() const noexcept;
    const char* c_str() const noexcept;
    //operator STRING_view();

public:
    //Iterators
    //iterator begin();
    const_iterator begin() const;
    const_iterator cbegin() const noexcept;
    //iterator end();
    const_iterator end() const;
    const_iterator cend() const noexcept;
    //reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator crbegin() const noexcept;
    //reverse_iterator rend() noexcept;
    const_reverse_iterator rend() const noexcept;
    const_reverse_iterator crend() const noexcept;

public:
    //Capacity
    bool empty() const noexcept;
    size_type length() const noexcept;
    size_type max_size() const noexcept;
    size_type size() const noexcept;
    size_type capacity() const noexcept;
    void resize (size_type n);
    void resize (size_type n, char c);
    void shrink_to_fit();

public:
    //Modifiers
    void clear() noexcept;
    STRING& insert (size_type pos, const STRING& str);	
    STRING& insert (size_type pos, const STRING& str, size_type subpos, size_type sublen = npos);	
    STRING& insert (size_type pos, const char* s);	
    STRING& insert (size_type pos, const char* s, size_type n);
    STRING& insert (size_type pos,   size_type n, char c);iterator insert (const_iterator p, size_type n, char c);	
    iterator insert (const_iterator p, char c);
    template <class InputIterator>
    iterator insert (iterator p, InputIterator first, InputIterator last);	
    STRING& insert (const_iterator p, std::initializer_list<char> il);
    //template< container-compatible-range<CharT> R >
    //constexpr iterator insert_range( const_iterator pos, R&& rg );
    STRING& erase (size_type pos = 0, size_type len = npos);	
    iterator erase (const_iterator p);	
    iterator erase (const_iterator first, const_iterator last);
    void push_back (char c);
    void pop_back();
    STRING& append (const STRING& str);
    STRING& append (const STRING& str, size_type subpos, size_type sublen = npos);	
    STRING& append (const char* s);	
    STRING& append (const char* s, size_type n);
    STRING& append (size_type n, char c);	
    template <class InputIterator>   
    STRING& append (InputIterator first, InputIterator last);	
    STRING& append (std::initializer_list<char> il);
    //append_range();
    STRING& replace (size_type pos, size_type len, const STRING& str);
    STRING& replace (const_iterator i1, const_iterator i2, const STRING& str);	
    STRING& replace (size_type pos, size_type len, const STRING& str, size_type subpos, size_type sublen = npos);	
    STRING& replace (size_type pos, size_type len, const char* s);
    STRING& replace (const_iterator i1, const_iterator i2, const char* s);
    STRING& replace (size_type pos, size_type len, const char* s, size_type n);
    STRING& replace (const_iterator i1, const_iterator i2, const char* s, size_type n);
    STRING& replace (size_type pos, size_type len,  size_type n, char c);
    STRING& replace (const_iterator i1, const_iterator i2, size_type n, char c);
    template <class InputIterator>  
    STRING& replace (const_iterator i1, const_iterator i2, InputIterator first, InputIterator last);
    STRING& replace (const_iterator i1, const_iterator i2, std::initializer_list<char> il);
    //replace_with_range();
    size_type copy (char* s, size_type len, size_type pos = 0) const;
    void resize (size_type n);
    void resize (size_type n, char c);
    //resize_and_overwrite();
    void swap();
    STRING& operator+= (const STRING& str);
    STRING& operator+= (const char* s);
    STRING& operator+= (char c);	
    STRING& operator+= (std::initializer_list<char> il);

public:
    //Search
    size_type find (const STRING& str, size_type pos = 0) const noexcept;	
    size_type find (const char* s, size_type pos = 0) const;
    size_type find (const char* s, size_type pos, size_type n) const;
    size_type find (char c, size_type pos = 0) const noexcept;
    size_type rfind (const STRING& str, size_type pos = npos) const noexcept;	
    size_type rfind (const char* s, size_type pos = npos) const;
    size_type rfind (const char* s, size_type pos, size_type n) const;
    size_type rfind (char c, size_type pos = npos) const noexcept;
    size_t find_first_of (const STRING& str, size_type pos = 0) const noexcept;	
    size_type find_first_of (const char* s, size_type pos = 0) const;	
    size_type find_first_of (const char* s, size_type pos, size_type n) const;	
    size_type find_first_of (char c, size_type pos = 0) const noexcept;
    size_type find_first_not_of (const STRING& str, size_type pos = 0) const noexcept;	
    size_type find_first_not_of (const char* s, size_type pos = 0) const;
    size_type find_first_not_of (const char* s, size_type pos, size_type n) const;
    size_type find_first_not_of (char c, size_type pos = 0) const noexcept;
    size_type find_last_of (const STRING& str, size_type pos = npos) const noexcept;
    size_type find_last_of (const char* s, size_type pos = npos) const;	
    size_type find_last_of (const char* s, size_type pos, size_type n) const;	
    size_type find_last_of (char c, size_type pos = npos) const noexcept;
    size_type find_last_not_of (const STRING& str, size_type pos = npos) const noexcept;	
    size_type find_last_not_of (const char* s, size_type pos = npos) const;	
    size_type find_last_not_of (const char* s, size_type pos, size_type n) const;	
    size_type find_last_not_of (char c, size_type pos = npos) const noexcept;

};

//Non-member functions
operator+();
operator==();
operator!=();
operator<();
operator>();
operator<=();
operator>=();
operator<=>();

//Input/output
istream& operator>>(istream& is, STRING& str);
ostream& operator<<(ostream& os, const STRING& str);
constexpr std::string operator""s( const char* str, std::size_t len );

//Numeric conversins
int stoi( const std::string& str, std::size_t* pos = nullptr, int base = 10 );
int stoi( const std::wstring& str, std::size_t* pos = nullptr, int base = 10 );
long stol( const std::string& str, std::size_t* pos = nullptr, int base = 10 );
long stol ( const std::wstring& str, std::size_t* pos = nullptr, int base = 10 );
long long stoll( const std::string& str, std::size_t* pos = nullptr, int base = 10 );
long long stoll( const std::wstring& str, std::size_t* pos = nullptr, int base = 10 );
//
unsigned long stoul ( const std::string& str, std::size_t* pos = nullptr, int base = 10 );
unsigned long stoul ( const std::wstring& str, std::size_t* pos = nullptr, int base = 10 );
unsigned long long stoull( const std::string& str, std::size_t* pos = nullptr, int base = 10 );
unsigned long long stoull( const std::wstring& str, std::size_t* pos = nullptr, int base = 10 );
//
float stof ( const std::string& str, std::size_t* pos = nullptr );
float stof ( const std::wstring& str, std::size_t* pos = nullptr );
double stod ( const std::string& str, std::size_t* pos = nullptr );
double stod ( const std::wstring& str, std::size_t* pos = nullptr );
long double stold( const std::string& str, std::size_t* pos = nullptr );
long double stold( const std::wstring& str, std::size_t* pos = nullptr );
//
std::string to_string( int value );
std::string to_string( long value );
std::string to_string( long long value );
std::string to_string( unsigned value );
std::string to_string( unsigned long value );
std::string to_string( unsigned long long value );
std::string to_string( float value );
std::string to_string( double value );
std::string to_string( long double value );


#endif