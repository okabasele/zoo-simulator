zooSimulator: main.o budget.o zoo.o habitat.o ianimal.o tigre.o aigle.o poule.o events.o
	g++ main.o budget.o zoo.o habitat.o ianimal.o tigre.o aigle.o poule.o events.o -o zooSimulator

main.o: main.cpp
	g++ -c main.cpp

ianimal.o: ianimal.cpp ianimal.h
	g++ -c ianimal.cpp

tigre.o: tigre.cpp tigre.h
	g++ -c tigre.cpp

aigle.o: aigle.cpp aigle.h
	g++ -c aigle.cpp

poule.o: poule.cpp poule.h
	g++ -c poule.cpp

zoo.o: zoo.cpp zoo.h
	g++ -c zoo.cpp

events.o: events.cpp events.h
	g++ -c events.cpp

habitat.o: habitat.cpp habitat.h
	g++ -c habitat.cpp

budget.o: budget.cpp budget.h
	g++ -c budget.cpp

clean:
	rm *.o zooSimulator