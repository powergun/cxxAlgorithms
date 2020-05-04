add_executable(iteration_custom_iterator custom_iterator.cpp)
target_link_libraries(iteration_custom_iterator PRIVATE doctest)
add_test(NAME "iteration::custom-iterator" COMMAND iteration_custom_iterator)

add_executable(iteration_custom_iterator_stl custom_iterator_stl.cpp)
target_link_libraries(iteration_custom_iterator_stl PRIVATE doctest)
add_test(NAME "iteration::custom-iterator-stl" COMMAND iteration_custom_iterator_stl)

add_executable(iteration_fib_iter fib_iter.cpp)
target_link_libraries(iteration_fib_iter PRIVATE doctest)
add_test(NAME "iteration::fibonacci-number-iterator" COMMAND iteration_fib_iter)

add_executable(iteration_zip_iter zip_iter.cpp)
target_link_libraries(iteration_zip_iter PRIVATE doctest)
target_include_directories(iteration_zip_iter PRIVATE ${Boost_INCLUDE_DIRS})
add_test(NAME "iteration::zip-iterators" COMMAND iteration_zip_iter)

add_executable(iteration_neighbour_elements iter_neighbour_elements.cpp)
target_link_libraries(iteration_neighbour_elements PRIVATE doctest)
target_include_directories(iteration_neighbour_elements PRIVATE ${Boost_INCLUDE_DIRS})
add_test(NAME "iteration::neighbour-elements" COMMAND iteration_neighbour_elements)