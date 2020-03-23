#include <iostream>
using namespace std;

const int numVertex = 13;
struct Node{
    int vertex;
    int weight;
    Node* next;
};

void initializeGraph(Node** adjList){
    for (int i=0; i<numVertex; i++){
        adjList[i] = new Node;
        adjList[i]->vertex = i;
        adjList[i]->weight = 0;
        adjList[i]->next = NULL;
    }
}

void addEdge(Node** adjList, int source, int destination){
    Node* newEdge = new Node;
    newEdge->vertex = destination;
    newEdge->next = adjList[source]->next;
    adjList[source]->next = newEdge;
}

void printGraph(Node** adjList){
    for(int i=0; i<numVertex; i++){
        Node* tmp = adjList[i]->next;
        if(tmp == NULL) cout << adjList[i]->vertex << endl;
        while(tmp != NULL){
            cout << adjList[i]->vertex << "-" << tmp->vertex << endl;
            tmp = tmp->next;
        }
    }
}

int computeOutDegree(Node** adjList, int vertex){
    int outDegree = 0;
    Node* tmp = adjList[vertex]->next;
    while(tmp != NULL){
        outDegree++;
        tmp = tmp->next;
    }
    return outDegree;
}

int computeInDegree(Node** adjList, int vertex){
    int inDegree = 0;
    Node* tmp = adjList[vertex];
    while(tmp != NULL){
        inDegree++;
        tmp = tmp->next;
    }
    return inDegree-1;
}

float computeAverageDegree(Node** adjList){
    float sumOfDegree = 0;
    for(int i=0; i<numVertex; i++){
        sumOfDegree += computeOutDegree(adjList, i);
    }
    return sumOfDegree/numVertex;
}

int countSelfLoop(Node** adjList){
    int counter = 0;
    for(int i=0; i<numVertex; i++){
        if(adjList[i] == adjList[i]->next){
            counter++;
        }
    }
    return counter;
}

int main(){
    Node** adjList = new Node*[numVertex];
    initializeGraph(adjList);
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 0, 5);
    addEdge(adjList, 0, 6);
    addEdge(adjList, 1, 0);
    addEdge(adjList, 2, 0);
    addEdge(adjList, 3, 4);
    addEdge(adjList, 3, 5);
    addEdge(adjList, 4, 3);
    addEdge(adjList, 4, 5);
    addEdge(adjList, 5, 3);
    addEdge(adjList, 5, 4);
    addEdge(adjList, 6, 0);
    addEdge(adjList, 6, 4);
    addEdge(adjList, 7, 8);
    addEdge(adjList, 8, 7);
    addEdge(adjList, 9, 12);
    addEdge(adjList, 10, 9);
    addEdge(adjList, 11, 9);
    addEdge(adjList, 11, 12);
    addEdge(adjList, 12, 9);
    addEdge(adjList, 12, 11);

    printGraph(adjList);
    cout << "In degree of vertex 2 = " << computeInDegree(adjList, 2) << endl;
    cout << "Out degree of vertex 0 = " << computeOutDegree(adjList, 0) << endl;
    cout << "Average degree of graph vertex = " << computeAverageDegree(adjList) << endl;
    cout << "Count of self loop = " << countSelfLoop(adjList) << endl;
}
