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

  private:
    std::string _answer;
    std::string _id;
};

#endif /* GRAPHNODE_H_ */
