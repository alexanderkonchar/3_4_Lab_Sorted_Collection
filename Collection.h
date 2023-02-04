//
// Created by Alex on 1/24/23.
//

#ifndef INC_3_4_LAB_SORTED_COLLECTION_COLLECTION_H
#define INC_3_4_LAB_SORTED_COLLECTION_COLLECTION_H

#include <iostream>
#include <memory>

using namespace std;

template<typename Item>
class Collection;

template<typename Item>
ostream &operator<<(ostream &out, const Collection<Item> &c);

template<typename Item>
class Collection {
public:
    Collection();

    explicit Collection(int size);

    Collection(Collection<Item> &a);

    virtual int size();

    virtual Item get(int ndx);

    virtual void add(Item e);

    virtual void removeEnd();

    Collection<Item> &operator=(Collection<Item> const &a);

    virtual Item operator[](int ndx);

    virtual void operator-(int num);

    friend ostream &operator<<(ostream &out, const Collection<Item> &c);

protected:
    int capacity;
    int curSize;
    static const int INITIAL_CAPACITY = 8;

    void expand();

    unique_ptr<Item[]> elements;

};

template<typename Item>
Collection<Item>::Collection() {
    capacity = INITIAL_CAPACITY;
    curSize = 0;
    elements = make_unique<Item[]>(capacity);
}

template<typename Item>
Collection<Item>::Collection(int size) {
    capacity = size;
    curSize = 0;
}

template<typename Item>
Collection<Item>::Collection(Collection<Item> &a) {
    capacity = a.capacity;
    curSize = a.curSize;
    // Deep copy of the class
    elements = make_unique<Item[]>(capacity);
    for (int i = 0; i < curSize; ++i) {
        elements[i] = a.elements[i];
    }
}

template<typename Item>
int Collection<Item>::size() {
    return curSize;
}

template<typename Item>
Item Collection<Item>::get(int ndx) {
    return elements[ndx];
}

template<typename Item>
void Collection<Item>::add(Item e) {
    if (curSize == capacity) {
        expand();
    }
    elements[curSize] = e;
    curSize++;
}

template<typename Item>
void Collection<Item>::removeEnd() {
    curSize--;
    if (curSize < 0) {
        throw runtime_error("Empty List");
    }
}

template<typename Item>
Collection<Item> &Collection<Item>::operator=(Collection<Item> const &a) {
    auto newElements = make_unique<Item[]>(a.capacity);
    for (int i = 0; i < a.curSize; ++i) {
        newElements[i] = a.elements[i];
    }
    elements = std::move(newElements);
    capacity = a.capacity;
    curSize = a.curSize;

    return *this;
}

template<typename Item>
Item Collection<Item>::operator[](int ndx) {
    return get(ndx);
}

template<typename Item>
void Collection<Item>::operator-(int num) {
    for (int i = 0; i < num; ++i) {
        removeEnd();
    }
}

template<typename Item>
void Collection<Item>::expand() {
    auto newElements = make_unique<Item[]>(capacity * 2);
    for (int i = 0; i < capacity; ++i) {
        newElements[i] = elements[i];
    }
    elements = std::move(newElements);
    capacity *= 2;
}

template<typename Item>
ostream &operator<<(ostream &out, const Collection<Item> &c) {
    for (int i = 0; i < c.curSize; ++i) {
        out << c.elements[i];
        if (i < c.curSize - 1) out << " ";
    }
    return out;
}


#endif //INC_3_4_LAB_SORTED_COLLECTION_COLLECTION_H
