#include <iostream>
using namespace std;

int main() {
int N;
cin >> N;

int W[1000], X[1000];

for(int i=0; i<N; i++) {
cin >> W[i] >> X[i];
}

int maxEmployees = 0;

for(int meetingHour=0; meetingHour<24; meetingHour++) {

int employees = 0;

for(int i=0; i<N; i++) {
  // 拠点iの現地時刻
  int localHour = (meetingHour + X[i]) % 24; 
  
  if(localHour >= 9 && localHour < 18) {
    employees += W[i]; 
  }
}

maxEmployees = max(maxEmployees, employees);
}

cout << maxEmployees << endl;

return 0;
}