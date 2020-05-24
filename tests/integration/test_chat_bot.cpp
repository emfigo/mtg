#include "catch2/catch.hpp"

#include <string>
#include <memory>

#include "../../src/chat_bot.h"
#include "../../src/graph_loader.h"


TEST_CASE( "Moving inside the default graph in the chatbot" ) {
  ChatBot bot;

  SECTION ( "And it has not moved in the graph" ){
    SECTION ( "Returns the root node answer" ){
      REQUIRE( bot.question() == "Hi ! Would you like to speak about the animal kingdom ?" );
    }
  }

  SECTION ( "And it has moved to an existing answer" ){
    bot.answerFor("yes");

    SECTION ( "Returns the expected node answer" ){
      REQUIRE( bot.question() == "Nice ! Let's select which group of animals you would like to speak more about (e.g diet). If you want to know the existing groups just let me know !" );
    }
  }

  SECTION ( "And it has moved to a non existing ansswer" ){
    bot.answerFor("maybe");

    SECTION ( "Returns the default node answer" ){
      REQUIRE( bot.question() == "Sorry I don't have an answer for that ! Would you like to speak about something else ?" );
    }
  }
}
