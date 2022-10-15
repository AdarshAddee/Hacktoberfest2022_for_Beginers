// header file
#include <iostream>

using namespace std;

// recursive function to do the sorting
void TowerOfHanoi(unsigned long long n, char from_rod, char to_rod,
                  char temp_rod)
{
    if (n == 0)
    {
        return;
    }
    TowerOfHanoi(n - 1, from_rod, temp_rod, to_rod);
    cout << "Moved disk " << n << " from rod " << from_rod
         << " to rod " << to_rod << endl;
    TowerOfHanoi(n - 1, temp_rod, to_rod, from_rod);
}

int main()
{
    // changed int to long long to increase the value intakes
    unsigned long long N;

    cout << "Enter the number of Disks : ";

    cin >> N;
    // A, B and C are names of rods A=first B=second C=third
    TowerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}
