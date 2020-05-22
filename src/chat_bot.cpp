#include "chat_bot.h"
#include "graph_loader.h"

ChatBot::ChatBot()
{
  std::cout << "Hello from ChatBot Constructor with default root" << std::endl;
  GraphLoader loader = GraphLoader(DATAPATH + ANSWERFILE);
  _rootNode = loader.getRootNode();
  _currentNode = _rootNode;
  _defaultNode = loader.getDefaultNode();
  _useDefault = false;
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
  return _useDefault ? _defaultNode->getAnswer() : _currentNode->getAnswer();
}

void ChatBot::answerFor(std::string sentence)
{
  std::shared_ptr<GraphNode> ptr;
  if (_useDefault) {
    ptr = _defaultNode->findChild(sentence);
  } else {
    ptr = _currentNode->findChild(sentence);
  }

  if (ptr != nullptr){
    _useDefault = false;
    _currentNode = ptr;
  }else if(!_useDefault) {
    _useDefault = true;
  } else {
    _useDefault = false;
  }
}
