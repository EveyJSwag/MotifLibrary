EXEC := MOTIF_EXEC 
DIRS := include/ src/ prototype/ db_interface/ util/
FILES := $(foreach file,$(DIRS),$(wildcard $(file)*.cpp))
OBJS := $(foreach c_file,$(FILES),$(patsubst %.cpp,%.o,$(c_file)))
CLANG := g++
GCC := cc 
COMP_FLAGS := -std=c++11 -g
LIB := -g -lXm -lXt -lX11 -lstdc++ -lpthread -L/opt/oracle/instantclient_21_1 -locci -L/opt/oracle/instantclient_21_1 -lclntsh 
INCLUDE = -I/home/everett/Projects/motif/include/ -I/home/everett/Projects/motif/prototype/  -I/home/everett/Projects/motif/db_interface -I/home/everett/Projects/motif/util -I/opt/oracle/instantclient_21_1/sdk/include -I/home/everett/Projects/motif/pictures

$(EXEC): $(OBJS)
	$(CLANG) $(COMP_FLAGS) -o $(EXEC) $(OBJS) $(LIB) 

%.o : %.cpp
	$(CLANG) -c $(INCLUDE) $(COMP_FLAGS) $< -o $@ $(LIB)
		
.Phony: clean
clean:
	rm $(EXEC)
	rm src/*.o
	rm include/*.o
	rm prototype/*.o
	rm db_interface/*.o

.Phony: clean_obj
clean_obj:
	rm src/*.o
	rm include/*.o
	rm db_interface/*.o
	rm prototype/*.o

.Phony: clean_src
clean_src:
	rm src/*.o

.Phony: clean_include
clean_include:
	rm include/*.o

.Phony: clean_proto
clean_proto:
	rm prototype/*.o

.Phony: clean_exec
clean_exec:
	rm $(EXEC)
