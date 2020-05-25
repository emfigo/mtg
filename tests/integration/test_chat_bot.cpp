#include "catch2/catch.hpp"

#include <string>
#include <memory>

#include "../../src/chat_bot.h"
#include "../../src/graph_loader.h"


TEST_CASE( "Moving inside the default graph in the chatbot" ) {
  ChatBot bot;

  SECTION ( "And it has not moved in the graph" ){
    bot.startFromBeginning();

    SECTION ( "Returns the root node answer" ){
      std::vector<std::string> expectedAnswer = {
        "Hi ! I'm Chat Bot and I know a few things about the animal kingdom. Would you like to know more ?"
      };

      REQUIRE( bot.getAnswer() == expectedAnswer);
    }
  }

  SECTION ( "And it has moved to an existing answer" ){
    bot.startFromBeginning();
    bot.makeQuestion("yes");

    SECTION ( "Returns the expected node answer" ){
      std::vector<std::string> expectedAnswer = {
        "Nice ! There are a few groups to classify animals ! Tell me which one would you like to speak of (e.g diet) or if you want me to tell you the existing groups just let me know !"
      };

      REQUIRE( bot.getAnswer() == expectedAnswer);
    }
  }

  SECTION ( "And it has moved to a non existing ansswer" ){
    bot.startFromBeginning();
    bot.makeQuestion("maybe");

    SECTION ( "Returns the default node answer" ){
      std::vector<std::string> expectedAnswer = {
        "Sorry I don't have an answer for that ! Would you like to speak about something else ?"
      };

      REQUIRE( bot.getAnswer() == expectedAnswer);
    }
  }
}

TEST_CASE( "Selecting a custom graph in the chatbot" ) {
  const std::string FIXTURE_ANSWER_GRAPH_PATH = "../tests/fixtures/answergraphsimple.yml";
  GraphLoader loader(FIXTURE_ANSWER_GRAPH_PATH);
  ChatBot bot(loader.getRootNode(), loader.getDefaultNode());

  SECTION ( "And it has not moved in the graph" ){
    bot.startFromBeginning();

    SECTION ( "Returns the root node answer" ){
      std::vector<std::string> expectedAnswer = {
        "Root Answer"
      };

      REQUIRE( bot.getAnswer() == expectedAnswer);
    }
  }

  SECTION ( "And it has moved to an existing answer" ){
    bot.startFromBeginning();
    bot.makeQuestion("yes");

    SECTION ( "Returns the expected node answer" ){
      std::vector<std::string> expectedAnswer = {
        "1 Answer"
      };

      REQUIRE( bot.getAnswer() == expectedAnswer);
    }
  }

  SECTION ( "And it has moved to a non existing ansswer" ){
    bot.startFromBeginning();
    bot.makeQuestion("maybe");

    SECTION ( "Returns the default node answer" ){
      std::vector<std::string> expectedAnswer = {
        "Default Answer"
      };

      REQUIRE( bot.getAnswer() == expectedAnswer);
    }
  }
}
