#include <bits/stdc++.h>
using namespace std;
 
const int N = 100, M = 33000;
int v[N][3], c[N][3], f[M];
int n, m, cnt;
 
 
int main(){
    while(scanf("%d%d", &m, &n) == 2){
        memset(v, 0, sizeof(v[0]) * (n + 5));
        memset(c, 0, sizeof(c[0]) * (n + 5));
        memset(f, 0, sizeof(f[0]) * (m + 5));
        for(int i = 1; i <= n; ++i){
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            if(z == 0) v[i][2] = x * y, c[i][2] = x;
            else for(int j = 0; j <= 1; ++j) if(v[z][j] == 0) {
                v[z][j] = x * y;
                c[z][j] = x;
                break;
            }
        }
        for(int i = 1; i <= n; ++i){
            for(int k = m; k >= 0; --k){
                for(int s = 0; s < 4; ++s){
                    int val = v[i][2], cst = c[i][2];
                    for(int j = 0; j <= 1; ++j){
                        if(s & (1 << j)) val += v[i][j], cst += c[i][j];
                    }
                    if(cst <= k) f[k] = max(f[k], f[k - cst] + val);
                }               
            }
        }
        printf("%d\n", f[m]);
    }
    return 0;
}

//java
import java.util.Scanner;
 
//加了限制条件的背包问题
public class Main {
    public static int getMaxValue(int[] val, int[] weight, int[] q, int n, int w) {
        int[][] dp = new int[n + 1][w + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= w; j++) {
                if (q[i-1] == 0) {  // 主件
                    if (weight[i - 1] <= j) // 用j这么多钱去买 i 件商品 可以获得最大价值
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j- weight[i - 1]]+ val[i - 1]);
                }
                else { //附件
                    if (weight[i - 1] + weight[q[i - 1]] <= j) //附件的话 加上主件一起算
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j- weight[i - 1]]+ val[i - 1]);
                }
            }
        }
        return dp[n][w];
    }
 
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextInt()) {
            int n = input.nextInt(); // 总钱数
            int m = input.nextInt(); // 商品个数
            int[] p = new int[m];
            int[] v = new int[m];
            int[] q = new int[m];
            for (int i = 0; i < m; i++) {
                p[i] = input.nextInt();        // 价格
                v[i] = input.nextInt() * p[i]; // 价值
                q[i] = input.nextInt();        // 主or附件
            }
            System.out.println(getMaxValue(v, p, q, m, n));
        }
    }
}