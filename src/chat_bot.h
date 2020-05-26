#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <iostream>
#include <tuple>
#include <memory>
#include <vector>

// forward declaration
class GraphNode;

class ChatBot
{
  public:
    ChatBot();
    ChatBot(std::shared_ptr<GraphNode> rootNode, std::shared_ptr<GraphNode> defaultNode);
    ~ChatBot();

    std::vector<std::string> getAnswer();
    void makeQuestion(std::string sentence);
    void startFromBeginning();

  private:
    const std::string DATAPATH = "../src/";
    const std::string ANSWERFILE = "answergraph.yml";

    std::shared_ptr<GraphNode> _rootNode;
    std::shared_ptr<GraphNode> _currentNode;
    std::shared_ptr<GraphNode> _defaultNode;

    // flags
    bool _useDefault;

    // memory
    std::vector<std::pair<std::string, std::shared_ptr<GraphNode>>> _topics;

    // helpers
    std::shared_ptr<GraphNode> generateNodeForSpokenTopic();
};

#endif /* CHATBOT_H_ */
