#include "Customer.h"
#include <iostream>
#include <vector>
#include <string>

template <class T>
class CrudRepository {
protected:
    virtual void createObject(T object);
    virtual std::vector<T> findAll(T object);
    virtual void update(T object);
    virtual void deleteObject(T object) = 0; // virtual = abstract class
};