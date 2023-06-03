/*
"MagicalContainer" that can store integers representing mystical elements. 
Implement necessary methods for adding elements, removing elements, and retrieving the size of the container. 
You can use a dynamic array or any other suitable data structure for internal storage.
*/

#pragma once
#include <vector> // dynamic array for internal storage

class MagicalContainer {
private:
    std::vector<int> Container;
    std::vector<int> Ascending_Container;
    std::vector<int> Prime_Container;
    std::vector<int> Cross_Container;

/*
Every time we are using the function addEelement we need to update the other Container
We will update the Ascending_Container , Prime and Cross.
*/
    void updateAscending();
    void updatePrime();
    void updateCross();

// We are going to use the function isPrime for the Prime_Container
    bool isPrime(int number);

/*
We dont want the same element in our Container , checking if he is there or not
Example : The vector is : 1 14 8 9 6 , we are trying the add now 6 : we are not adding 6  
*/ 
    bool isExist(int number);

public:
    void addElement(int element);

    void removeElement(int element);

    unsigned int getSize() const {
        return Container.size();
    }
// We dont need to create the operators for MagicalContainer because we are using vector from C++

    // The ascendingIterator going to allow traversal of elements in the MagicalContainer class in ascending order (sorted)
   class AscendingIterator {
    private:
    // current it's like a ptr , we are going to use current to travel on our Container
    std::vector<int>::iterator current;

    public:
    // Default constructor : I let the compiler create the default constructor

    // Parameter constructor
    AscendingIterator(std::vector<int>::iterator start);

    // Copy Constructor
    AscendingIterator(const AscendingIterator& other);

    // We don't need a destructor for this class
    ~AscendingIterator() {}

    // Operator = 
    AscendingIterator& operator=(const AscendingIterator& other);

    // Operator ==
    bool operator==(const AscendingIterator& other) const;

    // Operator !=
    bool operator!=(const AscendingIterator& other) const;

    // Operator >
    bool operator>(const AscendingIterator& other) const;

    // Operator <
    bool operator<(const AscendingIterator& other);

    // Operator * (like a ptr)
    int operator*() const;
    // Operator ++
    AscendingIterator& operator++();

};
    // Returns the appropriate iterator (ascending, cross, or prime) pointing to the first element of the container based on the specified type.
    AscendingIterator begin_ascending();

    // Returns the appropriate iterator (ascending, cross, or prime) pointing one position past the last element of the container based on the specified type.
    AscendingIterator end_ascending();


/*
SideCrossIterator going to allow traversal of elements in the MagicalContainer class with a special order 
Example : Container : 1 2 4 5 14  with the SideCross we got : 1 14 2 5 4
We are starting from the begin and the end we are going to do this until we are arrive in the "midle" of the Container
*/
    class SideCrossIterator {
    private:
    std::vector<int>::iterator current;

    public:
    SideCrossIterator();
    SideCrossIterator(std::vector<int>::iterator start);
    SideCrossIterator(const SideCrossIterator& other);
    ~SideCrossIterator();

    SideCrossIterator& operator=(const SideCrossIterator& other);
    bool operator==(const SideCrossIterator& other) const;
    bool operator!=(const SideCrossIterator& other) const;
    bool operator>(const SideCrossIterator& other) const;
    bool operator<(const SideCrossIterator& other) const;
    int operator*() const;
    SideCrossIterator& operator++();
};

    SideCrossIterator begin_sidecross();
    SideCrossIterator end_sidecross();

/*
PrimeIterator going to allow traversal of elements in the MagicalContainer class only on Prime numbers
Example : Container : 1 2 4 5 14 with PrimeIterator we got : 2 5
We are goign to use a function IsPrime
*/
    class PrimeIterator {
    private:
    std::vector<int>::iterator current;

    public:
    PrimeIterator();
    PrimeIterator(std::vector<int>::iterator start);
    PrimeIterator(const PrimeIterator& other);
    ~PrimeIterator();

    PrimeIterator& operator=(const PrimeIterator& other);
    bool operator==(const PrimeIterator& other) const;
    bool operator!=(const PrimeIterator& other) const;
    bool operator>(const PrimeIterator& other) const;
    bool operator<(const PrimeIterator& other) const;
    int operator*() const;
    PrimeIterator& operator++();
};
    // Returns the appropriate iterator (ascending, cross, or prime) pointing to the first element of the container based on the specified type.
    PrimeIterator begin_prime();
    // Returns the appropriate iterator (ascending, cross, or prime) pointing one position past the last element of the container based on the specified type.
    PrimeIterator end_prime();

};