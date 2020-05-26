#include "graph_edge.h"
#include "graph_node.h"

GraphNode::GraphNode() : _id(std::string()), _answer(std::string()), _topic(std::string())
{
  std::cout << "Hello from node constructor without memory allocation" << std::endl;
}


GraphNode::GraphNode(std::string id, std::string answer, std::string topic) : _id(id), _answer(answer), _topic(topic)
{
  std::cout << "Hello from Node constructor with id " << _id << " with answer " << _answer << std::endl;
}

GraphNode::~GraphNode()
{
  std::cout << "Calling Graph Node destructor with id " << _id << std::endl;
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

  for(GraphEdge *ptr: source._parentEdges){
    _parentEdges.push_back(ptr);
  }
  source._parentEdges.clear();

  for(auto &&[id, edge]: source._childEdges){
    _childEdges[id] = std::move(edge);
  }
  source._childEdges.clear();
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

  for(GraphEdge *ptr: source._parentEdges){
    _parentEdges.push_back(ptr);
  }
  source._parentEdges.clear();

  for(auto &&[id, edge]: source._childEdges){
    _childEdges[id] = std::move(edge);
  }
  source._childEdges.clear();

  return *this;
}

void GraphNode::addParentEdge(GraphEdge *edge)
{
  _parentEdges.push_back(edge);
}

void GraphNode::addChildEdge(std::unique_ptr<GraphEdge> edge)
{
  std::string id = edge->getChildNode()->getID();

  _childEdges[id] = std::move(edge);
}

std::shared_ptr<GraphNode> GraphNode::findChild(std::string sentence)
{
  std::shared_ptr<GraphNode> ptr;

  for(const auto &[id, edge]: _childEdges){
    if( edge->containsKeywordIgnoreCase(sentence) ){
      ptr = edge->getChildNode();
      break;
    }
  }

  return ptr;
}

bool GraphNode::isLeaf()
{
  return _childEdges.empty();
}

std::string GraphNode::getTopic()
{
  return _topic;
}

std::shared_ptr<GraphNode> GraphNode::findChildByID(std::string id)
{
  return _childEdges.find(id) != _childEdges.end() ? _childEdges[id]->getChildNode() : nullptr;
}

std::string GraphNode::getAnswer()
{
  return _answer;
}

std::string GraphNode::getID()
{
  return _id;
}
