#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if(!(cin >> n >> m)){
        return 0;
    }
    vector<pair<int,int>> edges;
    edges.reserve(m);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        if(u<1||u>n||v<1||v>n) continue;
        if(u==v) continue; // ignore self-loops
        edges.emplace_back(u,v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Recompute m as edges.size() to account for ignored inputs if any
    m = (int)edges.size();

    const int LOG = 20;
    vector<int> parent(n+1, 0), depth(n+1, 0);
    vector<vector<int>> children(n+1);
    vector<int> comp_root(n+1, 0);

    vector<char> vis(n+1, 0);
    queue<int> q;
    for(int r=1;r<=n;r++){
        if(vis[r]) continue;
        vis[r]=1;
        parent[r]=0;
        depth[r]=0;
        comp_root[r]=r;
        q.push(r);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int v: adj[u]){
                if(!vis[v]){
                    vis[v]=1;
                    parent[v]=u;
                    depth[v]=depth[u]+1;
                    children[u].push_back(v);
                    comp_root[v]=r;
                    q.push(v);
                }
            }
        }
    }

    // Prepare LCA structures
    vector<array<int, LOG>> up(n+1);
    for(int i=1;i<=n;i++){
        up[i].fill(0);
        up[i][0] = parent[i];
    }
    for(int j=1;j<LOG;j++){
        for(int i=1;i<=n;i++){
            int mid = up[i][j-1];
            up[i][j] = mid ? up[mid][j-1] : 0;
        }
    }

    // Compute tin/tout using iterative DFS over the children forest
    vector<int> tin(n+1, 0), tout(n+1, 0);
    int timer = 0;
    for(int r=1;r<=n;r++){
        if(parent[r]!=0) continue; // root of its tree (has parent 0)
        // iterative DFS stack: pair(node, next_child_index)
        vector<pair<int,int>> st;
        st.emplace_back(r, 0);
        while(!st.empty()){
            int u = st.back().first;
            int &idx = st.back().second;
            if(idx == 0){
                tin[u] = ++timer;
            }
            if(idx < (int)children[u].size()){
                int v = children[u][idx++];
                st.emplace_back(v, 0);
            }else{
                tout[u] = ++timer;
                st.pop_back();
            }
        }
    }

    auto is_ancestor = [&](int u, int v)->bool{ // is u ancestor of v
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    };

    function<int(int,int)> lca = [&](int u, int v){
        if(comp_root[u] != comp_root[v]) return 0; // different components
        if(is_ancestor(u,v)) return u;
        if(is_ancestor(v,u)) return v;
        for(int j=LOG-1;j>=0;j--){
            int pu = up[u][j];
            if(pu && !is_ancestor(pu, v)) u = pu;
        }
        return parent[u];
    };

    vector<long long> add(n+1, 0);

    // Process non-tree edges
    // Build a set to quickly recognize tree edges? We'll check parent relationships only.
    for(auto &e: edges){
        int u=e.first, v=e.second;
        if(parent[u]==v || parent[v]==u) continue; // tree edge
        if((depth[u]&1) == (depth[v]&1)){
            int w = lca(u,v);
            if(w==0){
                // Should not happen for edges within same component, but guard anyway
                continue;
            }
            add[u] += 1;
            add[v] += 1;
            add[w] -= 1;
            if(parent[w]!=0){
                add[parent[w]] -= 1;
            }
        }
    }

    // Post-order accumulate add over the forest using iterative DFS
    vector<int> order;
    order.reserve(n);
    // We'll simulate postorder: push (u, state)
    vector<pair<int,int>> st;
    for(int r=1;r<=n;r++){
        if(parent[r]!=0) continue; // roots (parent 0)
        st.clear();
        st.emplace_back(r, 0);
        while(!st.empty()){
            auto [u, state] = st.back(); st.pop_back();
            if(state == 0){
                st.emplace_back(u, 1);
                for(int v: children[u]){
                    st.emplace_back(v, 0);
                }
            }else{
                // accumulate from children
                for(int v: children[u]){
                    add[u] += add[v];
                }
            }
        }
    }

    long long invitible = 0; // can be invited
    for(int i=1;i<=n;i++){
        if(add[i] > 0) invitible++;
    }
    long long ans = n - invitible;
    cout << ans << "\n";
    return 0;
}
