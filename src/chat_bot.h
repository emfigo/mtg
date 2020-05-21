#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <iostream>
#include <memory>

#include "graph_node.h"

class ChatBot
{
  public:
    ChatBot();
    ChatBot(std::shared_ptr<GraphNode> root);
    ~ChatBot();

    std::string question();
    void answerFor(std::string sentence);

  private:
    const std::string DATAPATH = "../src/";
    const std::string ANSWERFILE = "answergraph.yml";
    std::shared_ptr<GraphNode> _rootNode;
    std::shared_ptr<GraphNode> _currentNode;
    std::shared_ptr<GraphNode> _defaultNode;
};

#endif /* CHATBOT_H_ */
