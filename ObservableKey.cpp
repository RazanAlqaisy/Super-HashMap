//
// Created by sebak on 4/30/2024.
//
#include "ObservableKey.h"

ObservableKey::ObservableKey(const std::string& initialKey) : key(initialKey) {}

void ObservableKey::setKey(const std::string& newKey) {
    notifyObservers();
    key = newKey;

}

void ObservableKey::notifyObservers() const {
    for (const auto& observer : observers) {
        observer(*this);
    }
}

std::string ObservableKey::getKey() const {
    return key;
}
void ObservableKey::addObserver(std::function<void(const ObservableKey&)> observer) {
    observers.push_back(observer);
}



