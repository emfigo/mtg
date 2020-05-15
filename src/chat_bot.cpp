#include "chat_bot.h"

ChatBot::ChatBot(GraphNode &&root)
{
  std::cout << "Hello from ChatBot Constructor" << std::endl;
  _rootNode = std::move(root);
  _currentNode = std::make_shared<GraphNode>(_rootNode);
}

ChatBot::~ChatBot()
{
  std::cout << "Hello from ChatBot Destructor" << std::endl;
}
