//
// Created by sebak on 4/30/2024.
//

#ifndef MYSUPERHASHMAP_OBSERVABLEKEY_H
#define MYSUPERHASHMAP_OBSERVABLEKEY_H
#include <string>
#include <vector>
#include <functional>

class ObservableKey {
private:
    std::string key;
    std::vector<std::function<void(const ObservableKey&)>> observers;
public:
    ObservableKey() : key("") {}  // Default constructor
    explicit ObservableKey(const std::string& initialKey);
    void setKey(const std::string& newKey);
    void notifyObservers() const;
    std::string getKey() const;
    void addObserver(std::function<void(const ObservableKey&)> observer);


    struct Hash {
        size_t operator()(const ObservableKey& obj) const {
            return std::hash<std::string>()(obj.getKey());
        }
    };

    bool operator==(const ObservableKey& other) const {
        return key == other.getKey();
    }
};

#endif //MYSUPERHASHMAP_OBSERVABLEKEY_H
