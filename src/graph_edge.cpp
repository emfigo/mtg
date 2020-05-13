#include "graph_edge.h"

GraphEdge::GraphEdge(std::shared_ptr<GraphNode> parent, std::shared_ptr<GraphNode> child, std::vector<std::string> keywords) : _parentNode(parent), _childNode(child)
{
  std::cout << "Hello from edge constructor" << std::endl;
  for(std::string keyword : keywords) {
    _keywords[keyword] = 1;
  }
}

GraphEdge::~GraphEdge()
{
  std::cout << "Bye from edge destructor" << std::endl;
}

GraphNode *GraphEdge::getParentNode()
{
  return _parentNode.get();
}

GraphNode *GraphEdge::getChildNode()
{
  return _childNode.get();
}

bool GraphEdge::containsKeyword(std::string keyword)
{
  return (bool) _keywords[keyword];
}
