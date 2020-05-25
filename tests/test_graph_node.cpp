#include "catch2/catch.hpp"

#include <string>
#include <memory>
#include <vector>

#include "../src/graph_node.h"
#include "../src/graph_edge.h"

TEST_CASE( "When moving a graph node", "[GraphNode]" ) {

  std::string id = "12345";
  std::string answer = "some answer";

  GraphNode source = GraphNode(id, answer);

  std::string keyword = "keyword";
  std::shared_ptr<GraphNode> childNode(new GraphNode(id, answer));
  std::vector<std::string> keywords = { keyword };
  std::unique_ptr<GraphEdge> edge(new GraphEdge(childNode.get(), childNode, keywords));
  source.addChildEdge(std::move(edge));

  GraphNode destination(std::move(source));

  SECTION ( "Source node no longer contains the answer" ){
    REQUIRE( source.getAnswer() == std::string() );
    REQUIRE( destination.getAnswer() == answer );
  }

  SECTION ( "Source node no longer contains the id" ){
    REQUIRE( source.getID() == std::string() );
    REQUIRE( destination.getID() == id );
  }

  SECTION ( "Source node no longer contains the child edges" ){
    REQUIRE( source.findChild(keyword) == nullptr );
    REQUIRE( destination.findChild(keyword) == childNode );
  }
}

TEST_CASE( "When moving a graph node with assigment", "[operator=]" ) {

  std::string id = "12345";
  std::string answer = "some answer";

  GraphNode source = GraphNode(id, answer);

  std::string keyword = "keyword";
  std::shared_ptr<GraphNode> childNode(new GraphNode(id, answer));
  std::vector<std::string> keywords = { keyword };
  std::unique_ptr<GraphEdge> edge(new GraphEdge(childNode.get(), childNode, keywords));
  source.addChildEdge(std::move(edge));

  GraphNode destination;
  destination = std::move(source);

  SECTION ( "Source node no longer contains the answer" ){
    REQUIRE( source.getAnswer() == std::string() );
    REQUIRE( destination.getAnswer() == answer );
  }

  SECTION ( "Source node no longer contains the id" ){
    REQUIRE( source.getID() == std::string() );
    REQUIRE( destination.getID() == id );
  }

  SECTION ( "Source node no longer contains the child edges" ){
    REQUIRE( source.findChild(keyword) == nullptr );
    REQUIRE( destination.findChild(keyword) == childNode );
  }
}

TEST_CASE( "When getting the answer from a graph node", "[getAnswer]" ) {

  SECTION ( "And uses the default constructor " ) {
    GraphNode node;

    SECTION ( "Contains an empty answer" ){
      REQUIRE( node.getAnswer() == std::string() );
    }
  }

  SECTION ( "And uses a constructor specifiying an answer" ) {
    std::string answer = "some answer in the node";
    GraphNode node = GraphNode("someid", answer);

    SECTION ( "Contains the expected answer" ){
      REQUIRE( node.getAnswer() == answer );
    }
  }
}

TEST_CASE( "When getting the id from a graph node", "[getID]" ) {

  SECTION ( "And uses the default constructor " ) {
    GraphNode node;

    SECTION ( "Contains an empty id" ){
      REQUIRE( node.getID() == std::string() );
    }
  }

  SECTION ( "And uses a constructor specifiying an id" ) {
    std::string id = "123456";
    GraphNode node = GraphNode(id, "some answer");

    SECTION ( "Contains the expected id" ){
      REQUIRE( node.getID() == id );
    }
  }
}

TEST_CASE( "Finding a child node based on a sentence", "[findChild]" ) {

  std::string id = "12345";
  std::string answer = "some answer";

  GraphNode node = GraphNode(id, answer);

  std::string keyword = "keyword";
  std::shared_ptr<GraphNode> childNode(new GraphNode(id, answer));
  std::vector<std::string> keywords = { keyword };
  std::unique_ptr<GraphEdge> edge(new GraphEdge(childNode.get(), childNode, keywords));
  node.addChildEdge(std::move(edge));

  SECTION ( "And the keyword does not exist " ) {
    std::string searchSentence = "somethingnotexisting";

    SECTION ( "Returns a nullptr" ){
      REQUIRE( node.findChild(searchSentence) == nullptr );
    }
  }

  SECTION ( "And the keyword does exist in a sentence" ) {
    std::string searchSentence = "really cool phrase but I want to find this keyword in the algorithm";

    SECTION ( "Returns the expected child node" ){
      REQUIRE( node.findChild(searchSentence) == childNode );
    }
  }

  SECTION ( "And the keyword does exist stand alone" ) {
    std::string searchSentence = "keyword";

    SECTION ( "Returns the expected child node" ){
      REQUIRE( node.findChild(searchSentence) == childNode );
    }
  }
}

TEST_CASE( "Checking if a node is a leave", "[isLeaf]" ) {
  std::string id = "12345";
  std::string answer = "some answer";

  SECTION ( "When the node has no childs" ) {
    GraphNode node = GraphNode(id, answer);

    SECTION ( "Returns true" ){
      REQUIRE( node.isLeaf() == true );
    }
  }

  SECTION ( "When the node has at least one child" ) {
    GraphNode node = GraphNode(id, answer);

    std::string keyword = "keyword";
    std::shared_ptr<GraphNode> childNode(new GraphNode(id, answer));
    std::vector<std::string> keywords = { keyword };
    std::unique_ptr<GraphEdge> edge(new GraphEdge(childNode.get(), childNode, keywords));
    node.addChildEdge(std::move(edge));

    SECTION ( "Returns false" ){
      REQUIRE( node.isLeaf() == false );
    }
  }
}

TEST_CASE( "Finding a child node based on ID", "[findChildByID]" ) {
  std::string id = "12345";
  std::string answer = "some answer";

  SECTION ( "When the id exists" ) {
    GraphNode node = GraphNode(id, answer);

    std::string keyword = "keyword";
    std::shared_ptr<GraphNode> childNode(new GraphNode(id, answer));
    std::vector<std::string> keywords = { keyword };
    std::unique_ptr<GraphEdge> edge(new GraphEdge(childNode.get(), childNode, keywords));
    node.addChildEdge(std::move(edge));

    SECTION ( "Returns expected node" ){
      REQUIRE( node.findChildByID(id) == childNode );
    }
  }

  SECTION ( "When the id does not exists" ) {
    GraphNode node = GraphNode(id, answer);
    std::string nonExistingID = "noexisting1234id";

    SECTION ( "Returns nullptr" ){
      REQUIRE( node.findChildByID(nonExistingID) == nullptr );
    }
  }
}
