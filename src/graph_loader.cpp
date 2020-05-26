#include "graph_edge.h"
#include "graph_node.h"
#include "graph_loader.h"

GraphLoader::GraphLoader(std::string relativePath)
{
  std::cout << "Hello from GraphLoader Constructor" << std::endl;
  YAML::Node config = YAML::LoadFile(relativePath);
  YAML::Node nodes = config["nodes"];
  loadNodes(nodes);

  YAML::Node edges = config["edges"];
  loadEdges(edges);
}

GraphLoader::~GraphLoader()
{
  std::cout << "Hello from GraphLoader Destructor" << std::endl;
}

std::shared_ptr<GraphNode> GraphLoader::getRootNode()
{
  return _nodeMap["root"];
}

std::shared_ptr<GraphNode> GraphLoader::getDefaultNode()
{
  return _nodeMap["default"];
}

void GraphLoader::loadNodes(YAML::Node nodes)
{
  for(YAML::const_iterator it = nodes.begin(); it != nodes.end(); it++)
  {
    YAML::Node node = it -> second;
    std::string id = it->first.as<std::string>();
    std::string answer = node["answer"].as<std::string>();
    std::string topic = std::string();
    if (node["topic"].IsDefined())
      topic = node["topic"].as<std::string>();

    std::shared_ptr<GraphNode> graphNode(new GraphNode(id, answer, topic));
    _nodeMap[id] = graphNode;
  }
}

void GraphLoader::loadEdges(YAML::Node edges)
{
  for(YAML::const_iterator it = edges.begin(); it != edges.end(); it++)
  {
    YAML::Node edge = it -> second;
    std::string parentKey = edge["parent"].as<std::string>();
    std::string childKey;
    if (edge["child"].IsDefined())
      childKey= edge["child"].as<std::string>();

    std::vector<std::string> keywords;
    if (edge["keywords"].IsDefined())
      keywords = edge["keywords"].as<std::vector<std::string>>();

    std::shared_ptr<GraphNode> parent = _nodeMap[parentKey];
    std::shared_ptr<GraphNode> child;
    if (!childKey.empty())
      child = _nodeMap[childKey];

    std::unique_ptr<GraphEdge> graphEdge(new GraphEdge(parent.get(), child, keywords));
    parent->addChildEdge(std::move(graphEdge));

    if (child != nullptr)
      child->addParentEdge(graphEdge.get());
  }
}
