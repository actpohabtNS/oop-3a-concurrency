file(GLOB_RECURSE HEADER_FILES *.hpp)

file(GLOB_RECURSE SOURCE_FILES *.cpp)

add_library(MergeSortLib STATIC ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(MergeSortLib PUBLIC libfort::fort)

target_include_directories(MergeSortLib PUBLIC MergeSortLib)
set_target_properties(MergeSortLib PROPERTIES LINKER_LANGUAGE CXX)
