#include <iostream>
#include "unordered_map"
#include "ObservableKey.h"
#include "SuperHashMap.h"
using namespace std;
int main() {
    std::unordered_map<ObservableKey, int, ObservableKey::Hash> m;
    SuperHashMap<int> mp;
    ObservableKey key1 = ObservableKey("key1");
    mp.insert(key1, 4);
    cout << mp[key1]<<endl;
    key1.setKey("modefied");
    cout <<mp[key1]<<endl;



    std::cout << "Hello, World!" << std::endl;
    return 0;
}
