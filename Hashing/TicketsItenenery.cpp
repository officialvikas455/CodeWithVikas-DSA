#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

void printItinerary(unordered_map<string, string> tickets) {
    // Starting point
    unordered_set<string> to;

    for (pair<string, string>ticket : tickets) {
        to.insert(ticket.second);
    }
    string start= " ";
    for (pair<string,string> ticket : tickets) {
        if (to.find(ticket.first) == to.end()) {
            start = ticket.first;
            break; // Found the starting point, exit the loop
    
    }

    // Plan Tickets
    cout << start << " ";

    while (tickets.count(start) > 0) {
        cout << " -> " << tickets[start];
        start = tickets[start];
    }
    cout << " Destination\n";
}

int main() {
    unordered_map<string, string> tickets;

    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai"; // Corrected key
    tickets["Delhi"] = "Goa";

    printItinerary(tickets);

    return 0;
}
