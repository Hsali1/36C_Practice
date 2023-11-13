#include <iostream>

template<typename K>
void merge_sort_merge(std::vector<K> &a, std::vector<k> &aux, // &a is the collection we want to sort. We want to sort it between lo and hi
                      int lo, int mid, int hi){     // aux is a space so we can do the merge without touching the origina collection
    // Save both halves into auxiliary space
    for(int k = lo; k <= hi; k++){ // Copy everything into the auxiliary array
        aux[k] = a[k];
    }
    // Merge the two halves: [lo,mid][mid+1,hi]
    int i = lo, j = mid + 1;
    for(int k = lo; k <= hi; k++){
        // first 2 if statements check if any half is completely sorted. mainly useful when coming to an end
        // Right half has been entierely merged
        if(i > mid)
            // Just take what's remaining from left half
            a[k] = aux[j++];
        // Left half has been entirely merged
        else if(j > hi)
            // Just take what's remaining from right half
            a[k] = aux[i++];
        // The below two if statements is where the comparison actually happens
        // Get smallest item from either left or right halves
        else if(aux[j] < aux[i])
            a[k] = aux[j++];
        else
            a[k] = aux[i++];
    }
};

template<typename k>
void merge_sort_recur(std::vector<K> &a, std::vector<K> &aux, int lo, int hi){
    // Recursion stop condition: subarray is sorted if it contains 0 or 1 item
    if(hi <= lo)
        return;
    // Otherwise, further divide subarray into two halves
    int mid = lo + (hi - lo) / 2;
    // Recursively sort right half
    merge_sort_recur(a, aux, lo, mid);
    merge_sort_recur(a, aux, mid + 1, hi);
    // Merge two halves
    merge_sort_merge(a, aux, lo, mid, hi);
};

template<typename K>
void merge_sort(std::vector<K> &a){
    // Need auxiliary space of the same size
    std::vector<K> aux(a.size());
    merge_sort_recur(a, aux, 0, a.size() - 1);
};