#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of persons: ";
    cin >> n;

    int height[n];

    cout << "Enter heights:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    int max = height[0];
    int min = height[0];

    for(int i = 1; i < n; i++)
    {
        if(height[i] > max)
            max = height[i];

        if(height[i] < min)
            min = height[i];
    }

    cout << "Maximum height = " << max << endl;
    cout << "Minimum height = " << min << endl;

    return 0;
}
