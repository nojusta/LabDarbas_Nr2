# Kompiliatorius
CXX = g++

# Kompiliatoriaus parametrai
CXXFLAGS = -std=c++14 -O3 -mmacosx-version-min=14.3

# Vykdomo failo pavadinimas
TARGET = v2

# Source failai
SRCS = main.cpp functionality.cpp input.cpp calculations.cpp student.cpp

# Object failai
OBJS = $(SRCS:.cpp=.o)

# Google Test biblioteka
GTEST = /usr/local/lib/libgtest.a /usr/local/lib/libgtest_main.a

# Testuojami failai
TEST_SRCS = student_test.cpp

# Testuojami objekto failai
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Testuojamo failo pavadinimas
TEST_TARGET = student_test

# Taisyklė programa susieti
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to build the test executable
$(TEST_TARGET): student.o $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) student.o $(TEST_OBJS) $(GTEST)

# Taisyklė kompiliuoti failus
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<  -o $@

# Taisyklė išvalyti tarpinius failus
clean:
	$(RM) $(OBJS) $(TEST_OBJS)

# Taisyklė išvalyti viską
distclean: clean
	$(RM) $(TARGET) $(TEST_TARGET)