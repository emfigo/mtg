#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <string>
#include <iostream>

class GraphNode
{
  public:
    GraphNode(std::string id, std::string answer);
    ~GraphNode();
  private:
    std::string _answer;
    std::string _id;
};

#endif /* GRAPHNODE_H_ */
