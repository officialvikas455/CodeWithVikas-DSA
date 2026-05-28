#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class TicketsQueue {
public:
    int timeToBuyTickets(vector<int>& tickets, int k) {
        int n = tickets.size();
        int time = 0;
        queue<int> q;

        // Push all person indices into queue
        for(int i = 0; i < n; ++i) {
            q.push(i);
        }

        // Process until target person buys all tickets
        while(tickets[k] > 0) {
            int currentPerson = q.front();
            q.pop();
            
            if(tickets[currentPerson] > 0) {
                tickets[currentPerson]--;
                time++;
                
                // If person still needs tickets, push back to queue
                if(tickets[currentPerson] > 0) {
                    q.push(currentPerson);
                }
            }
        }
        return time;
    }
};

int main() {
    TicketsQueue ticketQueue;
    
    // Test Case 1
    vector<int> tickets1 = {2, 3, 2};
    int k1 = 1;
    int result1 = ticketQueue.timeToBuyTickets(tickets1, k1);
    cout << "Example 1: Time taken for person " << k1 << " to buy tickets: " << result1 << endl;
    
    // Test Case 2
    vector<int> tickets2 = {5, 1, 1, 1};
    int k2 = 0;
    int result2 = ticketQueue.timeToBuyTickets(tickets2, k2);
    cout << "Example 2: Time taken for person " << k2 << " to buy tickets: " << result2 << endl;
    
    return 0;
}