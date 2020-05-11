#include "graph_node.h"

GraphNode::GraphNode(std::string id, std::string answer) : _id(id), _answer(answer)
{
  std::cout << "Hello from Node constructor with id " << _id << " with answer " << _answer << std::endl;
}

GraphNode::~GraphNode()
{
  std::cout << "Calling node destructor" << std::endl;
}
