//
// Created by Alex on 4/27/23.
//

#ifndef INC_3_4_LAB_SORTED_COLLECTION_SORTEDCOLLECTION_H
#define INC_3_4_LAB_SORTED_COLLECTION_SORTEDCOLLECTION_H

#include "Collection.h"

template<class Type>
class SortedCollection : public Collection<Type> {
public:
    SortedCollection<Type>();

    explicit SortedCollection<Type>(int size);

    SortedCollection<Type>(SortedCollection<Type> &a);

    void add(Type e) override;

    SortedCollection<Type> &operator+(Type c);

    SortedCollection<Type> &operator<<(Type c);
};

template<class Type>
SortedCollection<Type>::SortedCollection() : Collection<Type>() {}

template<class Type>
SortedCollection<Type>::SortedCollection(int size) : Collection<Type>(size) {}

template<class Type>
SortedCollection<Type>::SortedCollection(SortedCollection<Type> &a) : Collection<Type>(a) {}

template<class Type>
void SortedCollection<Type>::add(Type e) {
    Collection<Type>::add(e);
    for (int i = this->curSize; i > 0; --i) {
        Type b = this->elements[i - 1];
        if (e < b) {
            this->elements[i - 1] = e;
            this->elements[i] = b;
        }
    }
}

template<class Type>
SortedCollection<Type> &SortedCollection<Type>::operator+(Type c) {
    add(c);
    return *this;
}

template<class Type>
SortedCollection<Type> &SortedCollection<Type>::operator<<(Type c) {
    return *this + c;
}

#endif //INC_3_4_LAB_SORTED_COLLECTION_SORTEDCOLLECTION_H
