#include <iostream>
using namespace std;

template <typename T>
void selectionSort(T arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

int main()
{
    while (true) {
        cout << "---------------MENU---------------\n1) Sort integer array.\n2) Sort float array.\n3) Exit.\nEnter your choice: ";
        int ch;
        cin >> ch;
        switch(ch) {
            case 1:
                int iArr[20];
                int i, n;

                cout << "Enter number of elements in array: ";
                cin >> n;
                cout << endl;

                for (i = 0; i < n; i++) {
                    cout << "Enter your element " << i + 1 << ": ";
                    cin >> iArr[i];
                }
                cout << endl;

                cout << "Before sorting: ";
                for (i = 0; i < n; i++) {
                    cout << iArr[i] << " ";
                }
                cout << endl;

                selectionSort(iArr, n);

                cout << "After sorting: ";
                for (i = 0; i < n; i++) {
                    cout << iArr[i] << " ";
                }
                cout << endl << endl;

                break;
            case 2:
                float fArr[20];

                cout << "Enter number of elements in array: ";
                cin >> n;
                cout << endl;

                for (i = 0; i < n; i++) {
                    cout << "Enter your element " << i + 1 << ": ";
                    cin >> fArr[i];
                }
                cout << endl;

                cout << "Before sorting: ";
                for (i = 0; i < n; i++) {
                    cout << fArr[i] << " ";
                }
                cout << endl;

                selectionSort(fArr, n);

                cout << "After sorting: ";
                for (i = 0; i < n; i++) {
                    cout << fArr[i] << " ";
                }
                cout << endl << endl;

                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                return 0;
        }
    }
}
