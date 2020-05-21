#ifndef GRAPHLOADER_H_
#define GRAPHLOADER_H_

#include <iostream>
#include <memory>
#include "yaml-cpp/yaml.h"

// forawrd declaration
class GraphNode;

class GraphLoader
{
  public:
    GraphLoader(std::string relativePath);
    ~GraphLoader();
    std::shared_ptr<GraphNode> getRootNode();
    std::shared_ptr<GraphNode> getDefaultNode();

  private:
    std::map<std::string, std::shared_ptr<GraphNode>> _nodeMap;
    void loadNodes(YAML::Node nodes);
    void loadEdges(YAML::Node edges);

};

#endif /* GRAPHLOADER_H_ */
