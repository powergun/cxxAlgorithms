add_executable(partition_stable_partition stable_partition.cpp)
target_link_libraries(partition_stable_partition PRIVATE doctest)
add_test(NAME "partition::stable-partition" COMMAND partition_stable_partition)

add_executable(partition_copy partition_copy.cpp)
target_link_libraries(partition_copy PRIVATE doctest)
add_test(NAME "partition::partition-copy" COMMAND partition_copy)

add_executable(partition_split split.cpp)
target_link_libraries(partition_split PRIVATE doctest)
target_include_directories(partition_split PRIVATE ${Boost_INCLUDE_DIRS})
add_test(NAME "partition::split" COMMAND partition_split)

add_executable(partition_gather gather.cpp)
target_link_libraries(partition_gather PRIVATE doctest)
add_test(NAME "partition::gather" COMMAND partition_gather)

add_executable(partition_remove_multi_whitespace remove_multi_whitespace.cpp)
target_link_libraries(partition_remove_multi_whitespace PRIVATE doctest)
add_test(NAME "partition::uniq-remove-whitespace" COMMAND partition_remove_multi_whitespace)
