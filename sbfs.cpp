#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<vector<int>> g;
vector<bool> v;
vector<int> p;
list<int> path;

void edge(int a, int b) { g[a].pb(b); }

void bfs(int u) {
  queue<int> q;
  q.push(u);
  v[u] = true;
  while (!q.empty()) {
    int f = q.front();
    q.pop();
    cout << f << " ";
    // enqueue all adjascent of f and mak them visited
    for (auto i = g[f].begin(); i != g[f].end(); i++)
      if (!v[*i]) {
        q.push(*i);
        v[*i] = true;
        p[*i]= *i;
      }
  }
}
void reconstruct(int s,int e){
  list<int> path;
  for(int at=e; at!=-1; at=p[at])
    path.push_back(at);
  path.reverse();
  if(path.front() == s)
    return;
}
int main() {
  ifstream fin;
  fin.open("input.txt", ios::in);

  int a, b;
  int n, e;
  fin >> n >> e;
  cout << n << " " << e << endl;
  g.assign(n, vector<int>());
  v.assign(n, false);
  p.assign(n, -1);
  for (int i=0;i<e;i++) {
  fin >> a >> b;
    cout << a << " " << b << endl;
    edge(a, b);
    cout << a << " " << b << endl;
  }

//solution
  bfs(i);
  return 0;
}
