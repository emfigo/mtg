#include "graph_edge.h"
#include "graph_node.h"

GraphEdge::GraphEdge(GraphNode* parent, std::shared_ptr<GraphNode> child, std::vector<std::string> keywords) : _parentNode(parent), _childNode(child)
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
  return _parentNode;
}

std::shared_ptr<GraphNode> GraphEdge::getChildNode()
{
  return _childNode;
}

bool GraphEdge::containsKeyword(std::string keyword)
{
  return (bool) _keywords[keyword];
}
