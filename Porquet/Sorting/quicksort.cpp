#include <iostream>

template<typename K>
int quicksort_partition(std::vector<K> &a, int lo, int hi){
    int i = lo, j = hi + 1;
    while(true){
        // From left to right, find first item
        // Larger than pivot
        while(a[++i] < a[lo])
            // Prevents from groing out of bounds
            if(i == hi) break;
        // From right to left, find first item
        while(a[lo] < a[--j])
            // To keep code symmetry but unnecessary
            if(j == lo) break;
        // Pointers i and j have crossed, stop
        if(i >= j) break;
        std::swap(a[i], a[j])
    }
    // Put pivot(a[lo], a[j])
    std::swap(a[lo], a[j]);
    // Return pivot position
    return j;
};

template<typename K>
void quicksort_recur(std::vector<K> &a, int lo, int hi){
    // Recusrion stop condition:
    // Sub-array is sorted if it containts 0 or 1 item
    if(hi <= lo)
        return;

    // Partition array and get resulting pivot pos
    int p = quicksort_partition(a, lo, hi);
    // Recursively sort left sub-partition
    quicksort_recur(a, lo, p - 1);
    quicksort_recur(a, p + 1, hi);
};

// Generic quicksort function
template<typename K>
void quicksort(std::vector<K> &a){
    quicksort_recur(a, 0, a.size() - 1);
};