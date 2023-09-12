#include <iostream>
using namespace std;

string TAM[3][11];
string Back(string W){
  W = W.substr(1);
  for(int j = W.size(); !W.empty(); W = W.substr(1)) {
     if(TAM[0][j--] == W) return W;
  }
  return "eps";
}

int check(string W_t, string W_a) {
  string state;
  for(string::iterator it = W_t.begin(); it != W_t.end(); ++it) {
    switch(*it) {
      case 'a':
        state = TAM[1][state.size()];
        break;
      case 'b':
        state = TAM[2][state.size()];
        break;
      default:
        break;
    }
    if(state == "eps") {
      state.clear();
    }
    if(state == W_a) {
      return 1;
    }
  }
  return 0;
}

int main(){
  string W, W_t, now = "";
  int test, i = 0;
  cin >> W;
  TAM[0][0] = "";
  for(i = W.size(); i > 0; i--) {
    TAM[0][i] = W.substr(0, i);
  }
  TAM[0][0] = "eps";  
  for(; i < W.size(); i++){
    switch(W[i]){
      case 'a':
        TAM[1][i] = TAM[0][i+1];
        TAM[2][i] = Back(now+"b");
        break;
      case 'b':
        TAM[2][i] = TAM[0][i+1];
        TAM[1][i] = Back(now+"a");
        break;
      default:
        break;
    }
    now += W[i];
    cout << TAM[0][i] << " " << TAM[1][i] << " " << TAM[2][i] << endl;
  }
  TAM[1][i] = W;
  TAM[2][i] = W;
  cout << TAM[0][i] << " " << TAM[1][i] << " " << TAM[2][i] << endl;
  cin >> test;
  for(int i = 0; i < test; i++){
    cin >> W_t;
    cout << check(W_t, W) << endl;
  }
}