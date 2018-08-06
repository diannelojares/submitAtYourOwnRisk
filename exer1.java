// Java program to print DFS traversal from a given Graph

import java.io.*;
import java.util.*;
 
// This class represents a directed Dfs using adjacency list representation
class exer1 {

    private int V;   // No. of vertices
 
    // Array  of lists for Adjacency List Representation
    private static LinkedList<Integer> adj[];
    private static ArrayList map;
    
    // Constructor of the class
    Dfs(int v) {

        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i) {
            adj[i] = new LinkedList();
        }
    }
 
    //Function to add an edge into the Graph
    void addEdge(int v, int w) {
        adj[v].add(w);  // Add w to v's list.
    }
 
    // A function used by DFS
    void DFSUtil(int v, int goal, boolean visited[]) {
        // Mark the current node as visited and print it
        visited[v] = true;
        System.out.print( map.get(v) + " ");
 
        // Recur for all the vertexices adjacent to this vertex
        Iterator<Integer> i = adj[v].listIterator();
        while (i.hasNext()) {
            int n = i.next();
            // if ( !visited[n] ) {
            //     DFSUtil(n, visited);
            // }
            if ( !visited[n] && n == goal) {
                visited[n] = true;
                System.out.print( map.get(goal) + " ");
                // DFSUtil2(n, visited);
                break;
            }else if ( !visited[n] ){
                //int goal2 = goal;
                DFSUtil(n, goal, visited);
                break;
            }
        }
        return;
    }
    // void DFSUtil2(int v, boolean visited[]) {
    //     // Mark the current node as visited and print it
    //     visited[v] = true;
    //     System.out.print( v + " ");
    // }
 
    // The function to do DFS traversal. It uses recursive DFSUtil()
    void DFS(int v, int goaal) {
        // Mark all the vertices as not visited(set as false by default in java)
        boolean visited[] = new boolean[V];
 
        // Call the recursive helper function to print DFS traversal
        DFSUtil(v, goaal, visited);
    }
 
    public static void main(String args[])throws IOException {
        Scanner inp = new Scanner(new File("exer1.in"));
        while(inp.hasNextInt()){
            int numberOfCities = inp.nextInt();
            Dfs g = new Dfs(numberOfCities);
            map = new ArrayList<String>();

            for(int x = 0; x<numberOfCities; x++){
                map.add(inp.next());
            }

            for(int y = 0; y<numberOfCities; y++){
                int neighbors = inp.nextInt();

                for (int z = 0; z<neighbors; z++) {
                    g.addEdge(y, map.indexOf(inp.next()));
                }
            }
            //String destination = inp.next();
            int start = map.indexOf(inp.next());
            int end = map.indexOf(inp.next());

            g.DFS(start, end);
            //System.out.println("Original contents of ll: " + adj[0]);
            System.out.println();            
        }
    }
}
