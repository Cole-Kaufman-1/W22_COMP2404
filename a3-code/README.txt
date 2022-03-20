Cole Kaufman
101152549

File Descriptions:
    A3_UML.png
        A UML diagram for A3. 

    Control.h & Control.cc
        Header file and source code for the Control object, Controls the interaction between the inventory system (Store) and the user.
    
    Defs.h
        Header file containing constants used in the program.

    List.h & List.cc
        Header file and source code for the List container object, a list of Products that can grow arbitrarily large.
    
    Location.h & Location.cc
        Header file and source code for the Location entity object, a virtual base class for StoreLocation and WHLocation classes.

    Main.cc
        Main function used to launch the control object.

    Product.h & Product.cc
        Header file and source code for the Product entity object, contains information about the product, including the StoreLocation and WHLocations it is stored in.

    Queue.h & Queue.cc
        Header file and source code for the Queue container object, a first-in-first-out (FIFO) data structure for storing WHLocations. The FIFO nature of the data structure
        ensures that we use older stock first.

    Store.h & Store.cc
        Header file and source code for the Store control object, provides an interface for interacting with the inventory system.

    StoreLocation.h & StoreLocation.cc
        Header files and source code for the StoreLocation entity object, concrete implementation for in-store product locations.

    View.h & View.cc
        Header files and source code for the view object, collects user input and provides system output.

    WHLocation.h & WHLocation.cc
        Header files and source code for the WHLocation entity object, concrete implementation for warehouse product locations.

Compilation & Execution Instructions:
    1. Type "make" to compile and link the program
    2. Type "./a3" to run the program, prefix "./a3" with valgrind to check for memory leaks

Additional Notes:
    Similar to A2 some comments were added for clarification but overall most of the code is quite easy to understand without it.
    As Prof. Hill says the best code is self-documenting (with exceptions), this is what I was aiming for.

    I have commented out initStore() in control.cc, uncommment it to initialize the store with default values.

    I added a 6th and 7 option to run the additional test that were provided but not utilized.