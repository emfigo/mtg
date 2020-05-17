#ifndef GRAPHLOADER_H_
#define GRAPHLOADER_H_

#include <string>
#include <memory>

// forawrd declaration
class GraphNode;

class GraphLoader
{
  public:
    static std::shared_ptr<GraphNode> loadGraph(std::string relativePath);

};

#endif /* GRAPHLOADER_H_ */
