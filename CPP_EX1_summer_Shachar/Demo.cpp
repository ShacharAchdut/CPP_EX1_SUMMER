/*
 * Demo program for Exercise 3.
 * Author: Benjamin Saldman.
 */

#include "Graph.hpp"
#include "Algorithms.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{

    //+ operator ##############################################################################################

    Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph); // Load the graph to the object.
    cout << "print g1:\n" << g1 << "\n";
    // g1.printGraph();
    // cout << "\n";

    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    Graph g2;
    g2.loadGraph(weightedGraph); // Load the graph to the object.
    cout << "print g2:\n" << g2 << "\n";
    // g2.printGraph();
    // cout << "\n";

    Graph g3 = g1 + g2; // Add the two graphs together.
    cout << "Add g1 + g2 graphs together:\n" << g3 << "\n";
    // g3.printGraph();           // Should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]
    // cout << "\n";



    // //+= operator ###########################################################################################
    
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph1);
    cout << "print g1:\n" << g1 << "\n";
    // g1.printGraph();
    // cout << "\n";

    std::vector<std::vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 0}
    };
    g2.loadGraph(graph2);
    cout << "print g2:\n" << g2 << "\n";
    // g2.printGraph();
    // cout << "\n";

    // Add the second graph to the first graph using the += operator
    g1 += g2;
    cout << "Add g1 += g2 graphs together:\n" << g1 << "\n"; // Should print the matrix of the graph: [0, 2, 1],[2, 0, 1],[1, 1, 0]

    // Print the resulting graph
    // g1.printGraph();
    // cout << "\n";
    

    //plus unri operator #######################################################################################

    std::vector<std::vector<int>> graph3 = {
        {0, -1, 0},
        {-1, 0, -1},
        {0, 1, 0}
    };
    g1.loadGraph(graph3);

    cout << "befor plus unri operator:\n" << g1 << "\n";
    // g1.printGraph(); // Should print the matrix of the graph: [0, -1, 0], [-1, 0, -1], [0, 1, 0]
    // cout << "\n";

    g1 = +g1;
    cout << "after plus unri operator:\n" << g1 << "\n";
    // g1.printGraph(); // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]
    // cout << "\n";


    
    //- operator ##############################################################################################

    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph4); // Load the graph to the object.

    vector<vector<int>> weightedGraph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph2); // Load the graph to the object.

    g3 = g1 - g2; // - the two graphs together.
    cout << "g1 - g2 graphs:\n" << g3 << "\n";
    // g3.printGraph();           // Should print the matrix of the graph: [0, 0, -1], [0, 0, -1], [-1, -1, 0]
    // cout << "\n";



    //-= operator ##################################################################################################
    std::vector<std::vector<int>> graph5 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph5);

    std::vector<std::vector<int>> graph6 = {
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 0}
    };
    g2.loadGraph(graph6);

    // Add the second graph to the first graph using the -= operator
    cout << "g1 -= g2 graphs:\n" << g1 << "\n";
    g1 -= g2;

    // Print the resulting graph
    // g1.printGraph(); // Should print the matrix of the graph: [0, 0, -1],[0, 0, 1],[-1, 1, 0]
    // cout << "\n";
    

    //- unri operator ##########################################################################################
    std::vector<std::vector<int>> graph7 = {
        {0, 1, 0},
        {-1, 0, -1},
        {0, 1, 0}
    };

    g1.loadGraph(graph7);

    cout << "befor minus unri operator:\n" << g1 << "\n";
    // g1.printGraph(); // Should print the matrix of the graph: [0, 1, 0], [-1, 0, -1], [0, 1, 0]
    // cout << "\n";

    g1 = -g1;
    cout << "after minus unri operator:\n" << g1 << "\n";
    // g1.printGraph(); // Should print the matrix of the graph: [0, -1, 0], [-1, 0,-1], [0,-1, 0]
    // cout << "\n";


    // ++operator ##########################################################################################

    vector<vector<int>> graph8 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph8); // Load the graph to the object.

    cout << "befor ++ operator:\n" << g1 << "\n";
    // g1.printGraph(); // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]
    // cout << "\n";

    g1 = ++g1;

    cout << "after ++ operator:\n" << g1 << "\n";
    // g1.printGraph(); // Should print the matrix of the graph: [1, 2, 1], [2, 1, 2], [1, 2, 1]
    // cout << "\n";

    // --operator ##########################################################################################


    g1 = --g1;
    cout << "after -- operator:\n" << g1 << "\n";
    // g1.printGraph(); // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]
    // cout << "\n";


    // graph*k operator ##########################################################################################

    int k = 3;

    g1 = g1*k;
    cout << "after g1*3 operator:\n" << g1 << "\n";
    // g1.printGraph(); // Should print the matrix of the graph: [0, 3, 0], [3, 0, 3], [0, 3, 0]
    // cout << "\n";

    // graph/k operator ##########################################################################################

    g1 = g1/k;
    cout << "after g1/3 operator:\n" << g1 << "\n";
    // g1.printGraph(); // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]
    // cout << "\n";

    // graph*-2 operator ##########################################################################################

    g1 = g1*-2;        // Multiply the graph by -2.
    cout << "after g1*-2 operator:\n" << g1 << "\n";
    // g1.printGraph(); // Should print the matrix of the graph: [0, -2, 0], [-2, 0, -2], [0, -2, 0]
    // cout << "\n";

    // graph/-2 operator ##########################################################################################

    g1 = g1/-2;
    cout << "after g1/-2 operator:\n" << g1 << "\n";
    // g1.printGraph(); // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]
    // cout << "\n";

    //* graphs g1 * g2 ####################################################################################

    vector<vector<int>> graph9 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph9); // Load the graph to the object. 
    cout << "print g1:\n" << g1 << "\n";
    // g1.printGraph();
    // cout << "\n";

    vector<vector<int>> graph10 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 2}};
    g2.loadGraph(graph10); // Load the graph to the object.
    cout << "print g2:\n" << g2 << "\n";
    // g2.printGraph();
    // cout << "\n";



    Graph g4 = g1 * g2; // Multiply the two graphs together.
    cout << "mult g1 * g2 graphs:\n" << g4 << "\n";
    // g4.printGraph();  // Should print the multiplication of the matrices of g1 and g2: [0, 2, 0], [2, 0, 2], [0, 2, 0]
    // cout << "\n";

    vector<vector<int>> graph11 = {
        {0, 1, 0},
        {1, 0, 2},
        {0, 1, 0}};
    g1.loadGraph(graph11); // Load the graph to the object. 
    cout << "print g1:\n" << g1 << "\n";

    Graph g5;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph12 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 3},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph12); // Load the graph to the object.
    cout << "print g2:\n" << g5 << "\n";
    // g5.printGraph();
    // cout << "\n";
    bool t = g5 > g1;
    cout << "print g2>g1:\n" << t << "\n";
    
    try
    {
        cout << "try to mult g1 * g2 graphs:\n";
        
        Graph g6 = g5 * g1; // Multiply the two graphs together.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print "The number of columns in the first matrix must be equal to the number of rows in the second matrix."
    }
    return 0;
}