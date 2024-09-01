#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition") {
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);

    Graph g3 = g1 + g2;

    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};

    REQUIRE(g3.getAdjMatrix() == expectedGraph);
}

TEST_CASE("Test graph addition - Commutative property") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    Graph result1 = g1 + g2;
    Graph result2 = g2 + g1;

    REQUIRE(result1.getAdjMatrix() == result2.getAdjMatrix());
}

TEST_CASE("Test graph addition - Identity element") {
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    Graph result = g1 + g1;
    vector<vector<int>> expectedGraph2 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    REQUIRE(result.getAdjMatrix() == expectedGraph2);
}

TEST_CASE("Test graph subtraction - Commutative property") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    vector<vector<int>> expectedGraph3 = {
        {0, 0, -1},
        {0, 0, -1},
        {-1, -1, 0}};

    Graph result1 = g1 - g2;

    REQUIRE(result1.getAdjMatrix() == expectedGraph3);
}

TEST_CASE("Test graph subtraction - Identity element") {
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    Graph result = g1 - g1;

    REQUIRE(result.getAdjMatrix() == vector<vector<int>>(3, vector<int>(3, 0)));
}

TEST_CASE("Test graph scalar multiplication - Identity element") {
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    Graph result = g1 * 1;

    REQUIRE(result.getAdjMatrix() == g1.getAdjMatrix());
}

TEST_CASE("Test graph equality operator - Same graph") {
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    Graph g2;
    g2.loadGraph(graph);

    REQUIRE(g1 == g2);
}

TEST_CASE("Test graph inequality operator - Different graph") {
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    REQUIRE_FALSE(g1 == g2);
}

TEST_CASE("Check undirected graph classification") {
    Graph g;
    vector<vector<int>> undirectedGraph = {{0, 1}, {1, 0}};
    g.loadGraph(undirectedGraph);
    CHECK(g.getDirected() == false);
}

TEST_CASE("Test graph addition - Associative property") {
    Graph g1, g2, g3, g4;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);
    g3.loadGraph(graph1);
    g4.loadGraph(graph2);

    Graph result1 = (g1 + g2) + g3;
    Graph result2 = g1 + (g2 + g3);

    REQUIRE(result1.getAdjMatrix() == result2.getAdjMatrix());
}

TEST_CASE("Test graph addition - Zero element") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph2 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    Graph result1 = g1 + g2;

    REQUIRE(result1.getAdjMatrix() == g1.getAdjMatrix());
}

TEST_CASE("Test graph subtraction - Zero element") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    Graph result1 = g1 - g2;

    REQUIRE(result1.getAdjMatrix() == vector<vector<int>>(3, vector<int>(3, 0)));
}

TEST_CASE("Test graph scalar multiplication - Commutative property") {
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    vector<vector<int>> expectedGraph3 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};

    Graph result1 = g1 * 2;

    REQUIRE(result1.getAdjMatrix() == expectedGraph3);
}

TEST_CASE("Test graph equality operator - Identity element") {
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    REQUIRE(g1 == g1);
}

TEST_CASE("Test graph inequality operator - Non-identity element") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    REQUIRE_FALSE(g1 != g2);
}

TEST_CASE("Check directed graph classification") {
    Graph g;
    vector<vector<int>> directedGraph = {{0, 1}, {0, 0}};
    g.loadGraph(directedGraph);
    CHECK(g.getDirected() == true);
}

TEST_CASE("Test graph multiplication - Associative property") {
    Graph g1, g2, g3;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}};
    vector<vector<int>> graph2 = {
        {0, 1},
        {1, 0}};
    vector<vector<int>> graph3 = {
        {0, 1},
        {1, 0}};
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);
    g3.loadGraph(graph3);

    Graph result1 = (g1 * g2) * g3;
    Graph result2 = g1 * (g2 * g3);

    REQUIRE(result1.getAdjMatrix() == result2.getAdjMatrix());
}

TEST_CASE("Test graph multiplication - Identity element") {
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1},
        {1, 0}};
    g1.loadGraph(graph);

    Graph result = g1 * g1;

    REQUIRE(result.getAdjMatrix() == g1.getAdjMatrix());
}

TEST_CASE("Invalid operations")
{
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    CHECK_THROWS(g2.loadGraph(weightedGraph));
    Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}