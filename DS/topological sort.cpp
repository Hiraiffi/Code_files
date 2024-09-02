#include<iostream>
#include<stack>
using namespace std;

class Graph {
private:
    int vertices;
    int** adjacencyMatrix;

public:
    Graph(int vertices) {
        this->vertices = vertices;
        adjacencyMatrix = new int*[vertices];
        for (int i = 0; i < vertices; ++i) {
            adjacencyMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; ++j)
                adjacencyMatrix[i][j] = 0;
        }
    }

    void addEdge(int start, int end) {
        adjacencyMatrix[start][end] = 1;
    }

    void topologicalSortUtil(int v, bool visited[], stack<int>& s) {
        visited[v] = true;
        for (int i = 0; i < vertices; ++i) {
            if (adjacencyMatrix[v][i] && !visited[i])
                topologicalSortUtil(i, visited, s);
        }
        s.push(v);
    }

    void topologicalSort() {
        stack<int> s;
        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; ++i)
            visited[i] = false;

        for (int i = 0; i < vertices; ++i) {
            if (!visited[i])
                topologicalSortUtil(i, visited, s);
        }

        cout << "Topological Sort: ";
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    ~Graph() {
        for (int i = 0; i < vertices; ++i)
            delete[] adjacencyMatrix[i];
        delete[] adjacencyMatrix;
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();

    return 0;
}
