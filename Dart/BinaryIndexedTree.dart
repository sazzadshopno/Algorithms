import 'dart:math';

const int mx = 6;

List<int> arr = List.filled(mx, 0), tree = List.filled(mx, 0);
void update(int idx, int val, int n) {
  while (idx <= n) {
    tree[idx] += val;
    idx += (idx & -idx);
  }
}

int query(int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

int main() {
  int n = 5;
  for (int i = 1; i <= n; i++) {
    arr[i] = Random().nextInt(150);
    update(i, arr[i], n);
  }
  print(arr);
  int p = 5, q = 3;
  print(query(p) - query(q - 1));
  return 0;
}
