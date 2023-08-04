#include <vector>

int sum(std::vector<int> nums)
{
    if (nums.empty())
        return 0;
    int result = 0;
    for (int &num : nums)
        result += num;
    return result;
}

// ....................................................................

#include <vector>
#include <numeric>

int sum(std::vector<int> nums)
{
    return std::accumulate(nums.begin(), nums.end(), 0);
}

// ....................................................................

#include <vector>
#include <numeric>

int sum(std::vector<int> nums)
{
    return std::reduce(nums.begin(), nums.end());

    return std::reduce(begin(nums), end(nums));
}

// ....................................................................

#include <numeric>
#include <vector>

int sum(const std::vector<int> &nums)
{
    return std::accumulate(nums.cbegin(), nums.cend(), 0);
}


/*
Difference between nums.begin() and nums.cbegin(), and nums.end() and nums.cend():

In C++, begin() and end() are member functions of a container, such as std::vector,
that return iterators pointing to the beginning and one past the end of the container, respectively. On the other hand.

cbegin() and cend() are member functions introduced in C++11 that return constant iterators pointing to the beginning
and one past the end of the container, respectively.

The main difference between the regular and constant versions of these functions is the constness of the iterators they return:

- begin() and end() return iterators that allow modification of the elements they point to.
This means you can use these iterators to both read and modify the elements in the container.

- cbegin() and cend() return constant iterators that enforce immutability.
You can use these iterators to read the elements but not modify them.
Attempting to modify the elements through constant iterators will result in a compilation error.

In the provided code, both versions of the sum function are correct and achieve the same result.

The first version takes a copy of the vector (std::vector<int> nums) and uses nums.begin() and nums.end() to iterate over the elements.

The second version takes a const reference to the vector (const std::vector<int>& nums) and uses nums.cbegin() and nums.cend()
to iterate over the elements, ensuring that the elements are not modified within the function.

Using the constant versions (cbegin() and cend()) is generally recommended when you only need to read the elements of a container
and want to ensure immutability and prevent accidental modifications.

*/