class Solution {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        
    int d12=distance(p1,p2),d13=distance(p1,p3),d23=distance(p2,p3);
        if(d12==0 || d13==0 || d23==0)
    		return false;
    	if(d12==d23) {
    		return sides(p2,p1,p3,p4);
    	}
    	if(d12==d13) {
    		return sides(p1,p2,p3,p4);
    	}
    	if(d13==d23) {
    		return sides(p3,p2,p1,p4);
    	}
    	return false;
    }
	private boolean sides (int[] p1, int[] p2, int[] p3, int[] p4) {
		if((p1[0]-p2[0])*(p1[0]-p3[0])+(p1[1]-p2[1])*(p1[1]-p3[1])==0){
			return p4[0]==p2[0]+p3[0]-p1[0] && p4[1]==p2[1]+p3[1]-p1[1];
		}else {
			return false;
		}
	}
	private int distance(int[] p, int[] q) {
		int x=p[0]-q[0];
		int y=p[1]-q[1];
		return x*x+y*y;
	}
}