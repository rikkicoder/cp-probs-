#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <typeindex>
#include <stdexcept>
#include <set>
#include <iomanip>
#include <utility>
#include <type_traits>

class WrapperBase {
public:
    virtual ~WrapperBase() = default;
    virtual void display() const = 0;
};

class SingletonManager {
public:
    static map<type_index, void*> regi;
};

map<type_index, void*> SingletonManager::regi;

template<typename T>
struct is_std_set : false_type {};
template<typename... Args>
struct is_std_set<set<Args...>> : true_type {};

template <typename T>
class SgtnHldr : public WrapperBase { // SgtnHldr :: SingletonHolder
private:
    T storedValue;
    explicit SgtnHldr(T value) : storedValue(move(value)) {}

public:
    SgtnHldr(const SgtnHldr&) = delete;
    SgtnHldr& operator=(const SgtnHldr&) = delete;

    ~SgtnHldr() override {
        SingletonManager::regi.erase(type_index(typeid(T)));
    }

    static SgtnHldr<T>* create(T initialValue) {
        type_index key(typeid(T));
        if (SingletonManager::regi.count(key)) {
            throw runtime_error("A singleton of this type already exists");
        }
        auto* instance = new SgtnHldr<T>(move(initialValue));
        SingletonManager::regi[key] = instance;
        return instance;
    }

    T get() const {
        return storedValue;
    }

    void set(T value) {
        storedValue = move(value);
    }

    void display() const override {
        if constexpr (is_std_set<T>::value) {
            bool fItem = true;
            if constexpr (is_same_v<typename T::value_type, float>) {
                cout << fixed << setprecision(2);
            }
            for (const auto& item : storedValue) {
                if (!fItem) cout << " ";
                cout << item;
                fItem = false;
            }
            cout << endl;
        } else if constexpr (is_same_v<T, float>) {
            cout << fixed << setprecision(2) << storedValue << endl;
        } else {
            cout << storedValue << endl;
        }
    }
};

int main() {
    vector<WrapperBase*> wrpsList;
    int q;
    cin >> q;
    cin.ignore();

    for (int i = 0; i < q; ++i) {
        string inputLine;
        getline(cin, inputLine);
        stringstream ss(inputLine);
        string commandType;
        ss >> commandType;

        try {
            if (commandType == "int") {
                int value;
                ss >> value;
                auto* holder = SgtnHldr<int>::create(value);
                wrpsList.push_back(holder);
                holder->display();
            } else if (commandType == "float") {
                float value;
                ss >> value;
                auto* holder = SgtnHldr<float>::create(value);
                wrpsList.push_back(holder);
                holder->display();
            } else if (commandType == "set<int>") {
                set<int> numbers;
                int value;
                while (ss >> value) numbers.insert(value);
                auto* holder = SgtnHldr<set<int>>::create(numbers);
                wrpsList.push_back(holder);
                holder->display();
            } else if (commandType == "set<float>") {
                set<float> numbers;
                float value;
                while (ss >> value) numbers.insert(value);
                auto* holder = SgtnHldr<set<float>>::create(numbers);
                wrpsList.push_back(holder);
                holder->display();
            } else if (commandType == "Delete") {
                int delIndex;
                ss >> delIndex;
                if (delIndex > 0 && delIndex <= static_cast<int>(wrpsList.size()) 
                    && wrpsList[delIndex - 1] != nullptr) {
                    delete wrpsList[delIndex - 1];
                    wrpsList[delIndex - 1] = nullptr;
                }
            }
        } catch (const runtime_error& error) {
            cout << error.what() << endl;
        }
    }

    for (auto* wrapperPtr : wrpsList) {
        delete wrapperPtr;
    }

    return 0;
}
