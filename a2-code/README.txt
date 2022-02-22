Cole Kaufman
101152549

File Descriptions:
    Subscriber.h & Subscriber.cc
        Header file and source code for the subscriber entity, stores info about a subscriber that represents a customer of the service.
    
    Episode.h & Episode.cc
        Header file and source code for the episode entity, stores info about and episode of a podcast.
    
    Podcast.h & Podcast.cc
        Header file and source code for the podcast entity, stores info about a podcast series as well as a collection of episode entities.

    PodArray.h & PodArray.cc
        Header file and source code for the PodArray collection, an array-backed data structure containing podcast entities. Used by the client and network objects.

    Network.h & Network.cc
        Header file and source code for the Network control/boundary object manages collections of Podcasts and Subscribers as well as providing service to the client object. Additionally prints error messages.

    Client.h & Client.cc
        Header file and source code for the Client control object represents a client interacting with the network to stream and download podcasts. Manages a "local" PodArray for downloads.

    TestControl.h, TestControl.cc, TestView.h & TestView.cc
        Header files and source code for testing, provided to us by the professor. No changes were made to these files.


Compilation & Execution Instructions:
    1. Type "make" to compile and link the program
    2. Type "./a2" to run the program, prefix "./a2" with valgrind to check for memory leaks

Additional Notes:
    Similar to A1 some comments were added for clarification  but overall most of the code is quite easy to understand without it.
    As Prof. Hill says the best code is self-documenting (with exceptions), this is what I was aiming for.