//code by @tusharkhanna
#include<bits/stdc++.h>
using namespace std;

//brute
void sort012(vector<int> &a) {
    sort(a.begin(), a.end());
}

//optimal -> dutch national flag algorithm
void sort_012(vector<int> &a) {
    int low = 0, mid = 0, high = a.size()-1;
    while(mid <= high) {
        if(a[mid] == 0) {
            swap(a[low++], a[mid++]);
        }
        else if(a[mid] == 1) {
            mid++;
        }
        else {
            swap(a[mid], a[high--]);
        }
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    cout<<"Given array : ";
    for(int i: a) {
        cout<<i<<" ";
    }
    sort_012(a); // O(n)
    sort012(a); //O(n*logn)
    cout<<endl<<"Sorted array : ";
    for(int i: a) {
        cout<<i<<" ";
    }
    return 0;
}
