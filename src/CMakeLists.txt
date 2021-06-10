add_executable(Main main.cpp)
add_executable(Table CreateBenchTable.cpp)

target_link_libraries(Main PRIVATE MergeSortLib)
target_link_libraries(Table PRIVATE MergeSortLib)