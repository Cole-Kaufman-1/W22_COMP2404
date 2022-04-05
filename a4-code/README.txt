Cole Kaufman
101152549

File Descriptions:
    Control.h & Control.cc
        Header file and source code for the control object, Provides a test framework for the Airline.
    
    defs.h
        Header file containing constants used in the program.

    Array.h
        Header file and source code (combined) for the Array container object, A simple (templated) data structure.
    
    main.cc
        Main function used to launch the control object.

    Date.h & Date.cc
        Header file and source code for the Date entity object, Stores information of a date.

    Part.h & Part.cc 
        Header file and source code for all Part entity object variations, contains Part, FH_Part, IT_Part, and FHIT_Part.

    Aircraft.h & Aircraft.cc
        Header file and source code for Aircraft entity/container object, Aircraft data as well as a container for the installed Parts.

    Airline.h & Airline.cc  
        Header file and source code for Airline control object, Tracks parts, aircraft, installations, flights, etc.

    View.h and View.cc  
        Header file and source code for view object, Collects user input and provides system output.

Compilation & Execution Instructions:
    1. Type "make" to compile and link the program
    2. Type "./a4" to run the program, prefix "./a4" with valgrind to check for memory leaks

Additional Notes:
    Similar to A3 some comments were added for clarification but overall most of the code is quite easy to understand without it.
    As Prof. Hill says the best code is self-documenting (with exceptions), this is what I was aiming for.

