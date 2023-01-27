#include <iostream>
#include <vector>
#include <algorithm>

class cList {
    private:

    public:
        std::vector<int> numbers;
        // default constructor
        cList() {}
        // constructor that initializes list with a single number
        cList(int n) {
            numbers.push_back(n);
        }
        // copy constructor
        cList(const cList& other) {
            numbers = other.numbers;
        }
        // overloaded assignment operator
        cList& operator=(const cList& other) {
            numbers = other.numbers;
            return *this;
        }
        // overloaded addition operator (adds number to list)
        cList operator+(int n) {
            cList result = *this;
            result.numbers.push_back(n);
            return result;
        }
        // overloaded addition operator (concatenates lists)
        cList operator+(const cList& other) {
            cList result = *this;
            result.numbers.insert(result.numbers.end(), other.numbers.begin(), other.numbers.end());
            return result;
        }
        // overloaded subtraction operator (removes number from list)
        cList operator-(int n) {
            cList result = *this;
            result.numbers.erase(std::remove(result.numbers.begin(), result.numbers.end(), n), result.numbers.end());
            return result;
        }
        // overloaded subtraction operator (removes numbers from list)
        cList operator-(const cList& other) {
            cList result = *this;
            for (int i : other.numbers) {
                result = result - i;
            }
            return result;
        }
        // find function (returns true if number is in list, false otherwise)
        bool find(int n) {
            for (int i : numbers) {
                if (i == n) {
                    return true;
                }
            }
            return false;
        }
        // asort function (returns sorted list in ascending order)
        cList asort() {
            cList result = *this;
            std::sort(result.numbers.begin(), result.numbers.end());
            return result;
        }
        // reverse function (returns reversed list)
        cList reverse() {
            cList result = *this;
            std::reverse(result.numbers.begin(), result.numbers.end());
            return result;
        }
};

int main() {
    cList a;
    a = a + 1;
    a = a + 2;
    a = a + 3;
    std::cout << "List a: ";
    for (int i : a.numbers)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    cList b(4);
    b = b + 5;
    b = b + 6;
    std::cout << "List b: ";
    for (int i : b.numbers) {
        std::cout << i << " ";
}    }
