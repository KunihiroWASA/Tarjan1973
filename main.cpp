#include <iostream>
#include <vector>
#include <stack>

typedef  int                  Node; 
typedef  std::vector<Node>    AdjList; 
typedef  std::vector<AdjList> Graph; 

class CIRCUIT_ENUMERATION {
    
    std::stack<Node> point_stack; 
    std::stack<Node> marked_stack; 
    std::vector<bool> marked; 
    void BACKTRACK(Node v, bool f); 
    bool DELETE(AdjList a, Node v);  

    Graph g; 

    public:
        CIRCUIT_ENUMERATION(Graph & __g);
};




int main(int argc, char const* argv[])
{
    std::cout << "hello, world!" << std::endl;
    return 0;
}

void CIRCUIT_ENUMERATION::BACKTRACK(Node v, bool f) 
{
    bool g; 
    f = false; 
    point_stack.push(v); 
    marked.at(v) = true;  
    marked_stack.push(v); 

    for (auto& w : G.at(v)) {
        if (w < s) {
            DELETE(G.at(v), w);  
        }
    }

}

bool CIRCUIT_ENUMERATION::DELETE(AdjList a, Node v) 
{
    
}
CIRCUIT_ENUMERATION::CIRCUIT_ENUMERATION(Graph & __g) 
{
    g = __g; 
}
