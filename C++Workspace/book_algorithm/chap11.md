# 「アルゴリズムとデータ構造」　第11章章末問題　解答
## 11.1
https://atcoder.jp/contests/abc075/tasks/abc075_c
各辺ごとに、他の辺について頂点をunion-findした後に、最後にその辺の両端が同じグループに属しているかどうかを調べれば良い。
計算量はunion-findの初期化$O(V)$を考えると$O(|V||E|+|E|^2\alpha(|V|))$かな？（本と違う…）
ちなみに幅優先探索や深さ優先探索などで連結判定をするとO(|E|(|E|+|V|))らしい。

## 11.2
https://atcoder.jp/contests/abc120/tasks/abc120_d
橋を破壊していくのではなく、逆から橋を再生していけば良い。
頂点のunion-findを持っておき、辺を製造するごとにその辺によって改善した不便さを返せば良い。ただし、辺を製造してももともと両端が同じ連結成分に属しているときは、不便さは改善しない。
https://atcoder.jp/contests/abc120/submissions/16181856

## 11.3
https://atcoder.jp/contests/abc049/tasks/arc065_b
道路、鉄道それぞれについてunion-findを行いparentを求めておく。($O((K+L)\alpha(N))$)
この時同じ連結成分の頂点vの`parent[v]`は同じになるようにする。
あとは各iについて、(道路のparent,鉄道のparent)の同じ組が何個出てくるかをソートされた配列を二分探索するなどによって求める。($O(N \log N)$)
## 11.4
https://atcoder.jp/contests/arc090/tasks/arc090_b
重みつきunion-find木を使う。（union-find木に親ノードとの差分を持たせる）
union-findでもともと連結成分でないときは連結すれば良い。連結成分であるときは、重みが一致しているかどうかを確かめる。
あとでコードも載せます…