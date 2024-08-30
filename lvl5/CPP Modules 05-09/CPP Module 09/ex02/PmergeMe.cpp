#include "PmergeMe.hpp"

// INitialize and process inputs
PmergeMe::PmergeMe(int ac, char **av) {
    try {
        for (int i = 1; i < ac; ++i) {
            int num = atoi(av[i]);
            if (num < 0) throw NegativeNumber();
            add(num);
        }

        std::cout << "Before: ";
        displayVector(_vector);
        //displayList(_list);

        clock_t start_vector = clock();
        sortVector();
        clock_t end_vector = clock();
        double time_vector = double(end_vector - start_vector) / CLOCKS_PER_SEC;

        clock_t start_list = clock();
        sortList();
        clock_t end_list = clock();
        double time_list = double(end_list - start_list) / CLOCKS_PER_SEC;

        std::cout << "After: ";
        displayVector(_vector);
        //displayList(_list);

        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << time_vector * 1e6 << " us" << std::endl;
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::list : " << time_list * 1e6 << " us" << std::endl;
    }
    catch (const std::exception &e) {
        displayError(e.what());
    }
}

PmergeMe::PmergeMe(PmergeMe const &src) {
    *this = src;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &src) {
    if (this != &src) {
        _vector = src._vector;
        _list = src._list;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::add(int n) {
    if (std::find(_vector.begin(), _vector.end(), n) != _vector.end() ||
        std::find(_list.begin(), _list.end(), n) != _list.end()) {
        throw DuplicateNumber();
    }
    _vector.push_back(n);
    _list.push_back(n);
}

void PmergeMe::sortVector() {
    mergeInsertSort(_vector);
}

void PmergeMe::sortList() {
    mergeInsertSort(_list);
}

template <typename Container>
void PmergeMe::mergeInsertSort(Container& container) {
    if (container.size() <= 1) return;
    
    typename Container::iterator mid = container.begin();
    std::advance(mid, container.size() / 2);

    Container left(container.begin(), mid);
    Container right(mid, container.end());

    mergeInsertSort(left);
    mergeInsertSort(right);

    std::vector<typename Container::value_type> temp(container.size());
    std::merge(left.begin(), left.end(), right.begin(), right.end(), temp.begin());
    std::copy(temp.begin(), temp.end(), container.begin());
}

template <typename Container>
void PmergeMe::insertIntoSorted(Container& container) {
    typedef typename Container::iterator Iter;
    for (Iter it = container.begin(); it != container.end(); ++it) {
        typename Container::value_type value = *it;
        Iter pos = it;
        while (pos != container.begin() && *(--pos) > value) {
            *(pos + 1) = *pos;
        }
        *(pos + 1) = value;
    }
}

void PmergeMe::displayVector(const std::vector<int>& container) const {
    for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::displayList(const std::list<int>& container) const {
    for (std::list<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::displayError(const std::string& errorMsg) const {
    std::cerr << "Error: " << errorMsg << std::endl;
}

const char* PmergeMe::NegativeNumber::what() const throw() {
    return "Negative number encountered";
}

const char* PmergeMe::DuplicateNumber::what() const throw() {
    return "Duplicate number detected";
}
