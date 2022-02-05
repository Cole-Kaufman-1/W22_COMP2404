Cole Kaufman
101152549

File Descriptions:
    main.cc
        Driver source code for the project, uses function from a1-global.cc to perform tests.

    Date.h & Date.cc
        Header file and source code for the date class, used to keep track of reservation day, month, year, and hour as well as duration.
    
    Library.h & Library.cc
        Header file and source code for the library class, used to maintain collections of students, rooms, and reservations.
        Facilitates new reservations being made and checking for overlaps in booking. 

    Reservation.h & Reservation.cc
        Header file and source code for the reservation class, used to associate a student, room, and date together for reservations to be made.

    Room.h & Room.cc
        Header file and source code for the room class, stores information about a room that can be reserved.

    Student.h & Student.cc
        Header and source code for the student class, stores unformation about a student that can reserve a room.

    a1-global.cc
        Source code provided with the assignment that contains methods for testing. Used by main.cc to facilitate testing.

Compilation & Exectution Instructions:
    1. Type "make a1" to compile and link
    2. Type "./a1" to run the program

Additional Note:
    I found most of the code quite easy to read and self documenting since there isn't much complexity in the logic here,
    Some comments are added for clarification where needed.