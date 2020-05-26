#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

// Forward Declaration
class GraphEdge;

class GraphNode
{
  public:
    GraphNode();
    GraphNode(std::string id, std::string answer, std::string topic);
    ~GraphNode();
    GraphNode(GraphNode &&source);                  // Move constructor
    GraphNode &operator=(GraphNode &&source);       // Move assignment operator

    void addParentEdge(GraphEdge *edge);
    void addChildEdge(std::unique_ptr<GraphEdge> edge);

    std::string getAnswer();
    std::string getID();
    bool isLeaf();
    std::string getTopic();

    std::shared_ptr<GraphNode> findChild(std::string sentence);
    std::shared_ptr<GraphNode> findChildByID(std::string id);

  private:
    // properties
    std::string _answer;
    std::string _id;
    std::string _topic;

    // navigation
    std::vector<GraphEdge *> _parentEdges;
    std::map<std::string, std::unique_ptr<GraphEdge>> _childEdges;

    // Not allow copy operations
    GraphNode(const GraphNode &source);             // Copy constructor
    GraphNode &operator=(const GraphNode &source);  // Copy assignment operator
};

#endif /* GRAPHNODE_H_ */
