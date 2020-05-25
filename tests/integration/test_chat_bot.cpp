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
      REQUIRE( bot.getAnswer() == "Hi ! Would you like to speak about the animal kingdom ?" );
    }
  }

  SECTION ( "And it has moved to an existing answer" ){
    bot.startFromBeginning();
    bot.makeQuestion("yes");

    SECTION ( "Returns the expected node answer" ){
      REQUIRE( bot.getAnswer() == "Nice ! Let's select which group of animals you would like to speak more about (e.g diet). If you want to know the existing groups just let me know !" );
    }
  }

  SECTION ( "And it has moved to a non existing ansswer" ){
    bot.startFromBeginning();
    bot.makeQuestion("maybe");

    SECTION ( "Returns the default node answer" ){
      REQUIRE( bot.getAnswer() == "Sorry I don't have an answer for that ! Would you like to speak about something else ?" );
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
      REQUIRE( bot.getAnswer() == "Root Answer" );
    }
  }

  SECTION ( "And it has moved to an existing answer" ){
    bot.startFromBeginning();
    bot.makeQuestion("yes");

    SECTION ( "Returns the expected node answer" ){
      REQUIRE( bot.getAnswer() == "1 Answer" );
    }
  }

  SECTION ( "And it has moved to a non existing ansswer" ){
    bot.startFromBeginning();
    bot.makeQuestion("maybe");

    SECTION ( "Returns the default node answer" ){
      REQUIRE( bot.getAnswer() == "Default Answer" );
    }
  }
}
