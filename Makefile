SOURCES  =  main.c utils.c
OBJECTS  =  $(SOURCES:.cpp=.o)
TARGET   =  task_manager
LIBS     =  -lm #$(shell sdl-config --libs) -lGL -lGLU -lglut

all: $(OBJECTS)
	gcc -o $(TARGET) $(OBJECTS) $(LIBS)


%o: %cpp
	gcc -o $@ -c $<


x: all
	./$(TARGET)


clean: 
	rm -rf $(TARGET)


superclean: clean
	rm -rf $(TARGET)

