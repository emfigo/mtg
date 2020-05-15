#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <iostream>
#include <memory>

#include "graph_node.h"

class ChatBot
{
  public:
    ChatBot(GraphNode &&root);
    ~ChatBot();

  private:
    GraphNode _rootNode;
    std::shared_ptr<GraphNode> _currentNode;
};

#endif /* CHATBOT_H_ */
