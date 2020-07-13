/*
Топологическая сортировка (англ. topological sort) ориентированного ациклического графа G=(V,E)
представляет собой упорядочивание вершин таким образом, что для любого ребра (u,v) ∈ E(G)
номер вершины u меньше номера вершины v.

Для полной информации: http://neerc.ifmo.ru/wiki/index.php?title=Использование_обхода_в_глубину_для_топологической_сортировки

Важные сведение:
    Алгоритм dfs не может самостоятельно служить как topSort, ибо в примере:
        Граф:
            0 ->
            1 ->
            2 -> 3
            3 -> 1
            4 -> 0,1
            5 -> 0,2
        Ответ алгоритма dfs будет: 5 2 3 1 0 4, мы можем видеть что этот ответ для topSort не годится.
        Потому что, 4 должен стоять перед 0: 5 -> 2 -> 3 -> 1 0 <- 4.
    Из этого можем заметить, что при ответе topSort, если мы обозначим через стрелки соседние вершины рассматриваемой 
    вершины, то они строго должны смотреть в правую сторону.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> g[10];
bool used[10];
vector<int> ans;

void dfs(int v)
{
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
    ans.push_back(v);
}

void topSort()
{
    for (size_t i = 0; i < n; ++i)
        used[i] = false;
    ans.clear();

    for (size_t i = 0; i < n; ++i)
    {
        if (!used[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int main()
{

    return 0;
}