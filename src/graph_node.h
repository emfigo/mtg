#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <iostream>
#include <string>

class GraphNode
{
  public:
    GraphNode();
    GraphNode(std::string id, std::string answer);
    ~GraphNode();
    GraphNode(const GraphNode &source);             // Copy constructor
    GraphNode &operator=(const GraphNode &source);  // Copy assignment operator
    GraphNode(GraphNode &&source);                  // Move constructor
    GraphNode &operator=(GraphNode &&source);       // Move assignment operator

  private:
    std::string _answer;
    std::string _id;
};

#endif /* GRAPHNODE_H_ */
