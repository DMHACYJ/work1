#include <vector>
#include <cstdio>
using namespace std;
inline int read()
{
    int x = 0, f = 0;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar()) if (c == '-') f = 1;
    for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c ^ '0');
    return f ? -x : x;
}

const int N = 5e5 + 7;

int n, m, u, v, s;
int tot = 0, st[N], to[N << 1], nx[N << 1], fa[N], ans[N], vis[N];
struct note { int node, id; }; //ѯ���Խṹ����ʽ����
vector<note> ques[N];

inline void add(int u, int v) { to[++tot] = v, nx[tot] = st[u], st[u] = tot; }
inline int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); } //���鼯��getfa������·��ѹ��

void dfs(int u, int from)
{
    for (int i = st[u]; i; i = nx[i]) if (to[i] != from) dfs(to[i], u), fa[to[i]] = u; //��u�Ķ��Ӻϲ���u
    int len = ques[u].size(); //������u�йص�ѯ��
    for (int i = 0; i < len; i++) if (vis[ques[u][i].node]) ans[ques[u][i].id] = getfa(ques[u][i].node); //��Ӧ��v�Ѿ����ʲ�����ʱ��LCA(u,v)����v��fa�������С��һ��Ҳ����getfa(v)
    vis[u] = 1; //������ϻ���
}

int main()
{
    n = read(), m = read(), s = read();
    for (int i = 1; i < n; i++) u = read(), v = read(), add(u, v), add(v, u);
    for (int i = 1; i <= m; i++) u = read(), v = read(), ques[u].push_back((note){v, i}), ques[v].push_back((note){u, i}); //����ѯ�ʱ�ű������
    for (int i = 1; i <= n; i++) fa[i] = i;
    dfs(s, 0);
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]); //�����
    return 0;
}
