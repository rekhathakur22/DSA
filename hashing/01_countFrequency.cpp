// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//   int n;
//   cout << "enter number of elements in arr" << endl;
//   cin >> n;

//   int arr[n];
//   for (int i = 0; i < n; i++)
//   {
//     cin >> arr[i];
//   }

//   int max = *max_element(arr, arr + n);
//   int x = max + 1;
//   int hash[x] = {0};
//   for (int i = 0; i < n; i++)
//   {
//     hash[arr[i]] = hash[arr[i]] + 1;
//   }

//   for (int i = 0; i < x; i++)
//   {

//     cout << hash[i] << " ";
//   }

//   for (int i = 0; i < n; i++)
//   {
//     arr[i] = hash[arr[i]];
//   }
//   cout << endl;
//   int q;
//   cout << "enter the number of queries" << endl;

//   cin >> q;

//   while (q--)
//   {
//     int num;
//     cout << "enter the number" << endl;
//     cin >> num;
//     cout << hash[num] << " ";
//   }

//   return 0;
// }
