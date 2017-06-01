#include "ostream"
#include "rational.hpp"
#include "vector.hpp"

// needed to get Catch working with MinGW
#define TWOBLUECUBES_CATCH_REPORTER_JUNIT_HPP_INCLUDED
namespace Catch{ class JunitReporter{ ~JunitReporter(); }; };

#include "catch_with_main.hpp"

//test cases for vector
TEST_CASE( "vector, constructor, two_parameters" ){
   vector x( 3, 4 );
   std::stringstream s;
   s << x;
   REQUIRE( s.str() == "[3,4]" );   
}

TEST_CASE( "vector, equality, equal" ){
   vector x( 3, 4 );
   REQUIRE(x == vector(3, 4));   
}

TEST_CASE( "vector, add 2 vectors" ){
   vector x(3, 4);
   vector y(2, 1);
   x = x + y;
   REQUIRE( x == vector(5, 5) );   
}

TEST_CASE( "vector, monadic +operator"){
   vector x(3, 4);
   vector y(2, 1);
   x = + y;
   REQUIRE( x == vector(2, 1) );   
}

TEST_CASE( "vector, add vector into vector" ){
   vector x( 3, 4 );
   x += vector(2, 1);
   REQUIRE(x == vector(5, 5));   
}

TEST_CASE( "vector, multiply 2 vectors" ){
   vector x( 3, 4 );
   vector y = x * vector(2, 2);
   REQUIRE(y == vector(6, 8));   
}

TEST_CASE( "vector, a vector by a integer" ){
   vector x( 3, 4 );
   vector y = x * 2;
   REQUIRE(y == vector(6, 8));   
}

TEST_CASE( "vector, multiply vector into vector" ){
   vector x( 3, 4 );
   x *= vector(2, 2);
   REQUIRE(x == vector(6, 8));   
}

//test case for rational
TEST_CASE( "constructor, two_parameters" ){
   rational v( 3, 4 );
   std::stringstream s;
   s << v;
   REQUIRE( s.str() == "[3/4]" );   
}

TEST_CASE( "equality, equal" ){
   rational v( 1, 2 );
   REQUIRE( v == rational( 1, 2 ) ); 
}

TEST_CASE( "equality, unequal" ){
   rational v( 1, 2 );
   REQUIRE( ! ( v == rational( 1, 3 )) ); 
}

TEST_CASE( "constructor, two_parameters; reduction" ){
   rational v( 10, 2 );
   REQUIRE( v == rational( 5, 1 ) ); 
}

TEST_CASE( "constructor, one parameter" ){
   rational v( 6 );
   REQUIRE( v == rational( 6, 1 ) );   
}

TEST_CASE( "multiply by integer" ){
   rational v( 3, 4 );
   rational x = v * 7;
   REQUIRE( v == rational( 3, 4 ) );   
   REQUIRE( x == rational( 21, 4 ) );   
}


TEST_CASE( "multiply by integer; reduction" ){
   rational v( 3, 10 );
   rational x = v * 5;
   REQUIRE( v == rational( 3, 10 ) );   
   REQUIRE( x == rational( 3, 2 ) );   
}

TEST_CASE( "multiply by rational" ){
   rational v( 3, 4 );
   rational x = v * rational( 9, 7 );
   REQUIRE( v == rational( 3, 4 ) );   
   REQUIRE( x == rational( 27, 28 ) );   
}

TEST_CASE( "multiply by rational; reduction" ){
   rational v( 3, 10 );
   rational x = v * rational( 4, 6 );
   REQUIRE( v == rational( 3, 10 ) );   
   REQUIRE( x == rational( 1, 5 ) );   
}

TEST_CASE( "add rational into rational" ){
   rational v( 3, 10 );
   v += rational( 6, 7 ); 
   REQUIRE( v == rational( 81, 70 ) );     
}

TEST_CASE( "add rational into rational; reduction" ){
   rational v( 23, 147 );
   v += rational( 5, 91 ); 
   REQUIRE( v == rational( 404, 1911 ) );     
}

TEST_CASE( "add rational into rational; return value" ){
   rational v( 1, 2 );
   rational x = ( v += rational( 1, 4 )); 
   REQUIRE( v == rational( 3, 4 ) );     
   REQUIRE( x == rational( 3, 4 ) );     
}

TEST_CASE( "multiply rational into rational" ){
   rational v( 3, 10 );
   v *= rational( 1, 2 ); 
   REQUIRE( v == rational( 3, 20 ) );     
}

TEST_CASE( "multiply rational into rational; reduction" ){
   rational v( 2, 3 );
   v *= rational( 3, 2 ); 
   REQUIRE( v == rational( 1, 1 ) );     
}

TEST_CASE( "multiply rational into rational; return value" ){
   rational v( 3, 10 );
   rational x = ( v *= rational( 1, 2 )); 
   REQUIRE( x == rational( 3, 20 ) );     
}






