#ifndef GRAPHEDGE_H
#define GRAPHEDGE_H

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

class GraphNode;

class GraphEdge
{
  public:
    GraphEdge(std::shared_ptr<GraphNode> parent, std::shared_ptr<GraphNode> child, std::vector<std::string> keywords);
    ~GraphEdge();
    GraphNode *getParentNode();
    GraphNode *getChildNode();
    bool containsKeyword(std::string keyword);

  private:
    std::shared_ptr<GraphNode> _parentNode;
    std::shared_ptr<GraphNode> _childNode;
    std::map<std::string, int> _keywords;

};

#endif /* GRAPHEDGE_H_ */
