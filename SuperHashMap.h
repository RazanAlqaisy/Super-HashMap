//
// Created by sebak on 4/30/2024.
//

#ifndef MYSUPERHASHMAP_SUPERHASHMAP_H
#define MYSUPERHASHMAP_SUPERHASHMAP_H
#include <unordered_map>
#include <stdexcept>
#include "ObservableKey.h"

using namespace std;
template<typename V>
class SuperHashMap {
    unordered_map<ObservableKey, V, ObservableKey::Hash> superHashMap;
public:
    SuperHashMap() : superHashMap() {}
    void insert(ObservableKey& key, const V& value);
    void remove(const ObservableKey& key);
    const V& get(const ObservableKey& key) const;
    bool contains(const ObservableKey& key) const;
    V& operator[](const ObservableKey& key);
    void update(ObservableKey source, ObservableKey updated);

};



template<typename V>
void SuperHashMap<V>::insert( ObservableKey& key, const V& value) {
    superHashMap[key] = value;
    key.addObserver([this, &key](const ObservableKey& updatedKey) {
        this->update(key, updatedKey);
    });
}


template<typename V>
void SuperHashMap<V>::remove(const ObservableKey& key) {
    superHashMap.erase(key);
}

template<typename V>
const V& SuperHashMap<V>::get(const ObservableKey& key) const {
    auto it = superHashMap.find(key);
    if (it != superHashMap.end()) {
        return it->second;
    }
    // Handle key not found, possibly throw an exception
    throw std::out_of_range("Key not found in SuperHashMap");
}

template<typename V>
V& SuperHashMap<V>::operator[](const ObservableKey& key) {
    // Handle key not found, possibly insert a default-constructed V
    return superHashMap[key];
}

template<typename V>
bool SuperHashMap<V>::contains(const ObservableKey& key) const {
    return superHashMap.find(key) != superHashMap.end();
}
template<typename V>
void SuperHashMap<V>::update(ObservableKey source, ObservableKey updated) {
    if(!this->contains(source)) return;
    V value = this->get(source);
    this->remove(source);
    this->insert(updated, value);

}


#endif //MYSUPERHASHMAP_SUPERHASHMAP_H
