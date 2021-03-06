#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include <vector>
#include <algorithm>

#include <cassert>
// source
// more exception item 2 P10
// std::advance() is aware of the category of the iterator, hence able
// to optimize for random-access iter
//
// see std_remove example for how it helps to implement remove-Nth-elem
TEST_CASE( "test_advance_optimal()" )
{
    std::vector< int > v{ 1, 2, 3, 4, 5, 6, 7, 8 };
    auto i = v.begin();
    std::advance( i, 6 );
    assert( 7 == *i );
}
