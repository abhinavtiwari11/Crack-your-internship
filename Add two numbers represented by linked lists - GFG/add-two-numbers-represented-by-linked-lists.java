//{ Driver Code Starts
// driver

import java.util.*;

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class GfG{
    
    static void printList(Node n){
        while(n!=null){
            System.out.print(n.data+" ");
            n = n.next;
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        while (T-- > 0) {
            
            int n = sc.nextInt();
            int val = sc.nextInt();
            
            Node first = new Node(val);
            Node tail = first;
            for(int i=0; i<n-1; i++)
            {
                val = sc.nextInt();
                tail.next = new Node(val);
                tail = tail.next;
            }
            
            int m = sc.nextInt();
            val = sc.nextInt();
            
            Node second = new Node(val);
            tail = second;
            for(int i=0; i<m-1; i++)
            {
                val = sc.nextInt();
                tail.next = new Node(val);
                tail = tail.next;
            }
            
            Solution g = new Solution();
            Node res = g.addTwoLists(first, second);
            printList(res);
        }
    }
}

// } Driver Code Ends


/* node for linked list

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

*/

class Solution{
    //Function to add two numbers represented by linked list.
    static Node addTwoLists(Node first, Node second){
        // code here
        // return head of sum list
     Node firstt = reverse(first);
        Node secondd = reverse(second);
        
        
        Node dummy = new Node(0);
        Node tail = dummy;
        
        int carry = 0;
        
        while(firstt != null || secondd != null){
            int a = (firstt != null) ? firstt.data : 0;
            int b = (secondd != null) ? secondd.data : 0;
            
            int sum = carry + a + b;
            carry = sum / 10;
            
            tail.next = new Node(sum%10);
            tail = tail.next;
            
            if(firstt != null) firstt = firstt.next;
            if(secondd != null) secondd = secondd.next;
            
        }
        
        if(carry > 0)
            tail.next = new Node(carry);
            
        Node res = reverse(dummy.next);
        
        return res;
    }
    
    public static Node reverse(Node first){
        Node curr = first;
        Node prev = null;
        Node frwd = null;
        
        while(curr != null){
            frwd = curr.next;
            curr.next = prev;
            prev = curr;
            curr = frwd;
        }
        
        return prev;
    }
}
 

