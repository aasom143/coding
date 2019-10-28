void dfs(int v, int p){
  color[v] = 1; // GREY
  for(int w : g[v]){
    if(color[w] == 1){
      // you found a cycle, it's easy to recover it now.
    }
    if(color[w] == 0) dfs(w, v);
  }
  color[v] = 2; // BLACK
}
// And then just call it from any white node.

for(int i = 0; i < n; i++)
  if(color[i] == 0) dfs(i, -1); // IF NODE IS WHITE, START NEW DFS
