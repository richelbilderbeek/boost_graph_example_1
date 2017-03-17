#include <fstream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>

//C++14 and Boost
auto f() noexcept
{
  boost::adjacency_list<> g;
  boost::add_vertex(g);
  return boost::num_vertices(g);
}

int main()
{
  if (f() != 1) return 1;

  //Define the type of graph:
  //boost::adjacency_list is the 'Swiss army knife' graph
  typedef boost::adjacency_list
  <
    //Store all out edges as a std::vector
    boost::vecS,
    //Store all vertices in a std::vector
    boost::vecS,
    //Relations are both ways (in this example)
    //(note: but you can freely change it to boost::directedS)
    boost::undirectedS,
    //All vertices are person names of type std::string
    boost::property<boost::vertex_name_t,std::string>,
    //All edges are relation of type std::string
    boost::property<boost::edge_name_t,std::string>
  > Graph;

  Graph g;

  const auto v1 = boost::add_vertex(std::string("Mr. A"),g);
  const auto v2 = boost::add_vertex(std::string("Mrs. B"),g);
  const auto v3 = boost::add_vertex(std::string("Dr. C"),g);
  const auto v4 = boost::add_vertex(std::string("Prof. D"),g);
  boost::add_edge(v1,v2,std::string("Married"),g);
  boost::add_edge(v2,v3,std::string("Lovers"),g);
  boost::add_edge(v3,v4,std::string("Collegues"),g);
  boost::add_edge(v1,v4,std::string("Roommates"),g);

  //Write graph to std::cout
  boost::write_graphviz(std::cout,g);

  //Writing graph to file
  {
    std::ofstream f("test.dot");
    //Problems:
    //- All names are replaced by numbers
    //- All relationships are omitted
    boost::write_graphviz(f,g);
  }

  {
    std::ifstream f("test.dot");
    Graph h;
    boost::dynamic_properties dp(
      boost::ignore_other_properties
    );
    boost::read_graphviz(f,h,dp);
    boost::write_graphviz(std::cout,h);
  }
}
