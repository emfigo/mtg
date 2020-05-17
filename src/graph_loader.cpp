#include "graph_edge.h"
#include "graph_node.h"
#include "graph_loader.h"
#include "yaml-cpp/yaml.h"

std::shared_ptr<GraphNode> GraphLoader::loadGraph(std::string relativePath)
{
  std::map<std::string, std::shared_ptr<GraphNode>> nodeMap;

  YAML::Node config = YAML::LoadFile(relativePath);
  YAML::Node nodes = config["nodes"];

  for(YAML::const_iterator it = nodes.begin(); it != nodes.end(); it++)
  {
    YAML::Node node = it -> second;
    std::string id = it->first.as<std::string>();
    std::string answer = node["answer"].as<std::string>();
    std::shared_ptr<GraphNode> graphNode(new GraphNode(id, answer));
    nodeMap[id] = graphNode;
  }

  YAML::Node edges = config["edges"];

  for(YAML::const_iterator it = edges.begin(); it != edges.end(); it++)
  {
    YAML::Node edge = it -> second;
    std::string parentKey = edge["parent"].as<std::string>();
    std::string childKey = edge["child"].as<std::string>();
    std::vector<std::string> keywords = edge["keywords"].as<std::vector<std::string>>();

    std::shared_ptr<GraphNode> parent = nodeMap[parentKey];
    std::shared_ptr<GraphNode> child = nodeMap[childKey];

    std::unique_ptr<GraphEdge> graphEdge(new GraphEdge(parent.get(), child, keywords));
    child->addParentEdge(graphEdge.get());
    parent->addChildEdge(std::move(graphEdge));
  }

  return nodeMap["root"];
}
