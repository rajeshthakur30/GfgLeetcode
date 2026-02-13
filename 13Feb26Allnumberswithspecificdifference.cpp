#include <iostream>
using namespace std;

int main() 
{
    int n, k;
    
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter difference: ";
    cin >> k;

    cout << "Pairs with given difference:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(abs(arr[i] - arr[j]) == k)
                cout << arr[i] << " " << arr[j] << endl;
        }
    }

    return 0;
}
