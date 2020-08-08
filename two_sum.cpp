#include <unordered_map>
#include <vector>

/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 */
std::vector<int> twoSum(std::vector<int>& v, int target) {
    // Hash table to store values and positions
    std::unordered_map<int, int> h;

    int c, s = v.size();
    for (int i = 0; i < s; i++) {
        // Calculate the opposing target value (target = a + b)
        c = target - v[i];
        
        // Check if the opposing target value exists in the hash table
        if (h.find(c) != h.end()) return { i, h[c] };

        // Else add it current value as a entry
        h[v[i]] = i;
    }
    return { 0, 1 };
}
