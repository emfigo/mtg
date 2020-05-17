#include "yaml-cpp/yaml.h"

#include "chat_bot.h"
#include "graph_edge.h"
#include "graph_loader.h"
#include "graph_node.h"

#include <iostream>
#include <memory>

// forward declarations
class GraphNode;

int main() {
  std::cout << "Hello from MTG!" << "\n";

  ChatBot bot = ChatBot(GraphLoader::loadGraph("../src/answergraph.yml"));

  std::cout << "======================================" << std::endl;
  std::cout << bot.question() << std::endl;
  std::cout << "======================================" << std::endl;

  bot.answerFor("yes");

  std::cout << "======================================" << std::endl;
  std::cout << bot.question() << std::endl;
  std::cout << "======================================" << std::endl;

  bot.answerFor("diet");

  std::cout << "======================================" << std::endl;
  std::cout << bot.question() << std::endl;
  std::cout << "======================================" << std::endl;

  bot.answerFor("omnivore");

  std::cout << "======================================" << std::endl;
  std::cout << bot.question() << std::endl;
  std::cout << "======================================" << std::endl;

  return 0;
}
