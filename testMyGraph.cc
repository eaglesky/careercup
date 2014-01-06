#include <iostream>
#include "MyGraph.h"

int main(int argc, char** argv)
{
    std::ifstream fin1("Graph2.txt");
    Graph* g1 = new Graph;

    
    readGraph(g1, fin1);
    std::cout << "Graph1 content: " << std::endl;
    printGraphSimple(g1);
    std::cout << std::endl;

    std::cout << "BFS result: " << std::endl;
    bfs(g1, 0);
    std::cout << "BFS all paths: " << std::endl;
    for (int i = 0; i < g1->vNum; i++)
    {
        std::cout << "From 0 to " << i << ": ";
        printBFSPath(g1, i);
        std::cout << std::endl;
    }

    std::cout << "DFS result: " << std::endl;
    dfs(g1);
    std::cout << std::endl;

    destroyGraph(g1);
    delete g1;

    return 0;
}
