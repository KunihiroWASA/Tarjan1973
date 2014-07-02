#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

typedef  int                  Node; 
typedef  std::vector<Node>    AdjList; 
typedef  std::vector<AdjList> Graph; 

class CIRCUIT_ENUMERATION {
    
    Node s; 
    std::stack<Node> point_stack; 
    std::stack<Node> marked_stack; 
    std::map<Node, bool> mark; 
    void BACKTRACK(Node v, bool & f); 
    AdjList::iterator DELETE(AdjList & a, Node v);  
    void OUTPUT(); 

    int __cnt; 

    Graph G; 

    public:
        CIRCUIT_ENUMERATION();
        void MAIN(Graph & __g);  
};




int main(int argc, char const* argv[])
{
    Graph g = {
        {2, 6}, 
        {}, 
        {3}, 
        {0}, 
        {}, 
        {}, 
        {3}, 
        {}
    }; 

    CIRCUIT_ENUMERATION CE; 
    CE.MAIN(g); 
    return 0;
}

void CIRCUIT_ENUMERATION::MAIN(Graph & __g) 
{
    G = __g; 
    
    int V = (int)G.size(); 
    for (Node i = 0; i < V; ++i) {
        mark[i] = false; 
    }

    bool flag; 
    __cnt = 0; 
    for (s = 0; s < V; ++s) {
        BACKTRACK(s, flag); 
        while (!marked_stack.empty()) {
            Node u = marked_stack.top(); 
            mark[u] = false; 
            marked_stack.pop(); 
        }
    }
}

void CIRCUIT_ENUMERATION::BACKTRACK(Node v, bool & f) 
{
    bool g; 
    f = false; 
    point_stack.push(v); 
    mark[v] = true;  
    marked_stack.push(v); 

    for (auto itr = G.at(v).begin(); itr != G.at(v).end();) {
        Node w = *itr; 
        if (w < s) {
            itr = DELETE(G.at(v), w);  
        } else if (w == s) {
            OUTPUT(); 
            f = true; 
        } else if (mark[w] == false) {
            BACKTRACK(w, g); 
            f = f or g; 
        }

        if (w >= s) {
            ++itr; 
        }
    }

    if (f == true) {
        while (marked_stack.top() != v) {
            Node u = marked_stack.top(); 
            marked_stack.pop(); 
            mark[u] = false; 
        }
        marked_stack.pop(); 
        mark[v] = false; 
    }
    point_stack.pop(); 
}

AdjList::iterator CIRCUIT_ENUMERATION::DELETE(AdjList & a, Node v) 
{
    AdjList::iterator itr; 
    for (auto itr = a.begin(); itr != a.end(); ++itr) {
        if (*itr == v) {
            return a.erase(itr); 
        }
    }

    return a.end(); 
}

void CIRCUIT_ENUMERATION::OUTPUT()
{
    std::stack<Node> rev_point_stack; 
    std::cout << "C" << __cnt++ << ": " << s; 
    while (!point_stack.empty()) {
        Node t = point_stack.top(); 
        std::cout << " -> " << t; 
        point_stack.pop(); 
        rev_point_stack.push(t); 
    }
    std::cout << std::endl; 
    while (!rev_point_stack.empty()) {
        Node t = rev_point_stack.top(); 
        rev_point_stack.pop(); 
        point_stack.push(t); 
    }
}

CIRCUIT_ENUMERATION::CIRCUIT_ENUMERATION() 
{
}
