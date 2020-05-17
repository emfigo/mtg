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
    std::shared_ptr<GraphNode> _rootNode;
    std::shared_ptr<GraphNode> _currentNode;
};

#endif /* CHATBOT_H_ */
