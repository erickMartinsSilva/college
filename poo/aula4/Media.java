public class Media {
    public static void main(String[] args) {
        int u[] = {3, 2, 4, 5, 6, 1};
        int sum = 0;
        for(int i = 0; i < u.length; i++) {
            sum += u[i];
        }
        System.out.println((double) sum/u.length);
    }
}