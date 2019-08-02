SOURCES += main.cpp

# Compile with high warning levels, a warning is an error
QMAKE_CXXFLAGS += -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Weffc++ -Werror

# C++17
CONFIG += c++17
QMAKE_CXXFLAGS += -std=c++17

# Boost.Graph
LIBS += -lboost_graph
