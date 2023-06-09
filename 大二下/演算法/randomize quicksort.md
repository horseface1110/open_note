### 證明[[quick sort]] 、[[randomize quicksort]]的最糟狀況$O(n^2)$
* 基本式子：$T(n)=max(T(q)+T(n-q-1))+\theta(n)$
* 因為Partion會切割陣列成兩個，所以q的範圍從0到n-1
* 用替換法計算時間複雜度，令T(n) < $cn^2$
> $T(n) <= max(cq^2 + c(n - q - 1)^2 ) + \theta(n)$
> $= c * max(q^2+(n - q - 1)^2) + \theta(n)$
 * 要求max時，出現在q = 0 或 n - 1，所以max < $(n - 1 )^2$  
 * 所以，$T(n) <= cn^2$
 * **也可以用遞迴解法得出解是$\Omega(n^2)$** ，所以時間複雜度是$\theta(n^2)$
### 證明[[randomize quicksort]]的平均狀況
 * 因為Partition一次去掉一個元素，所以Partition最多呼叫n次
 * 再加上for迴圈執行的次數，所以是$O(n + X)$
 * ============================================
 * 先算出兩個元素會比較到的機率
 > 令$Z_{ij}$ 代表陣列中 第i大 到 第j大 的元素
 > $X_{ij}$ 代表元素$Z_i$跟$Z_j$比較的機率
 > 則所有元素會比較到的次數為$C(n,2)$  <- 大概吧，下圖
 ![[Screenshot_20230416_234345.jpg]]
 > 然後：元素$Z_i$$Z_j$比較的機率為$\frac{2}{j - i + 1}$
 >> 因為兩者要比較到一定要有一個是pivot，要成為pivot的機率是$\frac{1}{j - i + 1}啊有兩個要比所以機率是兩倍$
 >> 
 > 接下來計算X的期望值(我不知道甚麼是X)，![[Screenshot_20230416_234952.jpg]]
 > 所以就是$O(nlgn)$