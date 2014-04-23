index: compile runindex clean

compile:
	javac FileIndexer.java

runindex:
	java FileIndexer

clean:
	rm FileIndexer.class

# CPP
run:
	sh ./run.sh

rebuild:
	sh ./sh/build.sh

test: rebuild run

remake: index test