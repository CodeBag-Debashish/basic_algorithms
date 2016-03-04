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


	/*zero based index program :: let's say [0,1,2...9] are the indices then 
	left part [0,1,2..4] 
	and right part [5,6,7,..9]
	where mid = (0+9)>>1 = 4.5 = 4*/

int merge(int a[],int b[],int x,int y,int m) {
	int i,j,k,inv_cnt=0;

	/*[1st , 2nd , 3rd ,..., mid , mid+1 , mid+2 , .... , nth]*/
	/*left half and right half sorted*/
	
	i = x; j = m+1; k = x;

	while( (i<=m) && (j<=y) ) {
		if(a[i] <= a[j]) { 											// if a[i] is small (left half member)
			b[k++] = a[i++]; 											// ok to copy a left half member
		}else { 																// if a[j] is small (right half member)
			b[k++] = a[j++]; 											// ok to copy a right half member
			inv_cnt += (m-i+1); 									// just plus-minus :)
		}
	}
	while(i<=m) b[k++] = a[i++]; 							// if remains
	while(j<=y) b[k++] = a[j++]; 							// if remains
	for(i=x;i<=y;i++) a[i] = b[i]; 						// copy back
	return inv_cnt;
}

int merge_sort(int a[],int b[],int x,int y) {
	int mid,inv_cnt = 0;
	if(x == y) {															// small problem
		return 0;				
	}else if(y > x){
		mid = (x+y)>>1;
		inv_cnt = merge_sort(a,b,x,mid);				// conquer left half
		inv_cnt += merge_sort(a,b,mid+1,y);			// conquer right half
		inv_cnt += merge(a,b,x,y,mid);					// so now both the halves are sorted its time to merge them
	}
	return inv_cnt;
}

int main() {
	fast_cin_cout(true);
	/*use input if required*/
	int a[10] = {1,2,3,4,5,4};
	int *b = new int[6]; 											// outplace !! creat one array space extra
	cout << merge_sort(a,b,0,5) << endl;
	delete b;
	return 0;
}
