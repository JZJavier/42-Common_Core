#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <ctime>
#include <stdexcept>
#include <algorithm>

class PmergeMe
{
private:
    std::vector<int> _vector;
    std::list<int> _list;

    void add(int n);
    void sortVector();
    void sortList();
    template <typename Container>
    void mergeInsertSort(Container& container);
    template <typename Container>
    void insertIntoSorted(Container& container);
    void displayVector(const std::vector<int>& container) const;
    void displayList(const std::list<int>& container) const;
    void displayError(const std::string& errorMsg) const;

    class NegativeNumber : public std::exception {
        virtual const char* what() const throw();
    };

    class DuplicateNumber : public std::exception {
        virtual const char* what() const throw();
    };
public:
    PmergeMe(int ac, char **av);
    PmergeMe(PmergeMe const &src);
    PmergeMe &operator=(PmergeMe const &src);
    ~PmergeMe();
};

#endif 
