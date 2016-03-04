#include <bits/stdc++.h>
using namespace std;
	
#define mp make_pair
#define ff first
#define sf second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define r_all(x) (x).rbegin(), (x).rend()
#define fast_cin_cout(arg) ios::sync_with_stdio(!arg)
	
template<typename T> 
void printelem(T & container) {for(auto & elem: container) cout << elem << endl; }
template<typename T> 
void LOG(T const& t) { std::cout << t; }
template<typename First, typename ... Rest> 
void LOG(First const& first, Rest const& ... rest) { std::cout << first<<" "; LOG(rest ...);}
	
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

	
// partition function call :: linear BIG_O(n) time complexity
	
int partition(int a[],int x,int y) {
	int pivot_val = a[x];
	int i=x;
	for(int j=i+1;j<=y;j++) {
		if(a[j] <= pivot_val) {
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i],a[x]);
	return i;
}

void quick_sort(int a[],int x,int y) {
	/*test if the problem is small*/
/*	if(x == y)
		return a[x];*/
	/*big problem divide and conquer*/
		if(y>x) {
			int pivot_idx = partition(a,x,y);
			quick_sort(a,x,pivot_idx-1);
			quick_sort(a,pivot_idx+1,y);
		}
}
	
	
int main() {
	int a[10] = {7,6,5,1,211,0,8,9,3,2};
	quick_sort(a,0,9);
	for(int i=0;i<10;i++) {
		LOG(a[i]," ");
	}

}
