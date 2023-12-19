.PHONY: run

SCALA_BUILD_ROOT=../scala/target/universal/stage
CXX=gcc
SOURCE=main.cpp
INCLUDE=$(addprefix -I, $(wildcard $(SCALA_BUILD_ROOT)/jre/include/) $(dir $(wildcard $(SCALA_BUILD_ROOT)/jre/include/*/*)))
LIB=$(addprefix -L, $(SCALA_BUILD_ROOT)/jre/lib $(SCALA_BUILD_ROOT)/jre/lib/server)

runner: $(SOURCE)
	$(CXX) $(SOURCE) $(INCLUDE) $(LIB) -ljvm -Wl,-rpath,$(SCALA_BUILD_ROOT)/jre/lib/server -o runner

run: DEBUG="-verbose:jni"
run: runner
	./runner "-Djava.class.path=$(SCALA_BUILD_ROOT)/lib/com.example.scala-seed-project-0.1.0-SNAPSHOT.jar:$(SCALA_BUILD_ROOT)/lib/org.scala-lang.scala-library-2.13.12.jar" $(DEBUG)
