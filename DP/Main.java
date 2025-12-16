import java.util.Scanner;
public class Main {
    public static void main(String[] arg){
	int mod = (int) 1e9+7;
        Scanner s = new Scanner (System.in);
        int n;
        n = s.nextInt();
	int x;
        x = s.nextInt();

        int coins[] = new int[n];
        for (int i=0;i<n;i++){
            coins[i] = s.nextInt();
        }
        
        int dp[] = new int[x+1];
        for (int i=0;i<=x;i++){
            dp[i] = 0;
        }
        dp[0] = 1;
        for(int i=1;i<=x;i++){
            for(int coin : coins){
                if (i-coin >= 0){
                    dp[i] = (dp[i] + dp[i-coin])%mod;
                }
            }
        }
        System.out.println(dp[x]%mod);
    }
}