#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <iostream>
#include <memory>

#include "graph_node.h"

class ChatBot
{
  public:
    ChatBot();
    ChatBot(std::shared_ptr<GraphNode> rootNode, std::shared_ptr<GraphNode> defaultNode);
    ~ChatBot();

    std::string getAnswer();
    void makeQuestion(std::string sentence);
    void startFromBeginning();

  private:
    const std::string DATAPATH = "../src/";
    const std::string ANSWERFILE = "answergraph.yml";

    std::shared_ptr<GraphNode> _rootNode;
    std::shared_ptr<GraphNode> _currentNode;
    std::shared_ptr<GraphNode> _defaultNode;

    bool _useDefault;
};

#endif /* CHATBOT_H_ */
