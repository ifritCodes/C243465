#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};
bool compare(Activity a1, Activity a2) {
    return a1.finish < a2.finish;
}
int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
    Activity act[n];
    cout << "Enter start and finish times of activities:\n";
    for(int i = 0; i < n; i++) {
        cin >> act[i].start >> act[i].finish;
    }
    sort(act, act + n, compare);
    cout << "Selected activities are:\n";
    int lastFinish = 0;
    for(int i = 0; i < n; i++) {
        if(act[i].start >= lastFinish) {
            cout << "(" << act[i].start << ", " << act[i].finish << ") ";
            lastFinish = act[i].finish;
        }
    }
    return 0;
}
