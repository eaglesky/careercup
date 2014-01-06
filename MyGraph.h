#include <vector>
#include <list>
#include <fstream>

typedef struct EdgeNode{
    int id;
    struct EdgeNode* next;
} EdgeNode;

typedef struct {
    std::vector<EdgeNode*> vertices;
    int vNum;
    int eNum;
    int* parents;
    bool isDirected;
} Graph;

void bfs(Graph* g, int s)
{
    delete [](g->parents);
    g->parents = new int[g->vNum];
    int* status = new int[g->vNum];

    for (int i = 0; i < g->vNum; i++)
        status[i] = 0;

    std::list<int> queue;
    queue.push_back(s);
    status[s] = 1;
    (g->parents)[s] = -1;

    while(!queue.empty())
    {
        int cur = queue.front();
        queue.pop_front();

        std::cout << cur << ", ";

        EdgeNode* p = g->vertices[cur];
        p = p->next;
        while(p)
        {
            if (status[p->id] == 0) {
                queue.push_back(p->id);
                status[p->id] = 1;
                g->parents[p->id] = cur;
            }
            p = p->next;
        }

    }
    std::cout << std::endl;
    delete []status;
}

void dfsTree(Graph* g, int s, int* status)
{
  
    EdgeNode* p = g->vertices[s];
    status[p->id] = 1;

    std::cout << s << ", ";
    p = p->next;
    while(p)
    {
        int cur = p->id;
        if (status[cur] == 0)
            dfsTree(g, cur, status);

        p = p->next;
    }
}


void dfs(Graph* g)
{
    int* status = new int[g->vNum];
    for (int i = 0; i < g->vNum; i++)
        status[i] = 0;

    for (int i = 0; i < g->vNum; i++)
    {
        if (status[i] == 0)
            dfsTree(g, i, status);
    }

    delete []status;
}

void printBFSPath(Graph* g, int v)
{
    int* parents = g->parents;
    if (parents) {
        if (v != -1)
            printBFSPath(g, parents[v]);

        std::cout << v << ", ";
    }
}

bool readGraph(Graph* g, std::ifstream& fin)
{
    if (!fin) {
        std::cout << "Unable to open the file!" << std::endl;
        return false;
    }

    fin >> g->isDirected >> g->vNum >> g->eNum;

    std::cout << "Is directed: " << g->isDirected << std::endl;
    std::cout << "vNum = " << g->vNum << ", eNum = " << g->eNum << std::endl;

    std::vector<std::pair<int, int> > edges;

    int v1, v2;
    while (fin >> v1 >> v2)
    {
        std::cout << v1 << ", " << v2 << std::endl;
        edges.push_back(std::pair<int, int>(v1, v2));
    }

    for (int i = 0; i < g->vNum; i++)
    {
        EdgeNode* vNode = new EdgeNode;
        vNode->id = i;
        vNode->next = NULL;
        g->vertices.push_back(vNode);
    }
    for (int i = 0; i < edges.size(); i++)
    {
        int v1 = edges[i].first;
        int v2 = edges[i].second;

        EdgeNode* eNodeNext = g->vertices[v1]->next;
        EdgeNode* cur = new EdgeNode;
        cur->id = v2;
        cur->next = eNodeNext;
        g->vertices[v1]->next = cur;

        if (g->isDirected == 0) {
            eNodeNext = g->vertices[v2]->next;
            cur = new EdgeNode;
            cur->id = v1;
            cur->next = eNodeNext;
            g->vertices[v2]->next = cur;
        }
    }


    return true;
}

void printGraphSimple(Graph* g)
{
    for (int i = 0; i < g->vNum; i++)
    {
        EdgeNode* p = g->vertices[i];
        while(p)
        {
            std::cout << p->id << ", ";
            p = p->next;
        }
        std::cout << std::endl;
    }
}

void destroyGraph(Graph* g)
{
    for (int i = 0; i < g->vNum; i++)
    {
        EdgeNode* p = g->vertices[i];
        while (p)
        {
            EdgeNode* q = p;
            p = p->next;
            delete q;
        }
    }
   
}
