# NOTE: 
    1. online websites: for continuous memory allocation: eg: array,vectors 
        - locally: we can store elem upto 1e5
        - globally: we can store elem upto 1e7 
        - else TLE/runtime err

    2.  Vector<datatype> name; // size 0
        Vector<int> v(10); // size 10 with all values == 0
        v.push_back(11); // size 11 i.e {000000000011}

        - is of dynamic size
        - v.size() // O(1)
        - v.push_back(elem), v.pop_back() // O(1)
        - vector<int> cpy = v; // O(n)















--------------------------------------------------------------------------------
# Containers 
    - Sequential (vectors, stack, queue, pairs)
    - Ordered (map, set, multimap, multiset)
    - Unordered (unordered_map, unordered_set)

# iterators
    - are pointers of STL containers

# Algorithms
    - are algos reqd in stl: written in best Time Complexity
    eg:
        - upper bound, lower bound, 
        - sort (comparator)
        - max_element, min_element -> to find min elem in array 
        - accumulate -> to find sum of all elem of array, 
        - reverse
        - count -> cnt of elem in a container
        - find -> pos of elem in container
        - next_permutation, prev_permutation

# Functors
    - Classes which can act as functions