// A basic sample application using Junction.

#include <junction/ConcurrentMap_Grampa.h>

struct Foo {
};

void testMap() {
    // Create the map.
    typedef junction::ConcurrentMap_Grampa<turf::u32, Foo*> ConcurrentMap;
    ConcurrentMap myMap;

    // Do a few operations.
    myMap.assign(14, new Foo);
    Foo* foo = myMap.get(14);
    foo = myMap.exchange(14, new Foo);
    delete foo;
    foo = myMap.erase(14);
    delete foo;
}

int main() {
    // Create QSBR context for the main thread.
    junction::QSBR::Context context = junction::DefaultQSBR.createContext();

    // Run a simple map test.
    testMap();

    // Update the QSBR context for this thread.
    // In a larger application, this should be called periodically, for each thread, at a moment
    // when the thread is quiescent – that is, not in the middle of any operation that uses a
    // Junction data structure.
    junction::DefaultQSBR.update(context);

    // Destroy the QSBR context for the main thread.
    junction::DefaultQSBR.destroyContext(context);
    return 0;
}
