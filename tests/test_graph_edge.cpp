#include "catch2/catch.hpp"

#include <string>
#include <memory>
#include <vector>

#include "../src/graph_node.h"
#include "../src/graph_edge.h"

TEST_CASE( "When getting parent node of a graph edge", "[getParentNode]" ) {
  std::string id = "12345";
  std::string answer = "some answer";
  std::string keyword = "keyword";

  std::shared_ptr<GraphNode> node(new GraphNode(id, answer));

  std::vector<std::string> keywords = { keyword };

  SECTION ( "And the parent is nullptr " ) {
    GraphEdge edge(nullptr, node, keywords);

    SECTION ( "Returns nullptr" ){
      REQUIRE( edge.getParentNode() == nullptr );
    }
  }

  SECTION ( "And the parent exists " ) {
    GraphEdge edge(node.get(), node, keywords);

    SECTION ( "Returns the expected node" ){
      REQUIRE( edge.getParentNode() == node.get() );
    }
  }
}

TEST_CASE( "When getting child node of a graph edge", "[getChildNode]" ) {
  std::string id = "12345";
  std::string answer = "some answer";
  std::string keyword = "keyword";

  std::shared_ptr<GraphNode> node(new GraphNode(id, answer));

  std::vector<std::string> keywords = { keyword };

  SECTION ( "And the child is nullptr " ) {
    GraphEdge edge(node.get(), nullptr, keywords);

    SECTION ( "Returns nullptr" ){
      REQUIRE( edge.getChildNode() == nullptr );
    }
  }

  SECTION ( "And the child exists " ) {
    GraphEdge edge(node.get(), node, keywords);

    SECTION ( "Returns the expected node" ){
      REQUIRE( edge.getChildNode() == node );
    }
  }
}

TEST_CASE( "Check contains keyword in sentence case sensitive", "[containsKeyword]" ) {
  std::string id = "12345";
  std::string answer = "some answer";
  std::string keyword = "keyword";

  std::shared_ptr<GraphNode> node(new GraphNode(id, answer));

  std::vector<std::string> keywords = { keyword };

  GraphEdge edge(node.get(), node, keywords);

  SECTION ( "And the keyword does not exits " ) {
    std::string searchKeyword = "somethingnonexisting";

    SECTION ( "Returns false" ){
      REQUIRE( edge.containsKeyword(searchKeyword) == false );
    }
  }

  SECTION ( "And the keyword is not exactly the same string " ) {
    std::string searchKeyword = "Keyword";

    SECTION ( "Returns false" ){
      REQUIRE( edge.containsKeyword(searchKeyword) == false );
    }
  }

  SECTION ( "And the keyword is exactly the same string " ) {
    std::string searchKeyword = "keyword";

    SECTION ( "Returns true" ){
      REQUIRE( edge.containsKeyword(searchKeyword) == true );
    }
  }
}

TEST_CASE( "Check contains keyword in sentence case insensitive", "[containsKeywordIgnoreCase]" ) {
  std::string id = "12345";
  std::string answer = "some answer";
  std::string keyword = "keyword";

  std::shared_ptr<GraphNode> node(new GraphNode(id, answer));

  std::vector<std::string> keywords = { keyword };

  GraphEdge edge(node.get(), node, keywords);

  SECTION ( "And the keyword does not exits " ) {
    std::string searchKeyword = "somethingnonexisting";

    SECTION ( "Returns false" ){
      REQUIRE( edge.containsKeywordIgnoreCase(searchKeyword) == false );
    }
  }

  SECTION ( "And the keyword is not exactly the same string " ) {
    std::string searchKeyword = "Keyword";

    SECTION ( "Returns true" ){
      REQUIRE( edge.containsKeywordIgnoreCase(searchKeyword) == true );
    }
  }

  SECTION ( "And the keyword is exactly the same string " ) {
    std::string searchKeyword = "keyword";

    SECTION ( "Returns true" ){
      REQUIRE( edge.containsKeywordIgnoreCase(searchKeyword) == true );
    }
  }
}
