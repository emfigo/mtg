#include "graph_node.h"

GraphNode::GraphNode()
{
  std::cout << "Hello from node constructor without memory allocation" << std::endl;
}


GraphNode::GraphNode(std::string id, std::string answer) : _id(id), _answer(answer)
{
  std::cout << "Hello from Node constructor with id " << _id << " with answer " << _answer << std::endl;
}

GraphNode::~GraphNode()
{
  std::cout << "Calling node destructor" << std::endl;
}

GraphNode::GraphNode(const GraphNode &source)
{
  std::cout << "Calling GraphNode copy constructor" << std::endl;
  _answer = source._answer;
  _id = source._id;
}

GraphNode &GraphNode::operator=(const GraphNode &source)
{
  std::cout << "Calling GraphNode copy assigment operator" << std::endl;

  if (this == &source)
    return *this;

  _answer = source._answer;
  _id = source._id;

  return *this;
}

GraphNode::GraphNode(GraphNode &&source)
{
  std::cout << "Calling GraphNode move constructor" << std::endl;
  _answer = source._answer;
  _id = source._id;
  source._answer = std::string();
  source._id = std::string();
}

GraphNode &GraphNode::operator=(GraphNode &&source)
{
  std::cout << "Calling GraphNode move assigment operator" << std::endl;

  if (this == &source)
    return *this;

  _answer = source._answer;
  _id = source._id;
  source._answer = std::string();
  source._id = std::string();

  return *this;
}
