CXX      = g++
CXXFLAGS = -std=c++17 -Wall -I.

TARGET = singleton_demo

SRCS = main.cpp \
       src/SequenceGenerator.cpp \
       src/NotificationManager.cpp \
       src/PrintQueue.cpp \
       src/VisitorCounter.cpp \
       src/AppClock.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
