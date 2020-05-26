#include "chat_bot.h"
#include "graph_edge.h"
#include "graph_loader.h"
#include "graph_node.h"

ChatBot::ChatBot() : _useDefault(false)
{
  std::cout << "Hello from ChatBot Constructor with default root" << std::endl;
  GraphLoader loader = GraphLoader(DATAPATH + ANSWERFILE);
  _rootNode = loader.getRootNode();
  _currentNode = _rootNode;
  _defaultNode = loader.getDefaultNode();
}

ChatBot::ChatBot(std::shared_ptr<GraphNode> rootNode, std::shared_ptr<GraphNode> defaultNode) : _rootNode(rootNode), _currentNode(rootNode), _defaultNode(defaultNode), _useDefault(false)
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

std::vector<std::string> ChatBot::getAnswer()
{
  std::vector<std::string> output;
  std::string currentTopic = _currentNode->getTopic();

  if( !currentTopic.empty() ){
    std::pair<std::string, std::shared_ptr<GraphNode>> topic(currentTopic, _currentNode);
    _topics.insert(_topics.begin(), topic);
  }

  if( _useDefault ) {
    output.push_back(_defaultNode->getAnswer());
  } else {
    output.push_back(_currentNode->getAnswer());
  }

  if(_currentNode->isLeaf() && (_currentNode->getID() != "neg")){
    _currentNode = generateNodeForSpokenTopic();
    output.push_back(_currentNode->getAnswer());
  }

  return output;
}

void ChatBot::makeQuestion(std::string sentence)
{
  std::shared_ptr<GraphNode> ptr;
  if (_currentNode->getID() == "neg"){
    // this is done because the answer graph for the sample bot is too short
    ptr = _rootNode;
  } else if (_useDefault) {
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

std::shared_ptr<GraphNode> ChatBot::generateNodeForSpokenTopic()
{
  std::string response;
  std::shared_ptr<GraphNode> oldTopicNode;
  std::unique_ptr<GraphEdge> positiveEdge;
  std::shared_ptr<GraphNode> positiveNode;
  std::vector<std::string> positiveKeywords = { "yes", "sure", "ok", "cool" };
  std::unique_ptr<GraphEdge> negativeEdge;
  std::shared_ptr<GraphNode> negativeNode;
  std::vector<std::string> negativeKeywords = { "no" };

  if(_topics.empty()) {
    response = "Sorry I'm afraid I don't have more topics to speak about ... So let's start again";

    negativeNode = _rootNode;
    positiveNode = _rootNode;
  } else {
    negativeNode = std::make_shared<GraphNode>(
        "neg",
        "Would you like to speak about something else ?",
        std::string()
        );
    response = "Would you like to speak again about " + _topics.back().first + " ?";
    std::pair<std::string, std::shared_ptr<GraphNode>> topic = _topics.back();
    _topics.pop_back();
    positiveNode = topic.second;
  }

  oldTopicNode = std::make_shared<GraphNode>("tmp", response, std::string());
  positiveEdge = std::make_unique<GraphEdge>(oldTopicNode.get(), positiveNode, positiveKeywords);
  negativeEdge = std::make_unique<GraphEdge>(oldTopicNode.get(), negativeNode, negativeKeywords);

  oldTopicNode->addChildEdge(std::move(positiveEdge));
  oldTopicNode->addChildEdge(std::move(negativeEdge));

  return oldTopicNode;
}
