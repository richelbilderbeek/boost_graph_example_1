# boost_graph_example_1: four human names and their relationships + plotting

Branch|[![Travis CI logo](TravisCI.png)](https://travis-ci.org)
---|---
master|[![Build Status](https://travis-ci.org/richelbilderbeek/boost_graph_example_1.svg?branch=master)](https://travis-ci.org/richelbilderbeek/boost_graph_example_1)

[Boost.Graph example](https://github.com/richelbilderbeek/boost_graph_examples) that uses Graphviz.

It defines a graph of person names and their relationships. 
Then the graph is written to .dot file and plotted using KGraphViewer.



```
Writing graph to file #1:
graph G {
0;
1;
2;
3;
0--1 ;
1--2 ;
2--3 ;
0--3 ;
}

Writing graph to file #2:
graph G {
0;
1;
2;
3;
0--1 ;
1--2 ;
2--3 ;
0--3 ;
}
```