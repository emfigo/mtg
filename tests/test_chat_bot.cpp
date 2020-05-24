#include "catch2/catch.hpp"

#include <string>
#include <memory>

#include "../src/chat_bot.h"
#include "../src/graph_loader.h"

const std::string FIXTURE_ANSWER_GRAPH_PATH = "../tests/fixtures/answergraphsimple.yml";

TEST_CASE( "When the chatbot answer a question", "[question]" ) {
  GraphLoader loader(FIXTURE_ANSWER_GRAPH_PATH);
  ChatBot bot(loader.getRootNode(), loader.getDefaultNode());

  SECTION ( "And it has not moved in the graph" ){
    SECTION ( "Returns the root node answer" ){
      REQUIRE( bot.question() == "Root Answer" );
    }
  }

  SECTION ( "And it has moved to an existing answer" ){
    bot.answerFor("yes");

    SECTION ( "Returns the expected node answer" ){
      REQUIRE( bot.question() == "1 Answer" );
    }
  }

  SECTION ( "And it has moved to a non existing ansswer" ){
    bot.answerFor("maybe");

    SECTION ( "Returns the default node answer" ){
      REQUIRE( bot.question() == "Default Answer" );
    }
  }
}
