cmake_minimum_required(VERSION 3.5)
project(ProblemsImplementation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DP/practise.h DP/Matrix2D.h
        DP/MinimumCostPolygonTringulation.h
        DP/MinimumInitialPointsToReachDestination.h DP/CountOfSumWhoseSumIsN.h
        DP/CountNumberOfNonDecreasingDigits.h LinkedList/SwapNodes.h TEMPLATE.h Graph/OLD/GRAPH_OLD.h
        GRAPH.h Graph/OLD/GraphTraversal.h Graph/GraphOperations.h Apac2.h Graph_Nirav_Template.h GraphChanged.h BinaryTree/BTree.h)

add_executable(ProblemsImplementation ${SOURCE_FILES}
        DP/practise.h DP/Matrix2D.h
        DP/MinimumCostPolygonTringulation.h
        DP/MinimumInitialPointsToReachDestination.h DP/CountOfSumWhoseSumIsN.h
        DP/CountNumberOfNonDecreasingDigits.h LinkedList/SwapNodes.h TEMPLATE.h Graph/OLD/GRAPH_OLD.h
        GRAPH.h Graph/OLD/GraphTraversal.h Graph/GraphOperations.h Apac2.h Graph_Nirav_Template.h GraphChanged.h BinaryTree/BTree.h)


#TEMPLATE.h GRAPH.h