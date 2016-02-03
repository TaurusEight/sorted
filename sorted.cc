

// Required header files
//-----------------------------------------------------------------------------
#include <list>
#include <iostream>


// Project NS
//-----------------------------------------------------------------------------
namespace proj {


  // Custom objects from STL
  typedef std::list< int > list;  // locally used list type
  typedef list::const_iterator citerator;  // custom iterator


  // Print out a list
  void dump( const char*, const list& );  // Print the list to standard out


  // Merge two sorted lists
  void merge( const list&, citerator, const list&, citerator, list& );


};  // end NS proj



// Print the list out
//-----------------------------------------------------------------------------
void proj::dump( const char* name, const proj::list& list ) {

  static char space = ' ';

  std::cout << name << ':' << space;
  for( auto iter : list )
    std::cout << iter << space;
  std::cout << std::endl;

};  // end dump


// Reqursively merge two sorted lists into a third
//-----------------------------------------------------------------------------
void proj::merge( const proj::list& one,
                  citerator ione,
                  const proj::list& two,
                  citerator itwo,
                  proj::list& three ) {

  // We have reached the end of both lists
  if ( ione == one.end() && ( itwo == two.end() ) ) return;

  int value = 0x0;

  if ( ione == one.end() ) {
    value = *itwo++;
  } else if ( itwo == two.end() ) {
    value = *ione++;
  } else if ( *ione <= *itwo ) {
    value = *ione++;
  } else {
    value = *itwo++;
  };

  proj::merge( one, ione, two, itwo, three );
  three.push_front( value );

};  // end proj::merge


// NS shorthand
//-----------------------------------------------------------------------------
using namespace std;  // standard library


// Start here!
//-----------------------------------------------------------------------------
int main( int, char*[] ) {

  proj::list one( { 1, 3, 5, 7 } );
  proj::list two( { 2, 4, 6, 8 } );
  proj::list three;

  proj::dump( "One", one );
  proj::dump( "Two", two );
  proj::merge( one, one.begin(), two, two.begin(), three );
  proj::dump( "Three", three );

  return 0x0;

};  // end main
