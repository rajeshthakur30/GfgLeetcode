#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    int arr[n-1];
    cout << "Enter " << n-1 << " elements: ";
    for(int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }

    // Sum of first n natural numbers
    int total = n * (n + 1) / 2;

    // Sum of array elements
    int sum = 0;
    for(int i = 0; i < n-1; i++) {
        sum += arr[i];
    }

    cout << "Missing element is: " << total - sum << endl;

    return 0;
}
