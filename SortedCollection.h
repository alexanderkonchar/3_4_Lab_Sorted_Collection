//
// Created by Alex on 1/26/23.
//

#ifndef INC_3_4_LAB_SORTED_COLLECTION_SORTEDCOLLECTION_H
#define INC_3_4_LAB_SORTED_COLLECTION_SORTEDCOLLECTION_H

#include <ostream>
#include "Collection.h"

template<typename Item>
class SortedCollection : Collection<Item> {
public:
    SortedCollection();

    explicit SortedCollection(int size);

    explicit SortedCollection(Collection<Item> &collection);

    void add(Item toAdd);

    SortedCollection<Item> operator+(int num);

    SortedCollection<Item> operator<<(int num);
};

template<typename Item>
SortedCollection<Item>::SortedCollection() {
    this->capacity = this->INITIAL_CAPACITY;
    this->curSize = 0;
    this->elements = make_unique<Item[]>(this->capacity);
}

template<typename Item>
SortedCollection<Item>::SortedCollection(int size) {
    this->capacity = size;
    this->curSize = 0;
}

template<typename Item>
SortedCollection<Item>::SortedCollection(Collection<Item> &collection) {
    this->capacity = collection.capacity;
    this->curSize = collection.curSize;
    // Deep copy of the class
    this->elements = make_unique<Item[]>(this->capacity);
    for (int i = 0; i < this->curSize; ++i) {
        this->elements[i] = collection.elements[i];
    }
}

template<typename Item>
void SortedCollection<Item>::add(Item toAdd) {
    Collection<Item>::add(toAdd);
    for (int i = this->curSize - 1; i > 0; --i) {
        if (this->elements[this->curSize] > this->elements[this->curSize - 1]) {
            this->elements[this->curSize] = this->elements[this->curSize - 1];
            this->elements[this->curSize - 1] = toAdd;
        }
    }
}

template<typename Item>
SortedCollection<Item> SortedCollection<Item>::operator+(int num) {
    add(num);
    return *this;
}

template<typename Item>
SortedCollection<Item> SortedCollection<Item>::operator<<(int num) {
    add(num);
    return *this;
}

#endif //INC_3_4_LAB_SORTED_COLLECTION_SORTEDCOLLECTION_H
