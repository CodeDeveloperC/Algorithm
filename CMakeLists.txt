cmake_minimum_required(VERSION 3.7)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        #hash.cpp

        #StringHash.cpp
        #Allarranged.cpp
       # NQueue.cpp
        #NQueue2.cpp
       # greedy.cpp
        #patb1023.cpp
        #intervalGreedy.cpp
       # binarySearch.cpp
       # Fastpower.cpp
       # merge.cpp
        NonRecursive.cpp myQSort.cpp ByMeter.cpp randSelect.cpp patb1019.cpp codeUp1818.cpp Fraction.cpp prime.cpp prime2.cpp NMPrime.cpp Factorfactordecomposition.cpp)
add_executable(Algorithm ${SOURCE_FILES})