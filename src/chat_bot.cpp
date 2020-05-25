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

ChatBot::ChatBot(std::shared_ptr<GraphNode> rootNode, std::shared_ptr<GraphNode> defaultNode) : _rootNode(rootNode), _currentNode(rootNode), _defaultNode(defaultNode)
{
  std::cout << "Hello from ChatBot Constructor" << std::endl;
}

ChatBot::~ChatBot()
{
  std::cout << "Hello from ChatBot Destructor" << std::endl;
}

void ChatBot::startFromBeginning()
{
  _currentNode = _rootNode;
    _useDefault = false;
}

std::string ChatBot::getAnswer()
{
  return _useDefault ? _defaultNode->getAnswer() : _currentNode->getAnswer();
}

void ChatBot::makeQuestion(std::string sentence)
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
