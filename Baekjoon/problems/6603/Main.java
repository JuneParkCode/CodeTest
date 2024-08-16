import java.util.*;
import java.io.*;
import java.lang.*;

public class Main {
	static FastReader scan = new FastReader();
    
    // 정답은 sb에 append 를 사용해 출력
    // 만약 개행까지 출력하고 싶으면 append('\n')를 추가
    static StringBuilder sb = new StringBuilder();
    
    public static void main(String[] args) {
    	input();
    }
    
    static void input() {
    
    }
    
    static class FastReader {
    	BufferedReader br;
        StringTokenizer st;
        
        public FastReader() {
        	br = new BufferedReader(new InputStreamReader(System.in));
        }
        
        public FastReader(String s) throws FileNotFoundException {
        	br = new BufferedReader(new FileReader(new File(s)));
        }
        
        String next() {
        	while (st == null || !st.hasMoreElements()) {
            	try {
                	st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                	e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        
        int nextInt() {
        	return Integer.parseInt(next());
        }
        
        long nextLong() {
        	return Long.parseLong(next());
        }
        
        double nextDouble() {
        	return Double.parseDouble(next());
        }
        
        String nextLine() {
        	String str = "";
            try {
            	str = br.readLine();
            } catch (IOException e) {
            	e.printStackTrace();
            }
            
            return str;
        }
    
    }

}
