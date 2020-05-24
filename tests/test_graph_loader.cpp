#include "catch2/catch.hpp"

#include <string>
#include <memory>

#include "../src/graph_loader.h"
#include "../src/graph_node.h"

const std::string FIXTURE_ANSWER_GRAPH_PATH = "../tests/fixtures/answergraphsimple.yml";

TEST_CASE( "When getting root node from an answer graph", "[getRootNode]" ) {
  GraphLoader loader(FIXTURE_ANSWER_GRAPH_PATH);
  std::shared_ptr<GraphNode> node = loader.getRootNode();

  SECTION ( "Returns the expected root id" ){
    REQUIRE( node->getID() == "root" );
  }

  SECTION ( "Returns the expected root answer" ){
    REQUIRE( node->getAnswer() == "Root Answer" );
  }

  SECTION ( "Navigates to the correct child when keyword present" ){
    std::shared_ptr<GraphNode> child = node->findChild("yes");

    REQUIRE( child->getID() == "1" );
    REQUIRE( child->getAnswer() == "1 Answer" );
  }

  SECTION ( "Navigates to the correct child when keyword present" ){
    std::shared_ptr<GraphNode> child = node->findChild("yes");

    REQUIRE( child->getID() == "1" );
    REQUIRE( child->getAnswer() == "1 Answer" );

    child = node->findChild("no");

    REQUIRE( child->getID() == "2" );
    REQUIRE( child->getAnswer() == "2 Answer" );
  }

  SECTION ( "Returns nullptr when keyword not present" ){
    std::shared_ptr<GraphNode> child = node->findChild("maybe");

    REQUIRE( child == nullptr );
  }
}

TEST_CASE( "When getting default node from an answer graph", "[getDefaultNode]" ) {
  GraphLoader loader(FIXTURE_ANSWER_GRAPH_PATH);
  std::shared_ptr<GraphNode> node = loader.getDefaultNode();

  SECTION ( "Returns the expected default id" ){
    REQUIRE( node->getID() == "default" );
  }

  SECTION ( "Returns the expected default answer" ){
    REQUIRE( node->getAnswer() == "Default Answer" );
  }

  SECTION ( "Navigates to the correct child when keyword present" ){
    std::shared_ptr<GraphNode> child = node->findChild("yes");

    REQUIRE( child->getID() == "1" );
    REQUIRE( child->getAnswer() == "1 Answer" );
  }

  SECTION ( "Navigates to the correct child when keyword present" ){
    std::shared_ptr<GraphNode> child = node->findChild("yes");

    REQUIRE( child->getID() == "1" );
    REQUIRE( child->getAnswer() == "1 Answer" );
  }

  SECTION ( "Returns nullptr when keyword not present" ){
    std::shared_ptr<GraphNode> child = node->findChild("maybe");

    REQUIRE( child == nullptr );
  }
}
