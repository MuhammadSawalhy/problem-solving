#include <iostream>
using namespace std;

typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  unsigned long t, x, y;

  cin >> t;

  while (t--) {
    cin >> x;
    y = 1;

    for (int i = 0; i < 32; i++) { // test 32 bits
      if ((y & x) > 0 && (x ^ y) > 0)
        break;
      y <<= 1;
      if ((y & x) > 0 && (x ^ y) > 0)
        break;
      y += 1;
      if ((y & x) > 0 && (x ^ y) > 0)
        break;
      y -= 1;
    }

    std::cout << y << std::endl;
  }

  return 0;
}


