#include <iostream>
#include <vector>
using namespace std;

int main() {
    //12.	Разбить элементы массива на группы по k элементов. В каждой группе осуществить сдвиг влево на 1. Первый на k-oe место. Если количество элементов в массиве не кратно k, то для последней группы сдвиг осуществляется для того количества элементов, которое осталось.
    
    int n,k;
    cout << "enter number of items in the list: ";
    cin >> n;
    cout << "enter number of items in the each group: ";
    cin >> k;
    cout << "enter items of the list: ";
    vector <int> a(n);
    vector <int> b(k);
    vector <int> c(n % k);
    for (int i = 0; i < n; i++)
        cin >> a[i];

        for (int g = 0; g < n / k; g++) { //for every group
            for (int i = 0; i < k; i++)//for every item in the group
                b[i] = a[g * k + i];

            for (int j = 0; j < b.size() - 1; j++) //change the order in group
                swap(b[j], b[j + 1]);
            
            for (int i = 0; i < k; i++) // replace in the original vect
                a[g * k + i] = b[i];
        }

        if (n % k != 0) {
            for (int j = 0; j < n % k; j++) //for every left item in the A vect
                c[j] = a[k * (n / k) + j];

            for (int i = 0; i < n % k - 1; i++) //change the order in C
                swap(c[i], c[i + 1]);

            for (int i = 0; i < c.size(); i++) // replace in the original vect
                a[(n / k) * k + i] = c[i];
        }

            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
    return 0;
}