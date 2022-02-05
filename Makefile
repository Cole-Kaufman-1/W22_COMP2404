OBJ = student.o room.o date.o reservation.o library.o main.o

main: $(OBJ)
	g++ -g -o main $(OBJ)

main.o: main.cc
	g++ -c -g main.cc

student.o: Student.cc Student.h
	g++ -c -g Student.cc

room.o: Room.cc Room.h
	g++ -c -g Room.cc

date.o: Date.cc Date.h
	g++ -c -g Date.cc

reservation.o: Reservation.cc Reservation.h 
	g++ -c -g Reservation.cc

library.o: Library.cc Library.h
	g++ -c -g Library.cc

a1-global.o: a1-global.cc 
	g++ -c -g a1-global.cc

clean: 
	rm -f main *.o