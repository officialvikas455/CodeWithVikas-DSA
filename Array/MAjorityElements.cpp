#include<iostream>
#include<vector>
using namespace std;
        int majorityElement(vector<int>& arr) {
            int count = 0, candidate = -1;
    
            // Phase 1: Find a candidate for the majority element
            for (auto vikas : arr) {
                if (count == 0) {
                    candidate = vikas; // Set the candidate
                }
                count += (vikas == candidate) ? 1 : -1; // Increment or decrement count
            }
    
            // Phase 2: Verify the candidate
            count = 0;
            for (auto vikas : arr) {
                if (vikas == candidate) {
                    count++;
                }
            }
    
            // Check if the candidate is indeed the majority element
            if (count > arr.size() / 2) {
                return candidate;
            }
    
            // If no majority element is found, return -1 or handle as needed
            return -1; // or throw an exception
        }

    int main(){
        vector<int> arr = {1,2,3,3,4,4,4,4,4};
        cout << " The majority element is : " <<majorityElement(arr);
        return 0;
    }