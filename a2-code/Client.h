#ifndef CLIENT_H
#define CLIENT_H

#include "Network.h"

class Client{
    public:
        Client(const string&);
        ~Client();

        void download(Network*, const string&);
        void stream(Network*, const string&, int) const;
        void playLocal(const string&, int) const;

        void print() const;

    private:
        const string name;
        PodArray* podArr;
};

#endif