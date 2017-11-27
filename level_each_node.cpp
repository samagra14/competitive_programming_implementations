int level[10];
bool vis[10];

void bfs(int s){
    queue <int> q;
    q.push(s);
    level[s] =0;
    vis[s] = true;
    while(!q.empty()){
        int visiting = q.back();
        q.pop();
        for(int i =0;i<v[visiting].size();i++){
            if (!vis[v[visiting][i]]){
                level[v[visiting][i]] = level[visiting]+1;
                q.push(v[visiting][i]);
                vis[v[visiting][i]] = true;
            }
        }
    }
}

int main() {


    return 0;
}
