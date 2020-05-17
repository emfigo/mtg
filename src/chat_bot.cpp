#include "chat_bot.h"

ChatBot::ChatBot()
{
  std::cout << "Hello from ChatBot Constructor without memory allocation" << std::endl;
}

ChatBot::ChatBot(std::shared_ptr<GraphNode> root) : _rootNode(root), _currentNode(root)
{
  std::cout << "Hello from ChatBot Constructor" << std::endl;
}

ChatBot::~ChatBot()
{
  std::cout << "Hello from ChatBot Destructor" << std::endl;
}

std::string ChatBot::question()
{
  return _currentNode->getAnswer();
}

void ChatBot::answerFor(std::string sentence)
{
  std::shared_ptr<GraphNode> ptr = _currentNode->findChild(sentence);
  if (ptr != nullptr){
    _currentNode = ptr;
  } else {
    _currentNode = _rootNode;
  }
}
