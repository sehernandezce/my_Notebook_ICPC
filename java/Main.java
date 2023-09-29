import java.util.*;
import java.io.*;

public class Main{
    static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br=new BufferedReader(new InputStreamReader(System.in));
        }
        public FastReader(String nameIn){
            FileReader archive;
            try {
                archive = new FileReader(nameIn);
                br=new BufferedReader(archive);
            } catch (FileNotFoundException e) {
                this.br= null;
                e.printStackTrace();
            }
        }
        String next(){
            while(st==null || !st.hasMoreTokens()){
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt(){
            return Integer.parseInt(next());
        }
        long nextLong(){
            return Long.parseLong(next());
        }
        double nextDouble(){
            return Double.parseDouble(next());
        }
        String nextLine(){
            String str="";
            try {
                str=br.readLine().trim();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    static class FastWriter {
		private BufferedWriter bw;

		public FastWriter() {
			this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
		}

        public FastWriter(String nameOut) {
            FileWriter archive;
            try {
                archive = new FileWriter(nameOut);
                this.bw=new BufferedWriter(archive);
            } catch (IOException e) {
                e.printStackTrace();
                this.bw= null;
            }
        }

		public void print(Object object) throws IOException {
			bw.append("" + object);
		}

		public void println(Object object) throws IOException {
			print(object);
			bw.append("\n");
		}

		public void close() throws IOException {
			bw.close();
		}
	}

    public static void sort(int[] arr)
    {
        //Collections.sort() uses merge sort
        ArrayList<Integer> ls = new ArrayList<Integer>();
        for(int x: arr)
            ls.add(x);
        Collections.sort(ls);
        for(int i=0; i < arr.length; i++)
            arr[i] = ls.get(i);
    }
    public static void main(String[] args) {
        try {
            FastReader in=new FastReader("./input.txt");
            // FastWriter out = new FastWriter("./output.txt");
            // FastReader in=new FastReader();
            FastWriter out = new FastWriter();
            
            // Code Here
            
            out.close();
        } catch (Exception e) {
            return;
        }
    }
}