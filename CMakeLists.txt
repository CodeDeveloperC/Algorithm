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
        #NonRecursive.cpp myQSort.cpp ByMeter.cpp
        #randSelect.cpp patb1019.cpp codeUp1818.cpp
        #Fraction.cpp prime.cpp prime2.cpp NMPrime.cpp
        #Factorfactordecomposition.cpp bigNumber.cpp
        #Euclid.cpp vector.cpp BinaryTree.cpp
        #BinaryTreeLayer.cpp StaticTree.cpp p305.cpp
        #BST.cpp p317.cpp BalanceTree.cpp dfs.cpp
        #p273.cpp bfs.cpp maze.cpp note.cpp operator.cpp
        #Link.cpp 01Package.cpp p333.cpp heap.cpp
#        Huffman.cpp GraphDFS.cpp GrapthDFSVector.cpp
#        p357.cpp GraphBFS.cpp dijkstra.cpp
#        "Adjacency table.cpp" CCF/MA.cpp
#        CCF/4.cpp CCF/4.1.cpp
        CCF/4.2.cpp)
add_executable(Algorithm ${SOURCE_FILES})