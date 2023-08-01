//{ Driver Code Starts
// Initial Template for Java
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int V = Integer.parseInt(s[0]);
            int E = Integer.parseInt(s[1]);
            ArrayList<ArrayList<Integer>> adj =
                new ArrayList<ArrayList<Integer>>();
            for (int i = 0; i < V; i++) adj.add(new ArrayList<Integer>());
            for (int i = 0; i < E; i++) {
                String[] S = br.readLine().trim().split(" ");
                int u = Integer.parseInt(S[0]);
                int v = Integer.parseInt(S[1]);
                adj.get(u).add(v);
                adj.get(v).add(u);
            }
            Solution obj = new Solution();
            ArrayList<Integer> ans = obj.dfsOfGraph(V, adj);
            for (int i = 0; i < ans.size(); i++)
                System.out.print(ans.get(i) + " ");
            System.out.println();
        }
    }
}

// } Driver Code Ends


class Solution {
    // Function to return a list containing the DFS traversal of the graph.
    public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
     boolean vis[] = new boolean[V+1];
        ArrayList<Integer> list = new ArrayList<>();
        
        dfs(0, vis, adj, list);
        return list;
        
    }
    
    //our dfs function


    public static void dfs(int curr, boolean vis[], ArrayList<ArrayList<Integer>>adj,
    ArrayList<Integer>list){
        
        //make your curr true and add in list


        vis[curr] = true;
        list.add(curr);
        
        //traverse to check its neighbors if neighbors are not visited then call for neighbors
            
            // for(int i=0; i<adj.get(curr).size(); i++){// to traverse use this loop or
            //     int neighbor = adj.get(curr).get(i);
                
            //     if(!vis[neighbor]){
            //         dfs(neighbor, vis,adj,list);
            //     }
            
        // }
        
            for(Integer it:adj.get(curr)){// or use this for each loop
                if(!vis[it]){
                    dfs(it,vis,adj,list);
                }
            }
    }
}

